/*
** EPITECH PROJECT, 2020
** teuton
** File description:
** TODO: add description
*/

#ifndef TEUTON_STATEVIEWSSCENE_HPP
#define EUTON_STATEVIEWSSCENE_HPP

#include "IScene.hpp"
#include "../include/infoFile.hpp"
#include "../include/Widget.hpp"
#include "../include/DialogBox.hpp"
#include "../include/Label.hpp"
#include "../include/LineEdit.hpp"
#include "../include/QButton.hpp"
#include "../include/IWidgets.hpp"
#include "../include/StateViews.hpp"
#include <map>
#include <vector>
#include <QWidget>

namespace teuton::graphical
{
    class StateViewsScene: public IScene {
        public:
            StateViewsScene(std::string, teuton::parser::StateViews, std::vector<std::string> rival, std::vector<std::string> tag);
            ~StateViewsScene();
            std::vector<QWidget*> getWidgets() override;
            void setVisible(bool) override;
            QButton* getReturn();
            teuton::parser::StateViews getNewInfo();
            void setNewInfo(teuton::parser::StateViews);
            void connection();
            std::vector<std::string> getRival();
            void mostProbableCountry(std::vector<std::string> tag, std::string name);
            void newRival(int);

            Label *powerProjection;
            Label *prestige;
            Label *stability;
            Label *manpower;
            Label *innovation;
            Label *reformProgress;
            Label *haut;
            Label *middle;
            Label *bas;
            QButton *cC1;
            QButton *cC2;
            QButton *cC3;
            QButton *cC4;
            QButton *cC5;
            QButton *cC6;

            QButton *R1;
            QButton *R2;
            QButton *R3;
            std::vector<QButton*> _R;
            Label *txtR1;
            Label *txtR2;
            Label *txtR3;
            std::vector<QButton*> _cp;
            std::vector<std::string> rival;
            LineEdit *newName;
            QButton *research;
            Label *Pr;
            std::vector<std::string> tag;
            Widget *Rival;

        private:

            QButton *_Return;
            Label *name;
            Widget *_StateViewsScene;
            std::vector<QWidget*> _local;
            teuton::parser::StateViews stateViews;
    };
}

#endif //TEUTON_scene_HPP
