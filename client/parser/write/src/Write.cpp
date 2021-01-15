#include "../include/Write.hpp"

using namespace teuton::parser;

Write::Write(std::string path, std::vector<std::string> save, std::vector<Country> _country, std::vector<Province> province, std::vector<std::string> tagList) {
    this->_localSave = save;
    this->_country = _country;
    this->_localProvince = province;
    this->tagList = tagList;
    foundTag();

    int i = 0; 
    for (; (size_t)i < path.size() & path.at(i) != '/'; i++);
    path = path.substr(i + 1, path.size()); 
    i = 0;
    for (; (size_t)i < path.size() & path.at(i) != '.'; i++);
    path = path.substr(0, i) + "NEW" + path.substr(i, path.size()); 

    path = "../" + path;
    std::cout << path << std::endl;

    std::ofstream MyFile(path);

    std::cout << "write save" << std::endl;
    for (i = 0; this->_localSave.size() > (size_t)i ; i++) {
        if ((this->_localSave.at(i).size() > 0 && this->_localSave.at(i) != " " ) || this->_localSave.at(i) == "\n" )
            MyFile << this->_localSave.at(i) + '\n';
    }
    std::cout << "save is up"<< std::endl;

    MyFile.close();
}

Write::~Write() {}

void Write::foundTag() {
    int i = 0;
    for (;(size_t)i < this->_localSave.size() && this->_localSave.at(i) != "countries={"; i++)
        if (this->_localSave.at(i).size() > (size_t)5 && this->_localSave.at(i).at(0) == '-' && this->_localSave.at(i).size() > 2 && this->_localSave.at(i).size() <= 7) 
            i = baseProvince(this->_localSave.at(i), i);
    for (;(size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t}"; i++);
    i++;
    for (;(size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t}"; i++);
    i++;
    for (;(size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t}"; i++);
    i++;
    for (;(size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t}"; i++);
    i++;
    for (;(size_t)i < this->_localSave.size() && this->_localSave.at(i) != "}"; i++) {
        if (this->_localSave.at(i).size() == 6 && this->_localSave.at(i).at(0) == '\t' && this->_localSave.at(i).at(4) == '=') {
            std::string tag = this->_localSave.at(i).substr(1, 3);
            for (int y = 0; (size_t)y < _country.size(); y++) {
                for (int c = 0; (size_t)c < tagList.size(); c++)
                    if (tag == tagList.at(c))
                        if (tag == this->_country.at(y).getTag()) {
                            std::cout << "the modify country " << tag << " work" << std::endl;
                            i = parseTag(tag, i, this->_country.at(y));
                            this->nbEstate = 0;
                            this->nbRival = 0;
                        }
            }
        }
    }
}

int Write::baseProvince(std::string province, int i) {
    Province actualProvince;
    std::string sub;
    std::vector<std::string> cuted;
    bool equal;
    bool tst = false;
    bool taxe = false;
    bool man = false;
    bool prod = false;

    sub = this->_localSave.at(i);
    cuted = cutInPart('=', sub);
    
    for (; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t}";i++) {
        for (int y = 0; (size_t)y < this->_localProvince.size() && !tst; y++)
            if (cuted.at(0) == this->_localProvince.at(y).getName()) {
                actualProvince = this->_localProvince.at(y);
                tst = true;
            }
        if ((size_t)2 < this->_localSave.at(i).size()) {
            equal = false;
            sub = this->_localSave.at(i);
            sub = sub.substr(2, sub.size());
            for (int o = 0; (size_t)o < sub.size(); o++)
                if (sub.at(o) == '=')
                    equal = true;
            if (equal) {
                cuted = cutInPart('=', sub);
                    if (cuted.at(0) == "base_tax" && !taxe) {
                        std::string str = "\t\t";
                        str += "base_tax=" + std::to_string(actualProvince.getBaseTaxe()) + ".000";
                        this->_localSave.at(i) = str;
                        taxe = true;
                    }
                    else if (cuted.at(0) == "base_production" && !prod) {
                        std::string str = "\t\t";
                        str += "base_production=" + std::to_string(actualProvince.getBaseProduction()) + ".000";
                        this->_localSave.at(i) = str;
                        prod = true;
                    }
                    else if (cuted.at(0) == "base_manpower" && !man) {
                        std::string str = "\t\t";
                        str += "base_manpower=" + std::to_string(actualProvince.getBaseManpower()) + ".000";
                        this->_localSave.at(i) = str;
                        man = true;
                    }
            }
        }
    }
    this->_localProvince.push_back(actualProvince);

    return i;
}

int Write::parseTag(std::string tag, int i, Country cnt) {
    this->_actual = cnt;
    for (; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t}";i++) {
        int equal = 0;
        std::string sub = this->_localSave.at(i);
        for (;(size_t)equal < sub.size() && sub.at(equal) != '='; equal++);
        if ((size_t)equal < sub.size()) {
            sub = sub.substr(2, equal - 2);
            while (sub.at(0) == ' ')
                sub = sub.substr(1, sub.size());
        }
        if (sub == "government_rank" || sub == "government_name" || sub == "government") {
            i = government(i, sub);
        }
        else if (sub == "estate") {
            i = estate(i);
        }
        else if (sub == "active_idea_groups") {
            i = idea(i);
        }
        else if (sub == "current_power_projection" || sub == "prestige" || sub == "stability" || sub == "devotion" || sub == "meritocracy" || sub == "legitimacy" || sub == "manpower" || sub == "innovativeness" || sub == "government_reform_progress") {
            i = stateViews(i, sub);
        }
        else if (sub == "colors") {
            i = colors(i);
        }
        else if (sub == "technology" || sub == "technology_group") {
            i = technology(i);
        }
        else if (sub == "primary_culture" || sub == "religion" || sub == "rival") {
            i = misc(i, sub);
        }
        else if (sub == "owned_provinces" || sub == "powers") {
            i = three(i);
        }
    }

    return i;
}

int Write::estate(int i) {
    std::string sub;
    std::vector<std::string> cuted;
    std::vector<std::string> toAdd;
    Estates estate;
    bool all = false;
    
    i++;
    int pr = 0;
    
    for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t}"; i++) {
        sub = this->_localSave.at(i);
        sub = sub.substr(3, sub.size());
        cuted = cutInPart('=', sub);
        if (cuted.at(0) == "type")
            estate.setType(cuted.at(1));
        if (cuted.at(0) == "loyalty")
            this->_localSave.at(i) = with(i, this->_actual.getEstates().at(nbEstate).getLoyalty(), '=');
        if (cuted.at(0) == "territory")
            this->_localSave.at(i) = with(i, this->_actual.getEstates().at(nbEstate).getTerritory(), '=');
        if (cuted.at(0) == "granted_privileges" && !all) {
            this->revoke(i + 1, 3);
            i++;
            if (this->_localSave.at(i) != "\t\t\t}" && !all) {
                for (int y = 0; (size_t)y < this->_actual.getEstates().at(nbEstate).getGrantedPrivileges().size(); y++) {
                    toAdd.push_back(" {");
                    toAdd.push_back("\t\t\t" + this->_actual.getEstates().at(nbEstate).getGrantedPrivileges().at(y) + " 1444.10.01\t\t\t\t}");
                    all = true;
                }
                i = addLine(i, toAdd, 3);
                pr++;
                for (; this->_localSave.at(i) == " "; i++);
            }
        }
    }
    nbEstate++;

    return i;
}

