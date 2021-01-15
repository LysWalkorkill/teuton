/*
** EPITECH PROJECT, 2020
** teuton
** File description:
** TODO: add description
*/

#ifndef TEUTON_ISCENE_HPP
#define TEUTON_ISCENE_HPP

#include "../include/IWidgets.hpp"
#include <vector>
#include <QWidget>

namespace teuton::graphical
{
    class IScene {

        public:
            virtual std::vector<QWidget*> getWidgets() = 0;
            virtual void setVisible(bool) = 0;

    };
}

#endif //TEUTON_scene_HPP
