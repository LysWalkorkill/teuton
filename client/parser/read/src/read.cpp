#include "../include/read.hpp"

using namespace teuton::parser;

read::read(std::string path) {
    this->_info = new infoFile(path);
    this->_working = this->_info->isWorking();
    this->_localSave = this->_info->getSave();

    foundTag();
}

read::~read() {}

void read::foundTag() {
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
        if (this->_localSave.at(i).at(0) == '\t' && this->_localSave.at(i).at(4) == '=') {
            std::string tag = this->_localSave.at(i).substr(1, 3);
            Country _new;
            Government _newG;
            StateViews _newS;
            Technology _newT;
            this->_actual = _new;
            this->_localGovernment = _newG;
            this->_localStateViews = _newS;
            this->_localTechnology = _newT;
            i = parseTag(tag, i);
        }
    }

    // draw info
    // for (int i = 0; i != 30; i++) {
    std::cout << "design" << std::endl;
    for (int i = 0; i != 4; i++) {
        std::cout << "tag: " << this->_country.at(i).getTag() << std::endl;
        std::cout << "primaryCulture: " << this->_country.at(i).getPrimaryCulture() << std::endl;
        std::cout << "religion: " << this->_country.at(i).getReligion() << std::endl;
        std::cout << std::endl;
        std::cout << "rival: ";
        for (int o = 0; (size_t)o < this->_country.at(i).getRival().size(); o++) {
            std::cout << this->_country.at(i).getRival().at(o) << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "ownedProvinces: ";
        for (int o = 0; (size_t)o < this->_country.at(i).getOwnedProvince().size(); o++) {
            std::cout << this->_country.at(i).getOwnedProvince().at(o) << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        for (int o = 0; (size_t)o < this->_country.at(i).getEstates().size(); o++) {
            std::cout << "types: " << this->_country.at(i).getEstates().at(o).getType() << std::endl;
            std::cout << "loyalty: " << this->_country.at(i).getEstates().at(o).getLoyalty() << std::endl;
            std::cout << "territory: " << this->_country.at(i).getEstates().at(o).getTerritory() << std::endl;
            std::cout << "grantedPrivileges: ";
            for (int y = 0; (size_t)y < this->_country.at(i).getEstates().at(o).getGrantedPrivileges().size(); y++) {
                std::cout << this->_country.at(i).getEstates().at(o).getGrantedPrivileges().at(y) << " ";
            }
            std::cout << std::endl;
            std::cout << std::endl;
        }
        for (int o = 0; (size_t)o < this->_country.at(i).getActiveIdeaGroup().size(); o++) {
            std::cout << this->_country.at(i).getActiveIdeaGroup().at(o).getIdeaName() << std::endl;
            std::cout << this->_country.at(i).getActiveIdeaGroup().at(o).getIdeaLevel() << std::endl;
        }
        std::cout << std::endl;
        std::cout << "governmentRank: " << this->_country.at(i).getGovernment().getGovernmentRank() << std::endl;
        std::cout << "governmentName: " << this->_country.at(i).getGovernment().getGovernmentName() << std::endl;
        std::cout << "government: " << this->_country.at(i).getGovernment().getGovernment() << std::endl;
        std::cout << "reforms: ";
        for (int o = 0; (size_t)o < this->_country.at(i).getGovernment().getReform().size(); o++) {
            std::cout << this->_country.at(i).getGovernment().getReform().at(o) << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "currentPowerProjection: " << this->_country.at(i).getStateViews().getCurrentPowerProjection() << std::endl;
        std::cout << "prestige: " << this->_country.at(i).getStateViews().getPrestige() << std::endl;
        std::cout << "stability: " << this->_country.at(i).getStateViews().getStability() << std::endl;
        std::cout << "legitimacy: " << this->_country.at(i).getStateViews().getLegitimacy() << std::endl;
        std::cout << "manpower: " << this->_country.at(i).getStateViews().getManpower() << std::endl;
        std::cout << "innovativeness: " << this->_country.at(i).getStateViews().getInnovativeness() << std::endl;
        std::cout << "revolutionaryColors: ";
        for (int o = 0; (size_t)o < this->_country.at(i).getColors().getRevolutionaryColors().size(); o++) {
            std::cout << this->_country.at(i).getColors().getRevolutionaryColors().at(o) << " ";
        }
        std::cout << std::endl;
        std::cout << "mapColors: ";
        for (int o = 0; (size_t)o < this->_country.at(i).getColors().getMapColors().size(); o++) {
            std::cout << this->_country.at(i).getColors().getMapColors().at(o) << " ";
        }
        std::cout << std::endl;
        std::cout << "countryColors: ";
        for (int o = 0; (size_t)o < this->_country.at(i).getColors().getCountryColors().size(); o++) {
            std::cout << this->_country.at(i).getColors().getCountryColors().at(o) << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "technologyGroup: " << this->_country.at(i).getTechnology().getTechnologyGroup() << std::endl;
        std::cout << "admTech: " << this->_country.at(i).getTechnology().getAdmTech() << std::endl;
        std::cout << "dipTech: " << this->_country.at(i).getTechnology().getDipTech() << std::endl;
        std::cout << "milTech: " << this->_country.at(i).getTechnology().getMilTech() << std::endl;
        std::cout << "powers: ";
        for (int o = 0; (size_t)o < this->_country.at(i).getPowers().size(); o++) {
            std::cout << this->_country.at(i).getPowers().at(o) << " ";
        }
        std::cout << std::endl;
        std::cout << "-------------------------------------" << std::endl;
    }

    /*std::cout << "---------------province---------------" << std::endl;
    for (int i = 0; (size_t)i < this->_localProvince.size(); i++) {
        std::cout << std::endl;
        std::cout << this->_localProvince.at(i).name << std::endl;
        std::cout << this->_localProvince.at(i).baseTax << std::endl;
        std::cout << this->_localProvince.at(i).baseProduction << std::endl;
        std::cout << this->_localProvince.at(i).baseManpower << std::endl;
    }*/
}

int read::baseProvince(std::string province, int i) {
    Province actualProvince;
    std::string sub;
    std::vector<std::string> cuted;
    bool equal;

    sub = this->_localSave.at(i);
    cuted = cutInPart('=', sub);
    actualProvince.setName(cuted.at(0));
    
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
                        actualProvince.setBaseTax(std::atoi(cuted.at(1).c_str()));
                    else if (cuted.at(0) == "base_production")
                        actualProvince.setBaseProduction(std::atoi(cuted.at(1).c_str()));
                    else if (cuted.at(0) == "base_manpower")
                        actualProvince.setBaseManpower(std::atoi(cuted.at(1).c_str()));
            }
        }
    }
    this->_localProvince.push_back(actualProvince);

    return i;
}

