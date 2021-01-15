/*
** EPITECH PROJECT, 2020
** teuton
** File description:
** TODO: add description
*/

#ifndef TEUTON_SCENE_HPP
#define TEUTON_SCENE_HPP

#include "HomeScene.hpp"
#include "CountryScene.hpp"
#include "../include/infoFile.hpp"
#include "../include/Widget.hpp"
#include "../include/DialogBox.hpp"
#include "../include/Label.hpp"
#include "../include/LineEdit.hpp"
#include "../include/QButton.hpp"
#include "../include/IWidgets.hpp"
#include "../include/Country.hpp"
#include "../include/Province.hpp"
#include "../../../parser/write/include/Write.hpp"
#include <map>
#include <QPushButton>
#include <QApplication>
#include <QObject>
#include <QPainter>
#include <QWidget>
#include <QPaintDevice>
#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/QGLPixelBuffer>
#include <iostream>
#include <vector>

namespace teuton::graphical
{
    class Scene {
        public:
            Scene(std::vector<teuton::parser::Country>, std::vector<teuton::parser::Province>, std::string, std::vector<std::string>);
            ~Scene();
            void setScene(std::string, std::string);
            void endSave();
            void startSceneHome();

            teuton::parser::Country choosedC;
            CountryScene *_Country;
            std::vector<teuton::parser::Province> province;
            std::vector<std::string> tagList;

            QButton *goExit;
            bool end = true;

        private:
            void startSceneCountry(std::string);
            void connectHome();

            std::vector<teuton::parser::Country> country;
            std::vector<std::string> _tag;

            HomeScene *_Home;
            std::string path;
            std::vector<std::string> save;

    };
}

#endif //TEUTON_scene_HPP