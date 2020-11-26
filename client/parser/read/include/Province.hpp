#ifndef _PROVINCE_
#define _PROVINCE_

#include <string>
#include <vector>

namespace teuton::parser {
    class Province {
        public:
            Province();
            ~Province();

            void setName(std::string);
            void setBaseTax(int);
            void setBaseProduction(int);
            void setBaseManpower(int);

            std::string getName();
            int getBaseTaxe();
            int getBaseProduction();
            int getBaseManpower();

        private:
            std::string name;
            int basetax;
            int baseProduction;
            int baseManpower;

    };
}

#endif