int read::parseTag(std::string tag, int i) {
    this->_actual = *new Country;
    this->_actual.setTag(tag);
    this->_initCountry = false;
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
        else if (sub == "current_power_projection" || sub == "prestige" || sub == "stability" || sub == "devotion" || sub == "meritocracy" || sub == "legitimacy" || sub == "manpower" || sub == "innovativeness") {
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
    this->_actual.setGovernment(this->_localGovernment);
    this->_actual.setStateViews(this->_localStateViews);
    this->_actual.setTechnology(this->_localTechnology);
    if (this->_initCountry)
        this->_country.push_back(this->_actual);
    return i;
}

int read::estate(int i) {
    std::string sub;
    std::vector<std::string> cuted;
    Estates estate;
    i++;
    for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t}"; i++) {
        sub = this->_localSave.at(i);
        sub = sub.substr(3, sub.size());
        cuted = cutInPart('=', sub);
        if (cuted.at(0) == "type")
            estate.setType(cuted.at(1));
        if (cuted.at(0) == "loyalty")
            estate.setLoyalty(std::stof(cuted.at(1)));
        if (cuted.at(0) == "territory")
            estate.setTerritory(std::stof(cuted.at(1)));
        if (cuted.at(0) == "granted_privileges")
            for(;this->_localSave.at(i) != "\t\t\t}";i++) {
                if (this->_localSave.at(i) == "\t\t\t\t{")
                    i++;
                else if (this->_localSave.at(i).size() > 3){
                    sub = sub.substr(4, sub.size());
                    cuted = cutInPart(' ', sub);
                    estate.addGrantedPrivileges(cuted.at(0));
                }
            }
    }
    this->_actual.addEsates(estate);

    return i;
}

