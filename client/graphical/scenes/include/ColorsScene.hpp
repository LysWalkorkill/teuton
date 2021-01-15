/*
** EPITECH PROJECT, 2020
** teuton
** File description:
** TODO: add description
*/

#ifndef TEUTON_COLORSSCENE_HPP
#define TEUTON_COLORSSCENE_HPP

#include "IScene.hpp"
#include "../include/infoFile.hpp"
#include "../include/Widget.hpp"
#include "../include/DialogBox.hpp"
#include "../include/Label.hpp"
#include "../include/LineEdit.hpp"
#include "../include/QButton.hpp"
#include "../include/IWidgets.hpp"
#include "../include/Colors.hpp"
#include <map>
#include <vector>
#include <QWidget>

namespace teuton::graphical
{
    class ColorsScene: public IScene {
        public:
            ColorsScene(std::string, teuton::parser::Colors);
            ~ColorsScene();
            std::vector<QWidget*> getWidgets() override;
            void setVisible(bool) override;
            QButton* getReturn();
            teuton::parser::Colors getNewInfo();
            void setNewInfo(teuton::parser::Colors);
            void connect();
            
            Label *name1;
            Label *name2;
            Label *name3;
            Label *colors1;
            Label *colors2;
            Label *colors3;
            Label *haut;
            Label *middle;
            Label *bas;
            QButton *cC1;
            QButton *cC2;
            QButton *cC3;
            QButton *cC4;
            QButton *cC5;
            QButton *cC6;
            QButton *cC7;
            QButton *cC8;
            QButton *cC9;

        private:

            QButton *_Return;
            Widget *_ColorsScene;
            std::vector<QWidget*> _local;
            teuton::parser::Colors colors;
    };
}

#endif //TEUTON_scene_HPP