int Write::idea(int i) {
    std::vector<std::string> toAdd;
    i++;
    this->revoke(i + 1, 2);
    if ((size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t}") {
        for (int y = 0; (size_t)y < this->_actual.getActiveIdeaGroup().size(); y++)
            toAdd.push_back("\t\t\t" + this->_actual.getActiveIdeaGroup().at(y).getIdeaName() + "=" + std::to_string(this->_actual.getActiveIdeaGroup().at(y).getIdeaLevel()));
        i = addLine(i, toAdd, 2);
    }
    return i;
}

int Write::government(int i, std::string sub) {
    std::vector<std::string> cuted;
    std::vector<std::string> toAdd;
    cuted = cutInPart('=', this->_localSave.at(i));
    bool out = false;
    if (cuted.at(0) == "government_rank")
        this->_localSave.at(i) = "\t\tgovernment_rank=" + std::to_string(this->_actual.getGovernment().getGovernmentRank());
    if (cuted.at(0) == "government_name") {
        std::string str = "\t\tgovernment_name=";
        str += this->_actual.getGovernment().getGovernmentName();
        this->_localSave.at(i) = str;
    }
    if (cuted.at(0) == "government") {
        i++;
        for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t}"; i++) {
            sub = this->_localSave.at(i);
            sub = sub.substr(3, sub.size());
            cuted = cutInPart('=', sub);
            if (cuted.at(0) == "government") {
                std::string str = "\t\t\tgovernment=" + this->_actual.getGovernment().getGovernment();
                this->_localSave.at(i) = str;
            }
            if (cuted.at(0) == "reform_stack") {
                i++; 
                bool notAgain = false;
                for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t\t\t}" && !out; i++) {
                    if (this->_localSave.at(i) == "\t\t\t\thistory={") {
                        out = false;
                    }
                    if (this->_localSave.at(i) != "\t\t\t\thistory={") {
                        for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t\t\t}" && out != true &&  this->_localSave.at(i) != "\t\t\t\thistory={" && !notAgain; i++) {
                            sub = this->_localSave.at(i);
                            sub = sub.substr(4, sub.size());
                            if (sub == "reforms={") {
                                this->revoke(i + 1, 4);
                                i++;
                            }
                            if (sub != "reforms={") {
                                out = true;
                                for (int y = 0; (size_t)y < this->_actual.getGovernment().getReform().size(); y++) {
                                    toAdd.push_back("\t\t\t\t\t" + this->_actual.getGovernment().getReform().at(y));
                                }
                                for (; this->_localSave.at(i) != "\t\t\t\treforms={" ;i--);
                                i+=2;
                                i = addLine(i, toAdd, 4);
                                notAgain = true;
                            }
                            for (;this->_localSave.at(i) != "\t\t\t\t}";i++);
                        }
                    }
                }
            }
        }
    }

    return i;
}

