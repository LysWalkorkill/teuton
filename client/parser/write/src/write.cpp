#include "../include/write.hpp"

using namespace teuton::parser;

write::write(std::string path, std::vector<std::string> save, std::vector<country> _country, std::vector<_province> province) {
    this->_localSave = save;
    this->_country = _country;
    this->_localProvince = province;
    foundTag();
}

write::~write() {}

void write::foundTag() {
    int i = 0;
    this->_tag = 0;
    this->_nb = 0;
    this->_rival = 0;
    for (;(size_t)i < this->_localSave.size() && this->_localSave.at(i) != "countries={" && this->_localProvince.size() > (size_t)this->_nb; i++)
        if (this->_localSave.at(i).size() > (size_t)5 && this->_localSave.at(i).at(0) == '-' && this->_localSave.at(i).size() > 2 && this->_localSave.at(i).size() <= 7) {
            i = baseProvince(this->_localSave.at(i), i);
            this->_nb++;
        }
    for (;(size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t}"; i++);
    i++;
    for (;(size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t}"; i++);
    i++;
    for (;(size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t}"; i++);
    i++;
    for (;(size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t}"; i++);
    i++;
    for (;(size_t)i < this->_localSave.size() && this->_localSave.at(i) != "}" && this->_tag < this->_country.size(); i++) {
        if (this->_localSave.at(i).at(0) == '\t' && this->_localSave.at(i).at(4) == '=') {
            std::string tag = this->_localSave.at(i).substr(1, 3);
            if (tag == this->_country.at(this->_tag).tag) {
                std::cout << tag << "passed" << std::endl;
                i = parseTag(tag, i);
                this->_rival = 0;
                this->_tag++;
            }
            else {
                std::cout << tag << "failed" << std::endl;
                for (; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t}";i++);
            }
        }
    }
    // draw info
    //for (int i = 0; (size_t)i < this->_localSave.size(); i++)
    //    std::cout << this->_localSave.at(i) << std::endl;
    // for (int i = 0; i != 30; i++) {
    /*std::cout << "design" << std::endl;
    for (int i = 0; (size_t)i < this->_country.size(); i++) {
        std::cout << "tag: " << this->_country.at(i).tag << std::endl;
        std::cout << "primaryCulture: " << this->_country.at(i).primaryCulture << std::endl;
        std::cout << "religion: " << this->_country.at(i).religion << std::endl;
        std::cout << std::endl;
        std::cout << "rival: ";
        for (int o = 0; (size_t)o < this->_country.at(i).rival.size(); o++) {
            std::cout << this->_country.at(i).rival.at(o) << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "ownedProvinces: ";
        for (int o = 0; (size_t)o < this->_country.at(i).ownedProvince.size(); o++) {
            std::cout << this->_country.at(i).ownedProvince.at(o) << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        for (int o = 0; (size_t)o < this->_country.at(i).estates.size(); o++) {
            std::cout << "types: " << this->_country.at(i).estates.at(o).type << std::endl;
            std::cout << "loyalty: " << this->_country.at(i).estates.at(o).loyalty << std::endl;
            std::cout << "territory: " << this->_country.at(i).estates.at(o).territory << std::endl;
            std::cout << "grantedPrivileges: ";
            for (int y = 0; (size_t)y < this->_country.at(i).estates.at(o).grantedPrivileges.size(); y++) {
                std::cout << this->_country.at(i).estates.at(o).grantedPrivileges.at(y) << " ";
            }
            std::cout << std::endl;
            std::cout << std::endl;
        }
        for (int o = 0; (size_t)o < this->_country.at(i).activeIdeaGroup.size(); o++) {
            std::cout << this->_country.at(i).activeIdeaGroup.at(o).ideaName << std::endl;
            std::cout << this->_country.at(i).activeIdeaGroup.at(o).ideaLevel << std::endl;
        }
        std::cout << std::endl;
        std::cout << "governmentRank: " << this->_country.at(i).government.governmentRank << std::endl;
        std::cout << "governmentName: " << this->_country.at(i).government.governmentName << std::endl;
        std::cout << "government: " << this->_country.at(i).government.government << std::endl;
        std::cout << "reforms: ";
        for (int o = 0; (size_t)o < this->_country.at(i).government.reform.size(); o++) {
            std::cout << this->_country.at(i).government.reform.at(o) << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "currentPowerProjection: " << this->_country.at(i).stateViews.currentPowerProjection << std::endl;
        std::cout << "prestige: " << this->_country.at(i).stateViews.prestige << std::endl;
        std::cout << "stability: " << this->_country.at(i).stateViews.stability << std::endl;
        std::cout << "legitimacy: " << this->_country.at(i).stateViews.legitimacy << std::endl;
        std::cout << "manpower: " << this->_country.at(i).stateViews.manpower << std::endl;
        std::cout << "innovativeness: " << this->_country.at(i).stateViews.innovativeness << std::endl;
        std::cout << "revolutionaryColors: ";
        for (int o = 0; (size_t)o < this->_country.at(i).colors.revolutionaryColors.size(); o++) {
            std::cout << this->_country.at(i).colors.revolutionaryColors.at(o) << " ";
        }
        std::cout << std::endl;
        std::cout << "mapColors: ";
        for (int o = 0; (size_t)o < this->_country.at(i).colors.mapColors.size(); o++) {
            std::cout << this->_country.at(i).colors.mapColors.at(o) << " ";
        }
        std::cout << std::endl;
        std::cout << "countryColors: ";
        for (int o = 0; (size_t)o < this->_country.at(i).colors.countryColors.size(); o++) {
            std::cout << this->_country.at(i).colors.countryColors.at(o) << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "technologyGroup: " << this->_country.at(i).technology.technologyGroup << std::endl;
        std::cout << "admTech: " << this->_country.at(i).technology.admTech << std::endl;
        std::cout << "dipTech: " << this->_country.at(i).technology.dipTech << std::endl;
        std::cout << "milTech: " << this->_country.at(i).technology.milTech << std::endl;
        std::cout << "powers: ";
        for (int o = 0; (size_t)o < this->_country.at(i).powers.size(); o++) {
            std::cout << this->_country.at(i).powers.at(o) << " ";
        }
        std::cout << std::endl;
        std::cout << "-------------------------------------" << std::endl;
    }*/

    /*std::cout << "---------------province---------------" << std::endl;
    for (int i = 0; (size_t)i < this->_localProvince.size(); i++) {
        std::cout << std::endl;
        std::cout << this->_localProvince.at(i).name << std::endl;
        std::cout << this->_localProvince.at(i).baseTax << std::endl;
        std::cout << this->_localProvince.at(i).baseProduction << std::endl;
        std::cout << this->_localProvince.at(i).baseManpower << std::endl;
    }*/
}

int write::baseProvince(std::string province, int i) {
    std::string sub;
    std::vector<std::string> cuted;
    bool equal;

    sub = this->_localSave.at(i);
    cuted = cutInPart('=', sub);
    
    for (; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t}";i++) {
        if ((size_t)2 < this->_localSave.at(i).size()) {
            equal = false;
            sub = this->_localSave.at(i);
            sub = sub.substr(2, sub.size());
            for (int o = 0; (size_t)o < sub.size(); o++)
                if (sub.at(o) == '=')
                    equal = true;
            if (equal) {
                cuted = cutInPart('=', sub);
                    if (cuted.at(0) == "base_tax")
                       this->_localSave.at(i) = with(i, this->_localProvince.at(this->_nb).baseTax, '=');
                    else if (cuted.at(0) == "base_production")
                        this->_localSave.at(i) = with(i, this->_localProvince.at(this->_nb).baseProduction, '=');
                    else if (cuted.at(0) == "base_manpower")
                        this->_localSave.at(i) = with(i, this->_localProvince.at(this->_nb).baseManpower, '=');
            }
        }
    }

    return i;
}

int write::parseTag(std::string tag, int i) {
    this->_nbEstate = 0;
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
            //std::cout << "1" << std::endl;
            i = government(i, sub);
        }
        else if (sub == "estate") {
            //std::cout << "2" << std::endl;
            i = estate(i);
        }
        else if (sub == "active_idea_groups") {
            //std::cout << "3" << std::endl;
            i = idea(i);
        }
        else if (sub == "current_power_projection" || sub == "prestige" || sub == "stability" || sub == "devotion" || sub == "meritocracy" || sub == "legitimacy" || sub == "manpower" || sub == "innovativeness") {
            //std::cout << "4" << std::endl;
            i = stateViews(i, sub);
        }
        else if (sub == "colors") {
            //std::cout << "5" << std::endl;
            i = colors(i);
        }
        else if (sub == "technology" || sub == "technology_group") {
            //std::cout << "6" << std::endl;
            i = technology(i);
        }
        else if (sub == "primary_culture" || sub == "religion" || sub == "rival") {
            //std::cout << "7" << std::endl;
            i = misc(i, sub);
        }
        else if (sub == "owned_provinces" || sub == "powers") {
            //std::cout << "8" << std::endl;
            i = three(i);
        }
    }

    return i;
}

int write::estate(int i) {
    std::string sub;
    std::vector<std::string> cuted;
    std::vector<std::string> toAdd;

    i++;
    int pr = 0;
    for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t}"; i++) {
        sub = this->_localSave.at(i);
        sub = sub.substr(3, sub.size());
        cuted = cutInPart('=', sub);
        if (cuted.at(0) == "loyalty")
            this->_localSave.at(i) = with(i, this->_country.at(this->_tag).estates.at(this->_nbEstate).loyalty, '=');
        if (cuted.at(0) == "territory")
            this->_localSave.at(i) = with(i, this->_country.at(this->_tag).estates.at(this->_nbEstate).territory, '=');
        if (cuted.at(0) == "granted_privileges")
            for(;this->_localSave.at(i) != "\t\t\t}";i++) {
                if (this->_localSave.at(i) == "\t\t\t\t{")
                    i++;
                else if (this->_localSave.at(i).size() > 3){
                    for (int y = 0; (size_t)y < this->_country.at(this->_tag).estates.at(this->_nbEstate).grantedPrivileges.size(); y++) {
                        if (y == 0)
                            toAdd.push_back("\t\t\t\t}");
                        else
                            toAdd.push_back(" {");
                        toAdd.push_back("\t\t\t" + this->_country.at(this->_tag).estates.at(this->_nbEstate).grantedPrivileges.at(y) + " 1444.10.01\t\t\t\t}");
                    }
                    i = addLine(i, toAdd, 3);
                    pr++;
                }
            }
    }
    this->_nbEstate++;

    return i;
}

