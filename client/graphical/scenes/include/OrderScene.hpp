/*
** EPITECH PROJECT, 2020
** teuton
** File description:
** TODO: add description
*/

#ifndef TEUTON_ORDERSCENE_HPP
#define TEUTON_ORDERSCENE_HPP

#include "IScene.hpp"
#include "../include/infoFile.hpp"
#include "../include/Widget.hpp"
#include "../include/DialogBox.hpp"
#include "../include/Label.hpp"
#include "../include/LineEdit.hpp"
#include "../include/QButton.hpp"
#include "../include/IWidgets.hpp"
#include "../include/Estates.hpp"
#include "../include/Country.hpp"
#include <map>
#include <vector>
#include <QWidget>

namespace teuton::graphical
{
    class OrderScene: public IScene {
        public:
            OrderScene(std::string, std::vector<teuton::parser::Estates>,teuton::parser::Country);
            ~OrderScene();
            std::vector<QWidget*> getWidgets() override;
            void setVisible(bool) override;
            QButton* getReturn();
            std::vector<teuton::parser::Estates> getNewInfo();

            void burghers();
            void nobles();
            void clergy();
            void connectBurghers();
            void connectNobles();
            void connectClergy();

            void newPrivilegies(std::vector<std::string>,int);
            void rWrite(int);

            Label *bas;

            QButton *b1;
            QButton *b2;
            QButton *b3;
            QButton *b4;

            QButton *n1;
            QButton *n2;
            QButton *n3;
            QButton *n4;

            QButton *c1;
            QButton *c2;
            QButton *c3;
            QButton *c4;

            std::vector<QButton*> nP;
            int nPi = 0;
            int bt;

            Widget *newPrivilegie;
            std::string toR;

            std::vector<std::string> allNobles;
            std::vector<std::string> allChurch;
            std::vector<std::string> allBurghers;
            std::vector<std::string> noblesPrivilegies;
            std::vector<std::string> burghersPrivilegies;
            std::vector<std::string> clericalPrivilegies;

        private:

            Label *name;
            Label *haut;
            Label *middle;

            QButton *_Return;
            Widget *_OrderScene;
            std::vector<QWidget*> _local;
            std::vector<teuton::parser::Estates> estates;
            teuton::parser::Country country;
    };
}

#endif //TEUTON_scene_HPP