int read::idea(int i) {
    std::string sub;
    std::vector<std::string> cuted;
    i++;
    for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t}"; i++) {
        ActiveIdeaGroup local;
        sub = this->_localSave.at(i);
        sub = sub.substr(3, sub.size());
        if (sub != "") {
            cuted = cutInPart('=', sub);
            local.setIdeaLevel(std::atoi(cuted.at(1).c_str()));
            local.setIdeaName(cuted.at(0));
            this->_actual.addActiveIdeaGroup(local);
        }
    }

    return i;
}

int read::government(int i, std::string sub) {
    std::vector<std::string> cuted;
    cuted = cutInPart('=', this->_localSave.at(i));
    bool out = false;
    if (cuted.at(0) == "government_rank")
        this->_localGovernment.setGovernmentRank(std::atoi(cuted.at(1).c_str()));
    if (cuted.at(0) == "government_name")
        this->_localGovernment.setGovernmentName(cuted.at(1));
    if (cuted.at(0) == "government") {
        i++;
        for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t}"; i++) {
            sub = this->_localSave.at(i);
            sub = sub.substr(3, sub.size());
            cuted = cutInPart('=', sub);
            if (cuted.at(0) == "government")
                this->_localGovernment.setGovernment(cuted.at(1));
            if (cuted.at(0) == "reform_stack") {
                i++; 
                for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t\t}" && !out; i++)
                    for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t\t\t}" && this->_localSave.at(i) != "\t\t\t\thistory={"; i++) {
                        sub = this->_localSave.at(i);
                        sub = sub.substr(4, sub.size());
                        if (sub != "reforms={") {
                            out = true;
                            sub = sub.substr(1, sub.size());
                            this->_localGovernment.addReform(sub);
                        }
                    }
            }
        }
    }

    return i;
}

int read::stateViews(int i, std::string sub) {
    std::vector<std::string> cuted;
    cuted = cutInPart('=', this->_localSave.at(i));
    if (cuted.at(0) == "current_power_projection") {
        this->_localStateViews.setCurrentPowerProjection(std::stof(cuted.at(1)));
    }
    if (cuted.at(0) == "prestige")
        this->_localStateViews.setPrestige(std::stof(cuted.at(1)));
    if (cuted.at(0) == "stability")
        this->_localStateViews.setStability(std::stof(cuted.at(1)));
    if (cuted.at(0) == "devotion" || cuted.at(0) == "meritocracy" || cuted.at(0) == "legitimacy")
        this->_localStateViews.setLegitimacy(std::stof(cuted.at(1)));
    if (cuted.at(0) == "manpower")
        this->_localStateViews.setManpower(std::stof(cuted.at(1)));
    if (cuted.at(0) == "innovativeness")
        this->_localStateViews.setInnovativeness(std::stof(cuted.at(1)));

    return i;
}

