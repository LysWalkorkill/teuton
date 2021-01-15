#include "../include/Country.hpp"
#include <iostream>

using namespace teuton::parser;

Country::Country() {}
Country::~Country() {}

void Country::setTag(std::string tag) {
    this->tag = tag;
}
void Country::setPrimaryCulture(std::string primaryCultur) {
    this->primaryCulture = primaryCultur;
}
void Country::setReligion(std::string religion) {
    this->religion = religion;
}
void Country::addRival(std::string rival) {
    this->rival.push_back(rival);
}
void Country::addOwnedProvince(int ownedProvince) {
    this->ownedProvince.push_back(ownedProvince);
}
void Country::addPowers(int powers) {
    this->powers.push_back(powers);
}

void Country::addEsates(Estates estates) {
    this->_estates.push_back(estates);
}
void Country::addActiveIdeaGroup(ActiveIdeaGroup activeIdeaGroup) {
    this->_activeIdeaGroup.push_back(activeIdeaGroup);
}

std::string Country::getTag() {
    return this->tag;
}
std::string Country::getPrimaryCulture() {
    return this->primaryCulture;
}
std::string Country::getReligion() {
    return this->religion;
}
std::vector<std::string> Country::getRival() {
    return this->rival;
}
std::vector<int> Country::getOwnedProvince() {
    return this->ownedProvince;
}
std::vector<int> Country::getPowers() {
    return this->powers;
}

std::vector<Estates> Country::getEstates() {
    return this->_estates;
}
std::vector<ActiveIdeaGroup> Country::getActiveIdeaGroup() {
    return this->_activeIdeaGroup;
}
Government Country::getGovernment() {
    return this->_government;
}
StateViews Country::getStateViews() {
    return this->_stateViews;
}
Colors Country::getColors() {
    return this->_colors;
}
Technology Country::getTechnology() {
    return this->_technology;
}

void Country::setColor(Colors colors) {
    this->_colors = colors;
}
void Country::setStateViews(StateViews stateViews) {
    this->_stateViews = stateViews;
}
void Country::setTechnology(Technology technology) {
    this->_technology = technology;
}
void Country::setGovernment(Government government) {
    this->_government = government;
}

void Country::setActiveIdeaGroup(std::vector<ActiveIdeaGroup> idea) {
    this->_activeIdeaGroup = idea;
}

void Country::setEstates(std::vector<Estates> newE) {
    this->_estates = newE;
}

void Country::setRival(std::vector<std::string> rival) {
    this->rival = rival;
}