int write::idea(int i) {
    std::vector<std::string> toAdd;
    i++;
    if ((size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t}") {
        for (int y = 0; (size_t)y < this->_country.at(this->_tag).activeIdeaGroup.size(); y++)
            toAdd.push_back("\t\t\t" + this->_country.at(this->_tag).activeIdeaGroup.at(y).ideaName + " " + std::to_string(this->_country.at(this->_tag).activeIdeaGroup.at(y).ideaLevel));
        i = addLine(i, toAdd, 2);
    }

    return i;
}

int write::government(int i, std::string sub) {
    std::vector<std::string> cuted;
    std::vector<std::string> toAdd;
    cuted = cutInPart('=', this->_localSave.at(i));
    bool out = false;
    if (cuted.at(0) == "government_rank")
        this->_localSave.at(i) = "\t\tgovernment_rank=" + std::to_string(this->_country.at(this->_tag).government.governmentRank);
    if (cuted.at(0) == "government_name")
        this->_localSave.at(i) = "\t\tgovernment_name=" + '"' + this->_country.at(this->_tag).government.governmentName + '"';
    if (cuted.at(0) == "government") {
        i++;
        for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t}"; i++) {
            sub = this->_localSave.at(i);
            sub = sub.substr(3, sub.size());
            cuted = cutInPart('=', sub);
            if (cuted.at(0) == "government")
                this->_localSave.at(i) = "\t\t\tgovernment=" + '"' + this->_country.at(this->_tag).government.government + '"';
            if (cuted.at(0) == "reform_stack") {
                i++; 
                for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t\t}" && !out; i++)
                    for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t\t\t}" && out != true &&  this->_localSave.at(i) != "\t\t\t\thistory={"; i++) {
                        sub = this->_localSave.at(i);
                        sub = sub.substr(4, sub.size());
                        if (sub != "reforms={") {
                            out = true;
                            for (int y = 0; (size_t)y < this->_country.at(this->_tag).government.reform.size(); y++)
                                toAdd.push_back("\t\t\t\t\t" + '"' + this->_country.at(this->_tag).government.reform.at(y));
                            i = addLine(i, toAdd, 4);
                        }
                    }
            }
        }
    }

    return i;
}

