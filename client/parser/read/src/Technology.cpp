#include "../include/Technology.hpp"

using namespace teuton::parser;

Technology::Technology() {}
Technology::~Technology() {}

void Technology::setTechnologyGroup(std::string technologyGroup) {
    this->technologyGroup = technologyGroup;
}
void Technology::setAdmTech(int adm) {
    this->admTech = adm;
}
void Technology::setDipTech(int dip) {
    this->dipTech = dip;
}
void Technology::setMilTech(int mil) {
    this->milTech = mil;
}

std::string Technology::getTechnologyGroup() {
    return this->technologyGroup;
}
int Technology::getAdmTech() {
    return this->admTech;
}
int Technology::getDipTech() {
    return this->dipTech;
}
int Technology::getMilTech() {
    return this->milTech;
}