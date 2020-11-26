#ifndef _GOVERNMENT_
#define _GOVERNMENT_

#include <string>
#include <vector>

namespace teuton::parser {
    class Government {
        public:
            Government();
            ~Government();

            void setGovernmentRank(int);
            void setGovernmentName(std::string);
            void setGovernment(std::string);
            void addReform(std::string);

            int getGovernmentRank();
            std::string getGovernmentName();
            std::string getGovernment();
            std::vector<std::string> getReform();

        private:
            int governmentRank;
            std::string governmentName;
            std::string government;
            std::vector<std::string> reform;

    };
}

#endif