int write::stateViews(int i, std::string sub) {
    std::vector<std::string> cuted;
    cuted = cutInPart('=', this->_localSave.at(i));
    if (cuted.at(0) == "current_power_projection") 
        this->_localSave.at(i) = "\t\tcurrent_power_projection=" + std::to_string(this->_country.at(this->_tag).stateViews.currentPowerProjection);
    if (cuted.at(0) == "prestige")
        this->_localSave.at(i) = "\t\tprestige=" + std::to_string(this->_country.at(this->_tag).stateViews.prestige);
    if (cuted.at(0) == "stability")
        this->_localSave.at(i) = "\t\tstability=" + std::to_string(this->_country.at(this->_tag).stateViews.stability);
    if (cuted.at(0) == "devotion" || cuted.at(0) == "meritocracy" || cuted.at(0) == "legitimacy")
        this->_localSave.at(i) = "\t\t" + cuted.at(0) + "=" + std::to_string(this->_country.at(this->_tag).stateViews.legitimacy);
    if (cuted.at(0) == "manpower")
        this->_localSave.at(i) = "\t\tmanpower=" + std::to_string(this->_country.at(this->_tag).stateViews.manpower);
    if (cuted.at(0) == "innovativeness")
        this->_localSave.at(i) = "\t\tinnovativeness=" + std::to_string(this->_country.at(this->_tag).stateViews.innovativeness);

    return i;
}

