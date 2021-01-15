#include "../include/Idea.hpp"

using namespace teuton::graphical;

Idea::Idea(int lvl) {
    this->lvl = lvl;
}
Idea::~Idea() {
    
}
void Idea::setLvl(int lvl) {
    this->lvl = lvl;
}
int Idea::getLvl() {
    return lvl;
}