#include "../include/ActiveIdeaGroup.hpp"

using namespace teuton::parser;

ActiveIdeaGroup::ActiveIdeaGroup() {}
ActiveIdeaGroup::~ActiveIdeaGroup() {}

void ActiveIdeaGroup::setIdeaName(std::string ideaName) {
    this->ideaName = ideaName;
}
void ActiveIdeaGroup::setIdeaLevel(int level) {
    this->ideaLevel = level;
}

std::string ActiveIdeaGroup::getIdeaName() {
    return this->ideaName;
}
int ActiveIdeaGroup::getIdeaLevel() {
    return this->ideaLevel;
}