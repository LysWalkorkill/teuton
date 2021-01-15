#ifndef _WRITE_
#define _WRITE_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "manipulate.hpp"
#include "Technology.hpp"
#include "StateViews.hpp"
#include "Government.hpp"
#include "Estates.hpp"
#include "Country.hpp"
#include "Colors.hpp"
#include "ActiveIdeaGroup.hpp"

namespace teuton::parser {
    class Write {
        public :
            Write(std::string path, std::vector<std::string> save, std::vector<Country> _country, std::vector<Province> province, std::vector<std::string> tagList);
            ~Write();
            void foundTag();
            int parseTag(std::string tag, int i, Country);
            int estate(int);
            int idea(int);
            int government(int, std::string);
            int stateViews(int, std::string);
            int colors(int);
            int technology(int);
            int three(int);
            int misc(int, std::string);
            std::vector<std::string> cutInPart(char, std::string);
            int baseProvince(std::string, int);
            std::vector<std::string> getSave();
            std::vector<Province> getProvince();
            std::vector<Country> getCountry();
            std::string with(int i, float nb, char del);
            std::string with(int i, int nb, char del);
            std::string with(int i, std::string nb, char del);
            int addLine(int i, std::vector<std::string> sub, int tab);
            void revoke(int, int);

        private :
            bool _initCountry;
            bool _working;
            std::vector<std::string> _localSave;
            Country _actual;
            std::vector<Country> _country;
            std::vector<Province> _localProvince;
            Government _localGovernment;
            StateViews _localStateViews;
            Technology _localTechnology;
            int nbRival = 0;

            std::vector<std::string> tagList;
            int nbEstate = 0;
    };
}

#endif