int read::colors(int i) {
    std::string sub;
    std::vector<std::string> cuted;
    Colors colors;
    for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t}"; i++) {
        sub = this->_localSave.at(i);
        sub = sub.substr(3, sub.size());
        cuted = cutInPart('=', sub);
        std::vector<int> color;
        if (cuted.at(0) == "revolutionary_colors") {
            i++;
            sub = this->_localSave.at(i);
            sub = sub.substr(4, sub.size());
            cuted = cutInPart(' ', sub);
            for (int o = 0; (size_t)o < cuted.size(); o++)
                color.push_back(std::stof(cuted.at(0).c_str()));
            colors.setRevolutionaryColors(color);
        }
        if (cuted.at(0) == "map_color") {
            i++;
            sub = this->_localSave.at(i);
            sub = sub.substr(4, sub.size());
            cuted = cutInPart(' ', sub);
            for (int o = 0; (size_t)o < cuted.size(); o++)
                color.push_back(std::stof(cuted.at(0).c_str()));
            colors.setMapColors(color);
        }
        if (cuted.at(0) == "country_color") {
            i++;
            sub = this->_localSave.at(i);
            sub = sub.substr(4, sub.size());
            cuted = cutInPart(' ', sub);
            for (int o = 0; (size_t)o < cuted.size(); o++)
                color.push_back(std::stof(cuted.at(0).c_str()));
            colors.setCountryColors(color);
        }
    }
    this->_actual.setColor(colors);

    return i;
}

int read::technology(int i) {
    std::string sub;
    std::vector<std::string> cuted;
    sub = this->_localSave.at(i);
    sub = sub.substr(2, sub.size());
    cuted = cutInPart('=', sub);
    if (cuted.at(0) == "technology_group") {
        this->_localTechnology.setTechnologyGroup(cuted.at(1));
        return i;
    }
    for(; (size_t)i < this->_localSave.size() && this->_localSave.at(i) != "\t\t}"; i++) {
        _idea local;
        sub = this->_localSave.at(i);
        sub = sub.substr(3, sub.size());
        cuted = cutInPart('=', sub);
        if (cuted.at(0) == "adm_tech")
            this->_localTechnology.setAdmTech(std::atoi(cuted.at(1).c_str()));
        if (cuted.at(0) == "dip_tech")
            this->_localTechnology.setDipTech(std::atoi(cuted.at(1).c_str()));  
        if (cuted.at(0) == "mil_tech")
            this->_localTechnology.setMilTech(std::atoi(cuted.at(1).c_str()));  
    }

    return i;
}

int read::three(int i) {
    std::string sub;
    std::vector<std::string> cuted;
    sub = this->_localSave.at(i);
    sub = sub.substr(2, sub.size());
    cuted = cutInPart('=', sub);
    if (cuted.at(0) == "owned_provinces") {
        this->_initCountry = true;
        i++;
        sub = this->_localSave.at(i);
        sub = sub.substr(3, sub.size());
        cuted = cutInPart(' ', sub);
        for (int o = 0; (size_t)o < cuted.size(); o++)
            this->_actual.addOwnedProvince(std::stof(cuted.at(o).c_str()));
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

int read::misc(int i, std::string sub) {
    std::vector<std::string> cuted;
    if (sub == "primary_culture") {
        std::vector<std::string> cuted;
        sub = this->_localSave.at(i);
        sub = sub.substr(2, sub.size());
        cuted = cutInPart('=', sub);
        this->_actual.setPrimaryCulture(cuted.at(1));
    }
    if (sub == "religion") {
        std::vector<std::string> cuted;
        sub = this->_localSave.at(i);
        sub = sub.substr(2, sub.size());
        cuted = cutInPart('=', sub);
        this->_actual.setReligion(cuted.at(1));
    }
    if (sub == "rival") {
        i++;
        std::vector<std::string> cuted;
        sub = this->_localSave.at(i);
        sub = sub.substr(2, sub.size());
        cuted = cutInPart('=', sub);
        this->_actual.addRival(cuted.at(1));
    }

    return i;
}

std::vector<std::string> read::cutInPart(char delimiter, std::string sub) {
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

std::vector<std::string> read::getSave() {
    return this->_localSave;
}
std::vector<Province> read::getProvince() {
    return this->_localProvince;
}
std::vector<Country> read::getCountry() {
    return this->_country;
}