int write::colors(int i) {
    std::string sub;
    std::vector<std::string> cuted;
    for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t}"; i++) {
        sub = this->_localSave.at(i);
        sub = sub.substr(3, sub.size());
        cuted = cutInPart('=', sub);
        std::vector<int> color;
        if (cuted.at(0) == "revolutionary_colors") {
            i++;
            this->_localSave.at(i) = "\t\t\t\t" + this->_country.at(this->_tag).colors.revolutionaryColors.at(0) + ' ' + this->_country.at(this->_tag).colors.revolutionaryColors.at(1) + ' ' +this->_country.at(this->_tag).colors.revolutionaryColors.at(0);
        }
        if (cuted.at(0) == "map_color") {
            i++;
            this->_localSave.at(i) = "\t\t\t\t" + this->_country.at(this->_tag).colors.mapColors.at(0) + ' ' + this->_country.at(this->_tag).colors.mapColors.at(1) + ' ' +this->_country.at(this->_tag).colors.mapColors.at(0);
        }
        if (cuted.at(0) == "country_color") {
            i++;
            this->_localSave.at(i) = "\t\t\t\t" + this->_country.at(this->_tag).colors.countryColors.at(0) + ' ' + this->_country.at(this->_tag).colors.countryColors.at(1) + ' ' +this->_country.at(this->_tag).colors.countryColors.at(0);
        }
    }

    return i;
}