int Write::stateViews(int i, std::string sub) {
    std::vector<std::string> cuted;
    cuted = cutInPart('=', this->_localSave.at(i));
    if (cuted.at(0) == "current_power_projection") 
        this->_localSave.at(i) = "\t\tcurrent_power_projection=" + std::to_string(this->_actual.getStateViews().getCurrentPowerProjection());
    if (cuted.at(0) == "prestige")
        this->_localSave.at(i) = "\t\tprestige=" + std::to_string(this->_actual.getStateViews().getPrestige());
    if (cuted.at(0) == "stability")
        this->_localSave.at(i) = "\t\tstability=" + std::to_string(this->_actual.getStateViews().getStability());
    if (cuted.at(0) == "devotion" || cuted.at(0) == "meritocracy" || cuted.at(0) == "legitimacy")
        this->_localSave.at(i) = "\t\t" + cuted.at(0) + "=" + std::to_string(this->_actual.getStateViews().getLegitimacy());
    if (cuted.at(0) == "manpower")
        this->_localSave.at(i) = "\t\tmanpower=" + std::to_string(this->_actual.getStateViews().getManpower());
    if (cuted.at(0) == "innovativeness")
        this->_localSave.at(i) = "\t\tinnovativeness=" + std::to_string(this->_actual.getStateViews().getInnovativeness());
    if (cuted.at(0) == "government_reform_progress") {
        this->_localSave.at(i) = "\t\tgovernment_reform_progress=" + std::to_string(this->_actual.getStateViews().getRefromProgress());
    }

    return i;
}

int Write::colors(int i) {
    std::string sub;
    std::vector<std::string> cuted;
    for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t}"; i++) {
        sub = this->_localSave.at(i);
        sub = sub.substr(3, sub.size());
        cuted = cutInPart('=', sub);
        std::vector<int> color;
        if (cuted.at(0) == "revolutionary_colors") {
            i++;
            std::string str = "\t\t\t\t" + std::to_string(this->_actual.getColors().getRevolutionaryColors().at(0)) + ' ' + std::to_string(this->_actual.getColors().getRevolutionaryColors().at(1)) + ' ' + std::to_string(this->_actual.getColors().getRevolutionaryColors().at(2));
            this->_localSave.at(i) = str;
        }
        if (cuted.at(0) == "map_color") {
            i++;
            std::string str = "\t\t\t\t" + std::to_string(this->_actual.getColors().getMapColors().at(0)) + ' ' + std::to_string(this->_actual.getColors().getMapColors().at(1)) + ' ' + std::to_string(this->_actual.getColors().getMapColors().at(2));
            this->_localSave.at(i) = str;
        }
        if (cuted.at(0) == "country_color") {
            i++;
            std::string str = "\t\t\t\t" + std::to_string(this->_actual.getColors().getCountryColors().at(0)) + ' ' + std::to_string(this->_actual.getColors().getCountryColors().at(1)) + ' ' + std::to_string(this->_actual.getColors().getCountryColors().at(2));
            this->_localSave.at(i) = str;
        }
    }

    return i;
}

