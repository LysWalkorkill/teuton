#include "../include/Estates.hpp"

using namespace teuton::parser;

Estates::Estates() {}
Estates::~Estates() {}

void Estates::setType(std::string type) {
    this->type = type;
}
void Estates::setLoyalty(float loyalty) {
    this->loyalty = loyalty;
}
void Estates::setTerritory(float territory) {
    this->territory = territory;
}
void Estates::addGrantedPrivileges(std::string grantedPrivileges) {
    this->grantedPrivileges.push_back(grantedPrivileges);
}

std::string Estates::getType() {
    return this->type;
}
float Estates::getLoyalty() {
    return this->loyalty;
}
float Estates::getTerritory() {
    return this->territory;
}
std::vector<std::string> Estates::getGrantedPrivileges() {
    return this->grantedPrivileges;
}