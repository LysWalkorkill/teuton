/*
** EPITECH PROJECT, 2020
** teuton
** File description:
** TODO: add description
*/

#ifndef TEUTON_GOVERNMENTSCENE_HPP
#define TEUTON_GOVERNMENTSCENE_HPP

#include "IScene.hpp"
#include "../include/infoFile.hpp"
#include "../include/Widget.hpp"
#include "../include/DialogBox.hpp"
#include "../include/Label.hpp"
#include "../include/LineEdit.hpp"
#include "../include/QButton.hpp"
#include "../include/IWidgets.hpp"
#include "../include/Government.hpp"
#include <map>
#include <vector>
#include <QWidget>

namespace teuton::graphical
{
    struct tier {
        QButton *bt;
        Label *lb;
        std::string refrom;
    };
    class GovernementScene: public IScene {
        public:
            GovernementScene(std::string, teuton::parser::Government);
            ~GovernementScene();
            std::vector<QWidget*> getWidgets() override;
            void setVisible(bool) override;
            QButton* getReturn();
            teuton::parser::Government getNewInfo();
            void setNewInfo(teuton::parser::Government);
            void reset();

            DialogBox *dGName;
            DialogBox *dG;

            Label *gRank;
            QButton *gRankUp;
            QButton *gRankDown;
            QButton *gName;
            QButton *g;
            Label *Name;
            Label *haut;
            Label *middle;
            Label *bas;
            std::vector<tier> tier1;
            std::vector<tier> tier2;
            std::vector<tier> tier3;
            std::vector<tier> tier4;
            std::vector<tier> tier5;
            teuton::parser::Government government;

        private:
            void connect();
           // void addButtonTier(std::string, int);

            QButton *_Return;
            Widget *_GovernementScene;
            std::vector<QWidget*> _local;

    };
}

#endif //TEUTON_scene_HPP
