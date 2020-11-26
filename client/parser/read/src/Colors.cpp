#include "../include/Colors.hpp"

using namespace teuton::parser;

Colors::Colors() {}
Colors::~Colors() {}

void Colors::setRevolutionaryColors(std::vector<int> revolutionaryColors) {
    this->revolutionaryColors = revolutionaryColors;
}
void Colors::setMapColors(std::vector<int> mapColors) {
    this->mapColors = mapColors;
}
void Colors::setCountryColors(std::vector<int> countryColors) {
    this->countryColors = countryColors;
}

std::vector<int> Colors::getRevolutionaryColors() {
    return this->revolutionaryColors;
}
std::vector<int> Colors::getMapColors() {
    return this->mapColors;
}
std::vector<int> Colors::getCountryColors() {
    return this->countryColors;
}