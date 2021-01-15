#include "../include/Government.hpp"
#include <iostream>

using namespace teuton::parser;

Government::Government() {}
Government::~Government() {}

void Government::setGovernmentRank(int governmentRank) {
    this->governmentRank = governmentRank;
}
void Government::setGovernmentName(std::string governmentName) {
    this->governmentName = governmentName;
}
void Government::setGovernment(std::string government) {
    this->government = government;
}
void Government::addReform(std::string reform) {
    this->reform.push_back(reform);
}

int Government::getGovernmentRank() {
    return this->governmentRank;
}
std::string Government::getGovernmentName() {
    return this->governmentName;
}
std::string Government::getGovernment() {
    return this->government;
}
std::vector<std::string> Government::getReform() {
    return this->reform;
}

void Government::changeReform(int i, std::string newR) {
    reform.at(i) = newR;
}
