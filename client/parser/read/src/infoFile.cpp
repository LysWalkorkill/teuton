#include "../include/infoFile.hpp"

using namespace teuton::parser;

infoFile::infoFile(std::string path) {
    this->path = path;
}

infoFile::~infoFile() {}

bool infoFile::isWorking() {
    this->file.open(this->path);
    if (!this->file.is_open()) {
        std::cout << "Unable to open file " << this->path;
        return false;
    }
    std::string line;
    while (std::getline(this->file, line))
        this->LocalSave.push_back(line);
    return true;
}

std::string infoFile::getPath() {
    return this->path;
}

std::ifstream &infoFile::getFile() {
    return this->file;
}

std::vector<std::string> infoFile::getSave() {
    return this->LocalSave;
}