/*
** EPITECH PROJECT, 2020
** teuton
** File description:
** TODO: add description
*/

#ifndef TEUTON_OTECH_HPP
#define TEUTON_OTECH_HPP

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
#include "../include/Idea.hpp"
#include <map>
#include <vector>
#include <QWidget>

namespace teuton::graphical
{
    class OTech {
        public:
            OTech(std::string, int, Label*);
            ~OTech();
            void setLvl(int);
            void setName(std::string);
            void access(bool, int);
            void setLabel(int, int, int, int);
            int getLvl();
            std::string getName();
            void reset();
            void connect();

            QButton *b1;
            QButton *b2;
            QButton *b3;
            QButton *b4;
            QButton *b5;
            QButton *b6;
            QButton *b7;

            QButton *deleteIdea;

            QButton *newIdea; //todo
            
            Label *idea;

            int x;
            int y;
            int w;
            int h;
            Idea *lvl;
            bool acces;
            std::string name;
            Label *scene;
            int tech;
        private:
    };
}

#endif //TEUTON_scene_HPP