int write::technology(int i) {
    std::string sub;
    std::vector<std::string> cuted;
    sub = this->_localSave.at(i);
    sub = sub.substr(2, sub.size());
    cuted = cutInPart('=', sub);
    if (cuted.at(0) == "technology_group") {
        this->_localSave.at(i) = "technology_group=" + this->_country.at(this->_tag).technology.technologyGroup;
        return i;
    }
    for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t}"; i++) {
        _idea local;
        sub = this->_localSave.at(i);
        sub = sub.substr(3, sub.size());
        cuted = cutInPart('=', sub);
        if (cuted.at(0) == "adm_tech")
            this->_localSave.at(i) = "adm_tech=" + std::to_string(this->_country.at(this->_tag).technology.admTech); 
        if (cuted.at(0) == "dip_tech")
            this->_localSave.at(i) = "dip_tech=" + std::to_string(this->_country.at(this->_tag).technology.dipTech); 
        if (cuted.at(0) == "mil_tech")
            this->_localSave.at(i) = "mil_tech=" + std::to_string(this->_country.at(this->_tag).technology.milTech);  
    }

    return i;
}

int write::three(int i) {
    std::string sub;
    std::vector<std::string> cuted;
    sub = this->_localSave.at(i);
    sub = sub.substr(2, sub.size());
    cuted = cutInPart('=', sub);
    if (cuted.at(0) == "owned_provinces") {
        this->_initCountry = true;
        i++;
        sub = "\t\t\t";
        for (int o = 0; (size_t)o < this->_country.at(this->_tag).ownedProvince.size(); o++)
            sub += this->_country.at(this->_tag).ownedProvince.at(o) + " ";
        this->_localSave.at(i) = sub;
    }
    if (cuted.at(0) == "powers" ) {
        i++;
        sub = "\t\t\t";
        for (int o = 0; (size_t)o < this->_country.at(this->_tag).powers.size(); o++)
            sub += this->_country.at(this->_tag).powers.at(o) + " ";
        this->_localSave.at(i) = sub;
    }

    return i;
}

int write::misc(int i, std::string sub) {
    std::vector<std::string> cuted;
    if (sub == "primary_culture") {
        this->_localSave.at(i) = "\t\t\tprimary_culture=" + this->_country.at(this->_tag).primaryCulture;
    }
    if (sub == "religion") {
        this->_localSave.at(i) = "\treligion=" + this->_country.at(this->_tag).religion;
    }
    if (sub == "rival") {
        i++;
        this->_localSave.at(i) = "\t\t\tcountry=" + '"' + this->_country.at(this->_tag).rival.at(this->_rival) + '"';
        this->_rival++;
    }

    return i;
}

std::vector<std::string> write::cutInPart(char delimiter, std::string sub) {
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

std::string write::with(int i, float nb, char del) {
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

std::string write::with(int i, std::string nb, char del) {
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

std::string write::with(int i, int nb, char del) {
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

int write::addLine(int i, std::vector<std::string> sub, int tab) {
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
        //std::cout << "in 1" << std::endl;
        for (int o = this->_localSave.size() - 1; o != i; o--) {
            //std::cout << "in 2" << std::endl;
            if (o == this->_localSave.size() - 1) {
                //std::cout << "in 4" << std::endl;
                this->_localSave.push_back(this->_localSave.at(o));
            } else {
                //std::cout << "in 5" << std::endl;
                this->_localSave.at(o) = this->_localSave.at(o - 1);
            }
        }
        //std::cout << "in 3" << std::endl;
        this->_localSave.at(i) = sub.at(y);
        i++;
    }

    return i;
}