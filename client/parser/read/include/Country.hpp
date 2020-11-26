#ifndef _COUNTRY_
#define _COUNTRY_

#include <string>
#include <vector>
#include "ActiveIdeaGroup.hpp"
#include "Colors.hpp"
#include "Estates.hpp"
#include "StateViews.hpp"
#include "Technology.hpp"
#include "Government.hpp"
#include "Province.hpp"

namespace teuton::parser {
    class Country {
        public:
            Country();
            ~Country();
            void setTag(std::string);
            void setPrimaryCulture(std::string);
            void setReligion(std::string);
            void addRival(std::string);
            void addOwnedProvince(int);
            void addPowers(int);

            void addEsates(Estates);
            void addActiveIdeaGroup(ActiveIdeaGroup);

            void setColor(Colors);
            void setStateViews(StateViews);
            void setTechnology(Technology);
            void setGovernment(Government);

            std::string getTag();
            std::string getPrimaryCulture();
            std::string getReligion();
            std::vector<std::string> getRival();
            std::vector<int> getPowers();

            std::vector<Estates> getEstates();
            std::vector<ActiveIdeaGroup> getActiveIdeaGroup();
            std::vector<int> getOwnedProvince();
            Government getGovernment();
            StateViews getStateViews();
            Colors getColors();
            Technology getTechnology();

        private:
            std::string tag;
            std::string primaryCulture;
            std::string religion;
            std::vector<std::string> rival;
            std::vector<int> ownedProvince;
            std::vector<int> powers;

            std::vector<ActiveIdeaGroup> _activeIdeaGroup;
            Colors _colors;
            std::vector<Estates> _estates;
            StateViews _stateViews;
            Technology _technology;
            Government _government;
    };
}

#endif