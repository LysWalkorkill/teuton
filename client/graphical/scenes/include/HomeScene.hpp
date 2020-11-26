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
            HomeScene();
            ~HomeScene();
            std::vector<QWidget*> getWidgets() override;

        private:
            std::map<std::string, int> _Widgets;
            std::vector<QWidget*> _local;

    };
}

#endif //TEUTON_scene_HPP
