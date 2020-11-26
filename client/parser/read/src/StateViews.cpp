#include "../include/StateViews.hpp"

using namespace teuton::parser;

StateViews::StateViews() {}
StateViews::~StateViews() {}

void StateViews::setCurrentPowerProjection(float currentPowerProjection) {
    this->currentPowerProjection = currentPowerProjection;
}
void StateViews::setPrestige(float prestige) {
    this->prestige = prestige;
}
void StateViews::setStability(float stability) {
    this->stability = stability;
}
void StateViews::setLegitimacy(float legitimacy) {
    this->legitimacy = legitimacy;
}
void StateViews::setManpower(float manpower) {
    this->manpower = manpower;
}
void StateViews::setInnovativeness(float innovativeness) {
    this->innovativeness = innovativeness;
}

float StateViews::getCurrentPowerProjection() {
    return this->currentPowerProjection;
}
float StateViews::getPrestige() {
    return this->prestige;
}
float StateViews::getStability() {
    return this->stability;
}
float StateViews::getLegitimacy() {
    return this->legitimacy;
}
float StateViews::getManpower() {
    return this->manpower;
}
float StateViews::getInnovativeness() {
    return this->innovativeness;
}