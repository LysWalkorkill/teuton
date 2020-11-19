#ifndef _INFOFILE_
#define _INFOFILE_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

namespace teuton::parser {
    class infoFile {
        public :
            infoFile(std::string path);
            ~infoFile();
            bool isWorking();
            std::string getPath();
            std::ifstream &getFile();
            std::vector<std::string> getSave();

        private :
            std::string path;
            std::ifstream file;
            std::vector<std::string> LocalSave;
    };
}

#endif