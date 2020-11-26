#include "../include/Technology.hpp"

using namespace teuton::parser;

Technology::Technology() {}
Technology::~Technology() {}

void Technology::setTechnologyGroup(std::string technologyGroup) {
    this->technologyGroup = technologyGroup;
}
void Technology::setAdmTech(int admTech) {
    this->admTech = admTech;
}
void Technology::setDipTech(int dipTech) {
    this->dipTech = dipTech;
}
void Technology::setMilTech(int milTech) {
    this->milTech = milTech;
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