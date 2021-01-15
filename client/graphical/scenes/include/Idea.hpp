/*
** EPITECH PROJECT, 2020
** teuton
** File description:
** TODO: add description
*/

#ifndef TEUTON_IDEA_HPP
#define TEUTON_IDEA_HPP

#include "IScene.hpp"
#include "../include/infoFile.hpp"
#include "../include/Widget.hpp"
#include "../include/DialogBox.hpp"
#include "../include/Label.hpp"
#include "../include/LineEdit.hpp"
#include "../include/QButton.hpp"
#include "../include/IWidgets.hpp"
#include "../include/Technology.hpp"
#include "../include/ActiveIdeaGroup.hpp"
#include <map>
#include <vector>
#include <QWidget>

namespace teuton::graphical
{
    class Idea {
        public:
            Idea(int);
            ~Idea();
            void setLvl(int);
            int getLvl();
        private:
            int lvl;
    };
}

#endif //TEUTON_scene_HPP