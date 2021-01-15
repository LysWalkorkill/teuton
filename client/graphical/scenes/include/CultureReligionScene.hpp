/*
** EPITECH PROJECT, 2020
** teuton
** File description:
** TODO: add description
*/

#ifndef TEUTON_CULTURERELIGIONSCENE_HPP
#define TEUTON_CULTURERELIGIONSCENE_HPP

#include "IScene.hpp"
#include "../include/infoFile.hpp"
#include "../include/Widget.hpp"
#include "../include/DialogBox.hpp"
#include "../include/Label.hpp"
#include "../include/LineEdit.hpp"
#include "../include/QButton.hpp"
#include "../include/IWidgets.hpp"
#include "../include/Country.hpp"
#include "../include/infoFile.hpp"
#include <map>
#include <vector>
#include <QWidget>

namespace teuton::graphical
{
    class CultureReligionScene: public IScene {
        public:
            CultureReligionScene(std::string, teuton::parser::Country);
            ~CultureReligionScene();
            std::vector<QWidget*> getWidgets() override;
            void setVisible(bool) override;
            QButton* getReturn();
            teuton::parser::Country getNewInfo();
            void setNewInfo(teuton::parser::Country);
            void cSearchMostProbable(std::string);
            void rSearchMostProbable(std::string);

            QButton *_cp1;
            QButton *_cp2;
            QButton *_cp3;
            QButton *_cp4;
            QButton *_cp5;
            QButton *_cp6;
            QButton *_cp7;
            QButton *_cp8;
            QButton *_cp9;
            QButton *_cp10;
            QButton *_rp1;
            QButton *_rp2;
            QButton *_rp3;
            QButton *_rp4;
            QButton *_rp5;
            QButton *_rp6;
            QButton *_rp7;
            QButton *_rp8;
            QButton *_rp9;
            QButton *_rp10;
            std::vector<QButton*> rB;
            std::vector<QButton*> cB;
            QButton *_Csearch;
            QButton *_Rsearch;
            LineEdit *_r;
            LineEdit *_c;
            Label *tReligion;
            Label *tCulture;
        private:

            QButton *_Return;
            Widget *_CultureReligionScene;
            std::vector<QWidget*> _local;
            teuton::parser::Country country;
            Label *_religion;
            Label *_culture;
            Label *name;
            Label *haut;
            Label *middle;
            Label *bas;
            Label *cut;
            teuton::parser::infoFile *infoC;
            teuton::parser::infoFile *infoR;
            std::vector<std::string> cSave;
            std::vector<std::string> rSave;

            void connect();

    };
}

#endif //TEUTON_scene_HPP
