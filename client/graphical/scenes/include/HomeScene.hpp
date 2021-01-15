/*
** EPITECH PROJECT, 2020
** teuton
** File description:
** TODO: add description
*/

#ifndef TEUTON_HOMESCENE_HPP
#define TEUTON_HOMESCENE_HPP

#include "IScene.hpp"
#include "../include/infoFile.hpp"
#include "../include/Widget.hpp"
#include "../include/DialogBox.hpp"
#include "../include/Label.hpp"
#include "../include/LineEdit.hpp"
#include "../include/QButton.hpp"
#include "../include/IWidgets.hpp"
#include <map>
#include <vector>
#include <QWidget>

namespace teuton::graphical
{
    class HomeScene: public IScene {
        public:
            HomeScene(std::vector<std::string>);
            ~HomeScene();
            std::vector<QWidget*> getWidgets() override;
            void setVisible(bool) override;
            std::vector<QButton*> getCp();
            std::string cp1Acces();
            std::string cp2Acces();
            std::string cp3Acces();
            std::string cp4Acces();
            std::string cp5Acces();
            std::string cp6Acces();
            std::string cp7Acces();
            std::string cp8Acces();

        private:
            void searchAcces();
            void mostProbableCountry(std::vector<std::string>, std::string);

            Widget *_homeScene;
            LineEdit *_ledger;
            std::vector<QButton*> _cp;
            QButton *_cp1;
            QButton *_cp2;
            QButton *_cp3;
            QButton *_cp4;
            QButton *_cp5;
            QButton *_cp6;
            QButton *_cp7;
            QButton *_cp8;
            QButton *_search;
            std::string _look;
            std::vector<std::string> _tag;
            std::map<std::string, int> _Widgets;
            std::vector<QWidget*> _local;
            std::string _toSearch;

    };
}

#endif //TEUTON_scene_HPP