int Write::technology(int i) {
    std::string sub;
    std::vector<std::string> cuted;
    sub = this->_localSave.at(i);
    sub = sub.substr(2, sub.size());
    cuted = cutInPart('=', sub);
    if (cuted.at(0) == "technology_group") {
        std::string str = "\t\t";
        str += "technology_group=" + this->_actual.getTechnology().getTechnologyGroup();
        this->_localSave.at(i) = str;
        return i;
    }
    for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t}"; i++) {
        _idea local;
        sub = this->_localSave.at(i);
        sub = sub.substr(3, sub.size());
        cuted = cutInPart('=', sub);
        if (cuted.at(0) == "adm_tech") {
            std::string str = "\t\t\t";
            str += "adm_tech=" + std::to_string(this->_actual.getTechnology().getAdmTech());
            this->_localSave.at(i) = str;
        }
        if (cuted.at(0) == "dip_tech") {
            std::string str = "\t\t\t";
            str += "dip_tech=" + std::to_string(this->_actual.getTechnology().getDipTech());
            this->_localSave.at(i) = str;
        }
        if (cuted.at(0) == "mil_tech") {
            std::string str = "\t\t\t";
            str += "mil_tech=" + std::to_string(this->_actual.getTechnology().getMilTech());
            this->_localSave.at(i) = str;
        }
    }

    return i;
}

int Write::three(int i) {
    std::string sub;
    std::vector<std::string> cuted;
    sub = this->_localSave.at(i);
    sub = sub.substr(2, sub.size());
    cuted = cutInPart('=', sub);
    if (cuted.at(0) == "owned_provinces") {
        i++;
        sub = this->_localSave.at(i);
        sub = sub.substr(3, sub.size());
        cuted = cutInPart(' ', sub);
        for (int o = 0; (size_t)o < cuted.size(); o++) {
            std::string tst = cuted.at(o);
            if (tst.at(0) == '-')
                tst = tst.substr(1, tst.size());
            if (tst.size() >= 3)
                this->_initCountry = true;
            this->_actual.addOwnedProvince(std::stof(tst.c_str()));
        }
    }
    if (cuted.at(0) == "powers" ) {
        i++;
        sub = this->_localSave.at(i);
        sub = sub.substr(3, sub.size());
        cuted = cutInPart(' ', sub);
        for (int o = 0; (size_t)o < cuted.size(); o++)
            this->_actual.addPowers(std::stof(cuted.at(0).c_str()));
    }

    return i;
}

int Write::misc(int i, std::string sub) {
    std::vector<std::string> cuted;
    if (sub == "primary_culture") {
        std::vector<std::string> cuted;
        sub = this->_localSave.at(i);
        sub = sub.substr(2, sub.size());
        cuted = cutInPart('=', sub);
        char t = this->_actual.getPrimaryCulture().at(0);
        t = std::tolower(t);
        std::string ts = t + this->_actual.getPrimaryCulture().substr(1, this->_actual.getPrimaryCulture().size());
        std::string str = "\t\tprimary_culture=" + ts;
        this->_localSave.at(i) = str;
    }
    if (sub == "religion") {
        std::vector<std::string> cuted;
        sub = this->_localSave.at(i);
        sub = sub.substr(2, sub.size());
        cuted = cutInPart('=', sub);
        std::string str = "\t\treligion=" + this->_actual.getReligion();
        this->_localSave.at(i) = str;
    }
    if (sub == "rival") {
        i++;
        std::string str = "\t\t\tcountry=";
        str += this->_actual.getRival().at(nbRival);
        this->_localSave.at(i) = str;
        nbRival++;
    }

    return i;
}

