#ifndef _ESTATES_
#define _ESTATES_

#include <string>
#include <vector>

namespace teuton::parser {
    class Estates {
        public:
            Estates();
            ~Estates();

            void setType(std::string);
            void setLoyalty(float);
            void setTerritory(float);
            void addGrantedPrivileges(std::string);

            std::string getType();
            float getLoyalty();
            float getTerritory();
            std::vector<std::string> getGrantedPrivileges();

        private:
            std::string type;
            float loyalty;
            float territory;
            std::vector<std::string> grantedPrivileges;
    };
}

#endif