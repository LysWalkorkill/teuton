#ifndef _TECHNOLOGY_
#define _TECHNOLOGY_

#include <string>
#include <vector>

namespace teuton::parser {
    class Technology {
        public:
            Technology();
            ~Technology();

            void setTechnologyGroup(std::string);
            void setAdmTech(int);
            void setDipTech(int);
            void setMilTech(int);

            std::string getTechnologyGroup();
            int getAdmTech();
            int getDipTech();
            int getMilTech();

        private:
            std::string technologyGroup;
            int admTech;
            int dipTech;
            int milTech;
    };
}

#endif