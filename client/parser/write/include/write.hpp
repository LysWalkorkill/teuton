#ifndef _WRITE_
#define _WRITE_

#include <string>
#include <vector>
#include <iostream>
#include "manipulate.hpp"

namespace teuton::parser {
    class write {
        public :
            write(std::string path, std::vector<std::string> save, std::vector<country> _country, std::vector<_province> province);
            ~write();
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
            std::string with(int i, float nb, char del);
            std::string with(int i, int nb, char del);
            std::string with(int i, std::string nb, char del);
            int addLine(int i, std::vector<std::string> sub, int tab);
            /*std::string withF(int i, float nb, char del);
            std::string withS(int i, std::string nb, char del);
            std::string withI(int i, int nb, char del);
*/
        private :
            std::vector<std::string> _localSave;
            std::vector<country> _country;
            std::vector<_province> _localProvince;
            int _tag;
            int _nb;
            int _nbEstate;
            bool _initCountry;
            int _rival;
    };
}

#endif