#include "../include/Province.hpp"

using namespace teuton::parser;

Province::Province() {}
Province::~Province() {}

void Province::setName(std::string name) {
    this->name = name;
}
void Province::setBaseTax(int tax) {
    this->basetax = tax;
}
void Province::setBaseProduction(int production) {
    this->baseProduction = production;
}
void Province::setBaseManpower(int manpower) {
    this->baseManpower = manpower;
}

std::string Province::getName() {
    return this->name;
}
int Province::getBaseTaxe() {
    return this->basetax;
}
int Province::getBaseProduction() {
    return this->baseProduction;
}
int Province::getBaseManpower() {
    return this->baseManpower;
}