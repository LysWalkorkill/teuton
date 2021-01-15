/*
** EPITECH PROJECT, 2020
** teuton
** File description:
** TODO: add description
*/

#ifndef TEUTON_COUNTRYSCENE_HPP
#define TEUTON_COUNTRYSCENE_HPP

#include "IScene.hpp"
#include "../include/infoFile.hpp"
#include "../include/Widget.hpp"
#include "../include/DialogBox.hpp"
#include "../include/Label.hpp"
#include "../include/LineEdit.hpp"
#include "../include/QButton.hpp"
#include "../include/IWidgets.hpp"
#include "../include/Country.hpp"
//#include "../include/Write.hpp"
#include <map>
#include <vector>
#include <QWidget>
#include "ColorsScene.hpp"
#include "CultureReligionScene.hpp"
#include "OrderScene.hpp"
#include "ProvincesScene.hpp"
#include "StateViewsScene.hpp"
#include "TechIdeaScene.hpp"
#include "GovernmentScene.hpp"
#include "HomeScene.hpp"

namespace teuton::graphical
{
    enum SCENE {
        COLORS = 0,
        CULTURERELIGION = 1,
        ORDER = 2,
        PROVINCE = 3,
        STATEVIEWS = 4,
        TECHIDEA = 5,
        GOVERNEMENT = 6,
        COUNTRY = 7
    };
    class CountryScene: public IScene {
        public:
            CountryScene(std::string, HomeScene*, teuton::parser::Country, std::vector<teuton::parser::Province>, std::vector<std::string> tag);
            ~CountryScene();
            std::vector<QWidget*> getWidgets() override;
            teuton::parser::Country getNewCountry();
            std::vector<teuton::parser::Province> getNewProvince();
            void setVisible(bool) override;
            void hideScene(SCENE);
            void setScene(SCENE);
            void endW();
            void hideAll();

            ColorsScene *_colors;
            CultureReligionScene *_culturReligion;
            OrderScene *_order;
            ProvincesScene *_provinces;
            StateViewsScene *_stateViews;
            TechIdeaScene *_techIdea;
            GovernementScene *_government;
            teuton::parser::Country country;
            std::vector<teuton::parser::Province> province;
            QButton *_saveQuit;
            QButton *_Return;
            Widget *_CountryScene;
        private:

            void startSceneColors();
            void startSceneCultureReligion();
            void startSceneOrder();
            void startSceneProvince();
            void startSceneStateViews();
            void startSceneTechIdea();
            void startSceneGovernement();

            void connectSceneColors();
            void connectSceneCultureReligion();
            void connectSceneOrder();
            void connectSceneProvince();
            void connectSceneStateViews();
            void connectSceneTechIdea();
            void connectSceneGovernement();

            QButton *_gov;
            QButton *_tIdea;
            QButton *_ord;
            QButton *_stViews;
            QButton *_col;
            QButton *_pro;
            QButton *_culReligion;
            std::vector<QWidget*> _local;
            HomeScene *_home;
            std::string _tag;
            std::vector<std::string> tag;
    };
}

#endif //TEUTON_scene_HPP
