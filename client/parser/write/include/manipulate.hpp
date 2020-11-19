#ifndef _MANIPULATE_
#define _MANIPULATE_

#include <string>
#include <vector>

namespace teuton::parser {

    struct _estate {
        std::string type;
        float loyalty;
        float territory;
        std::vector<std::string> grantedPrivileges;
    };

    struct _province {
        std::string name;
        int baseTax;
        int baseProduction;
        int baseManpower;
    };

    struct _idea {
        std::string ideaName;
        int ideaLevel;
    };

    struct _government {
        int governmentRank;
        std::string governmentName;
        std::string government;
        std::vector<std::string> reform;
    };

    struct _stateViews {
        float currentPowerProjection;
        float prestige;
        float stability;
        float legitimacy;
        float manpower;
        float innovativeness;
    };

    struct _colors {
        std::vector<int> revolutionaryColors;
        std::vector<int> mapColors;
        std::vector<int> countryColors;
    };

    struct _technology {
        std::string technologyGroup;
        int admTech;
        int dipTech;
        int milTech;
    };

    struct country {
        std::string tag;
        std::string primaryCulture;
        std::string religion;
        std::vector<std::string> rival;
        std::vector<int> ownedProvince;
        std::vector<_estate> estates;
        std::vector<_idea> activeIdeaGroup;
        _government government;
        _stateViews stateViews;
        _colors colors;
        _technology technology;
        std::vector<int> powers;
    };


    class manipulate {
        public :
            manipulate();
            ~manipulate();

        private :

    };
}

#endif