std::vector<std::string> Write::cutInPart(char delimiter, std::string sub) {
    std::vector<std::string> cuted;
    int i = 0;
    for (; (size_t)i < sub.size() && (sub.at(i) == '\t' || sub.at(i) == ' '); i++);
    sub = sub.substr(i, sub.size());
    i = 0;
    for (; (size_t)i < sub.size(); i++)
        if (sub.at(i) == delimiter) {
            cuted.push_back(sub.substr(0, i));
            sub = sub.substr(i + 1, sub.size());
            i = 0;
        }
    if (sub != "")
        cuted.push_back(sub);
    return cuted;
}

std::vector<std::string> Write::getSave() {
    return this->_localSave;
}
std::vector<Province> Write::getProvince() {
    return this->_localProvince;
}
std::vector<Country> Write::getCountry() {
    return this->_country;
}


std::string Write::with(int i, float nb, char del) {
    std::string sub = this->_localSave.at(i);
    if (del != 'N') {
        int y = 0;
        for (; (size_t)y < sub.size(); y++)
        if (sub.at(y) == del) {
            sub = sub.substr(0, y + 1);
        }
    }
    else {
        int y = 0;
        for (; (size_t)y < sub.size() && (sub.at(y) == '\t' || sub.at(y) == ' '); y++);
        sub.substr(0, y);
    }
    sub += std::to_string(nb);
    return sub;
}

std::string Write::with(int i, std::string nb, char del) {
    std::string sub = this->_localSave.at(i);
    if (del != 'N') {
        int y = 0;
        for (; (size_t)y < sub.size(); y++)
        if (sub.at(y) == del) {
            sub = sub.substr(0, y + 1);
        }
    }
    else {
        int y = 0;
        for (; (size_t)y < sub.size() && (sub.at(y) == '\t' || sub.at(y) == ' '); y++);
        sub.substr(0, y);
    }
    sub += nb;
    return sub;
}

std::string Write::with(int i, int nb, char del) {
    std::string sub = this->_localSave.at(i);
    if (del != 'N') {
        int y = 0;
        for (; (size_t)y < sub.size(); y++)
        if (sub.at(y) == del) {
            sub = sub.substr(0, y + 1);
        }
    }
    else {
        int y = 0;
        for (; (size_t)y < sub.size() && (sub.at(y) == '\t' || sub.at(y) == ' '); y++);
        sub.substr(0, y);
    }
    sub += std::to_string(nb);
    return sub;
}

int Write::addLine(int i, std::vector<std::string> sub, int tab) {
    std::string del = "";
    std::string start = "";
    int saveI = i;
    for (int y = 0; y != tab; y++)
        del += "\t";
    start = del;
    start += "{";
    del += "}";
    for (; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != del; i++)
        if (this->_localSave.at(i + 1) != del) {
            for (int y = i; ((size_t)y + 1) < this->_localSave.size(); y++)
                this->_localSave.at(y) == this->_localSave.at(y + 1);
            this->_localSave.erase(this->_localSave.begin() + this->_localSave.size() - 1);
        }
    if (this->_localSave.at(saveI) == start)
        saveI++;
    i = saveI;
    for (int y = 0; (size_t)y < sub.size(); y++) {
        for (int o = this->_localSave.size() - 1; o != i; o--) {
            if (o == this->_localSave.size() - 1) {
                this->_localSave.push_back(this->_localSave.at(o));
            } else {
                this->_localSave.at(o) = this->_localSave.at(o - 1);
            }
        }
        this->_localSave.at(i) = sub.at(y);
        i++;
    }

    return i;
}

void Write::revoke(int i, int nb) {
    int iSave = i;
    bool end = false;
    for (; this->_localSave.size() > i && end == false; i++) {
        if (nb == 3 && this->_localSave.at(i) != "\t\t\t}") {
            this->_localSave.at(i) = " ";
        }else if (nb == 4 && this->_localSave.at(i) != "\t\t\t\t}") {
            this->_localSave.at(i) = " ";
        } else if (nb == 2 && this->_localSave.at(i) != "\t\t}") {
            this->_localSave.at(i) = " ";
        }
        if (nb == 3 && this->_localSave.at(i) == "\t\t\t}") {
            end = true;
        }else if (nb == 4 && this->_localSave.at(i) == "\t\t\t\t}") {
            end = true;
        } else if (nb == 2 && this->_localSave.at(i) == "\t\t}") {
            end = true;
        }
    }
}