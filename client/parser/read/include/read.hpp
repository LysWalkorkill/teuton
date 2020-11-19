#ifndef _READ_
#define _READ_

#include <string>
#include <vector>
#include <iostream>
#include <string>  
#include "manipulate.hpp"
#include "infoFile.hpp"

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
            std::vector<_province> getProvince();
            std::vector<country> getCountry();

        private :
            country _actual;
            std::vector<country> _country;
            infoFile *_info;
            std::vector<std::string> _localSave;
            std::vector<_province> _localProvince;
            bool _working;
            _government _localGovernment;
            _stateViews _localStateViews;
            _technology _localTechnology;
            bool _initCountry;
    };
}

#endif