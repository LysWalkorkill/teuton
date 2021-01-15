/*
** EPITECH PROJECT, 2020
** teuton
** File description:
** TODO: add description
*/

#ifndef TEUTON_PROVINCESCENE_HPP
#define TEUTON_PROVINCESCENE_HPP

#include "IScene.hpp"
#include "../include/infoFile.hpp"
#include "../include/Widget.hpp"
#include "../include/DialogBox.hpp"
#include "../include/Label.hpp"
#include "../include/LineEdit.hpp"
#include "../include/QButton.hpp"
#include "../include/IWidgets.hpp"
#include "../include/Province.hpp"
#include "../include/Country.hpp"
#include <map>
#include <vector>
#include <QWidget>

namespace teuton::graphical
{
    class ProvincesScene: public IScene {
        public:
            ProvincesScene(std::string, teuton::parser::Country, std::vector<teuton::parser::Province>);
            ~ProvincesScene();
            std::vector<QWidget*> getWidgets() override;
            void setVisible(bool) override;
            QButton* getReturn();
            std::vector<teuton::parser::Province> getNewInfo();
            void connect();
            void reset();


            LineEdit *searchId;
            QButton *search;
            QButton *milD;
            QButton *dipD;
            QButton *admD;
            QButton *prevP;
            QButton *newtP;
            Label *nameC;
            Label *IDC;

            std::vector<teuton::parser::Province> provinceList;
            int actPage;
            std::vector<int> provinceID;
            int maxPage;
            std::vector<std::string> provinceName;
            std::vector<Label*> infoD;

        private:

            Label *name;
            Label *haut;
            Label *middle;
            Label *bas;

            Label *choosedName;
            Label *chooseId;
            Label *nameP;
            Label *idP;
            Label *milP;
            Label *dipP;
            Label *admP;
            Label *nameP2;
            Label *idP2;
            Label *milP2;
            Label *dipP2;
            Label *admP2;

            teuton::parser::infoFile *infoP;
            QButton *_Return;
            Widget *_ProvincesScene;
            std::vector<QWidget*> _local;
            std::vector<teuton::parser::Province> province;
            teuton::parser::Country country;
    };
}

#endif //TEUTON_scene_HPP
