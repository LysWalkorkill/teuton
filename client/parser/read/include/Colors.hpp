#ifndef _COLORS_
#define _COLORS_

#include <string>
#include <vector>

namespace teuton::parser {
    class Colors {
        public:
            Colors();
            ~Colors();

            void setRevolutionaryColors(std::vector<int>);
            void setMapColors(std::vector<int>);
            void setCountryColors(std::vector<int>);

            std::vector<int> getRevolutionaryColors();
            std::vector<int> getMapColors();
            std::vector<int> getCountryColors();

        private:
            std::vector<int> revolutionaryColors;
            std::vector<int> mapColors;
            std::vector<int> countryColors;
    };
}

#endif