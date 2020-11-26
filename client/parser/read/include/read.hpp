#ifndef _READ_
#define _READ_

#include <string>
#include <vector>
#include <iostream>
#include <string>  
#include "manipulate.hpp"
#include "infoFile.hpp"
#include "Country.hpp"
#include "Province.hpp"

namespace teuton::parser {
    class read {
        public :
            read(std::string path);
            ~read();
            void foundTag();
            int parseTag(std::string tag, int i);
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

        private :
            bool _initCountry;
            bool _working;
            infoFile *_info;
            std::vector<std::string> _localSave;
            Country _actual;
            std::vector<Country> _country;
            std::vector<Province> _localProvince;
            Government _localGovernment;
            StateViews _localStateViews;
            Technology _localTechnology;
            /*country _actual;
            std::vector<country> _country;
            std::vector<_province> _localProvince;
            _government _localGovernment;
            _stateViews _localStateViews;
            _technology _localTechnology;*/
    };
}

#endif