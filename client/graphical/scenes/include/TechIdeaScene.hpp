/*
** EPITECH PROJECT, 2020
** teuton
** File description:
** TODO: add description
*/

#ifndef TEUTON_TECHIDEASCENE_HPP
#define TEUTON_TECHIDEASCENE_HPP

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
#include "../include/OTech.hpp"
#include "../include/infoFile.hpp"
#include <map>
#include <vector>
#include <QWidget>

namespace teuton::graphical
{
    class TechIdeaScene: public IScene {
        public:
            TechIdeaScene(std::string, teuton::parser::Technology, std::vector<teuton::parser::ActiveIdeaGroup>);
            ~TechIdeaScene();
            std::vector<QWidget*> getWidgets() override;
            void setVisible(bool) override;
            QButton* getReturn();
            teuton::parser::Technology getNewInfoTech();
            std::vector<teuton::parser::ActiveIdeaGroup> getNewInfoIdea();
            void connectOTech(OTech&, int);
            void newIdea(OTech&, int);

            QButton *admTech;
            QButton *dipTech;
            QButton *milTech;
            QButton *changeTG;
            std::vector<std::string> techGroup;
            std::vector<QButton*> vecTech;
            Widget *newTechGroup;
            std::vector<OTech> _tech;
            std::vector<teuton::parser::ActiveIdeaGroup> activeIdeaGroup;
            teuton::parser::Technology technology;
        private:

            Label *name;
            Label *haut;
            Label *middle;
            Label *bas;

            QButton *_Return;
            Widget *_TechIdeaScene;
            std::vector<QWidget*> _local;
    };
}

#endif //TEUTON_scene_HPP
