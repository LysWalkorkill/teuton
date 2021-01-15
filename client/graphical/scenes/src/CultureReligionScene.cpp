#include "../include/CultureReligionScene.hpp"

using namespace teuton::graphical;

CultureReligionScene::CultureReligionScene(std::string name, teuton::parser::Country government) {
    this->_CultureReligionScene = new Widget;
    this->country = government;
    this->_CultureReligionScene->setSize(500, 600);
    this->_CultureReligionScene->setTransparentBackground(false);

    this->haut = new Label(*_CultureReligionScene->getWidgets());
    this->haut->setSize(500, 50);
    this->name = new Label(*haut->getWidgets());
    this->name->move(200, 22);
    this->name->setText("Culture & Religion");
    this->_Return = new QButton(*haut->getWidgets());
    this->_Return->move(0,0);
    this->_Return->setSize(50, 50);
    this->_Return->setText("back");
    this->haut->setStyleSheet("background-color: red");
    this->_Return->setStyleSheet("background-color: grey");
    this->middle = new Label(*_CultureReligionScene->getWidgets());
    this->middle->move(0, 50);
    this->middle->setSize(500, 100);
    this->middle->setStyleSheet("background-color: green");
    this->bas = new Label(*_CultureReligionScene->getWidgets());
    this->bas->move(0, 150);
    this->bas->setSize(500, 450);
    this->cut = new Label(*bas->getWidgets());
    this->cut->setStyleSheet("background-color: green");
    this->cut->setSize(2, 450);
    this->cut->move(249, 0);
    this->_r = new LineEdit(*bas->getWidgets());
    this->_c = new LineEdit(*bas->getWidgets());
    this->_Csearch = new QButton(*bas->getWidgets());
    this->_Rsearch = new QButton(*bas->getWidgets());

    this->_culture = new Label(*middle->getWidgets());
    this->_religion = new Label(*middle->getWidgets());
    this->_culture->move(20,20);
    this->_culture->setSize(230, 20);
    this->_culture->setText("Culture");
    this->_religion->move(270,20);
    this->_religion->setSize(230, 20);
    this->_religion->setText("Religion");
    this->tCulture = new Label(*middle->getWidgets());
    this->tReligion = new Label(*middle->getWidgets());
    this->tCulture->move(20, 50);
    this->tCulture->setSize(100, 20);
    this->tReligion->move(270, 50);
    this->tReligion->setSize(100, 20);
    this->tCulture->setText(country.getPrimaryCulture());
    this->tReligion->setText(country.getReligion());

    this->_Rsearch->move(430, 10);
    this->_Rsearch->setSize(50, 34);
    this->_Rsearch->setText("search");
    this->_Csearch->move(190, 10);
    this->_Csearch->setSize(50, 34);
    this->_Csearch->setText("search");
    this->_r->setSize(160, 34);
    this->_r->move(260, 10);
    this->_c->setSize(160, 34);
    this->_c->move(20, 10);

    infoC = new teuton::parser::infoFile("../client/graphical/scenes/ressources/cultureList.txt");
    infoR = new teuton::parser::infoFile("../client/graphical/scenes/ressources/religionList.txt");
    infoC->isWorking();
    infoR->isWorking();
    cSave = infoC->getSave();
    rSave = infoR->getSave();
    for (int i = 0; (size_t)i < cSave.size(); i++){
        int y = 0;
        int o = 0;
        for (; y != 1; o++)
            if (cSave.at(i).at(o) == ' ')
                y++;
        cSave.at(i) = cSave.at(i).substr(0, o - 5);
    }


    _cp1 = new QButton(*bas->getWidgets());
    _cp1->setText(cSave.at(0));
    _cp2 = new QButton(*bas->getWidgets());
    _cp2->setText(cSave.at(1));
    _cp3 = new QButton(*bas->getWidgets());
    _cp3->setText(cSave.at(2));
    _cp4 = new QButton(*bas->getWidgets());
    _cp4->setText(cSave.at(3));
    _cp5 = new QButton(*bas->getWidgets());
    _cp5->setText(cSave.at(4));
    _cp6 = new QButton(*bas->getWidgets());
    _cp6->setText(cSave.at(5));
    _cp7 = new QButton(*bas->getWidgets());
    _cp7->setText(cSave.at(6));
    _cp8 = new QButton(*bas->getWidgets());
    _cp8->setText(cSave.at(7));
    _cp9 = new QButton(*bas->getWidgets());
    _cp9->setText(cSave.at(8));
    _cp10 = new QButton(*bas->getWidgets());
    _cp10->setText(cSave.at(9));
    _rp1 = new QButton(*bas->getWidgets());
    _rp1->setText(rSave.at(0));
    _rp2 = new QButton(*bas->getWidgets());
    _rp2->setText(rSave.at(1));
    _rp3 = new QButton(*bas->getWidgets());
    _rp2->setText(rSave.at(2));
    _rp4 = new QButton(*bas->getWidgets());
    _rp4->setText(rSave.at(3));
    _rp5 = new QButton(*bas->getWidgets());
    _rp5->setText(rSave.at(4));
    _rp6 = new QButton(*bas->getWidgets());
    _rp6->setText(rSave.at(5));
    _rp7 = new QButton(*bas->getWidgets());
    _rp7->setText(rSave.at(6));
    _rp8 = new QButton(*bas->getWidgets());
    _rp8->setText(rSave.at(7));
    _rp9 = new QButton(*bas->getWidgets());
    _rp9->setText(rSave.at(8));
    _rp10 = new QButton(*bas->getWidgets());
    _rp10->setText(rSave.at(9));

    _cp1->setSize(100, 60);
    _cp2->setSize(100, 60);
    _cp3->setSize(100, 60);
    _cp4->setSize(100, 60);
    _cp5->setSize(100, 60);
    _cp6->setSize(100, 60);
    _cp7->setSize(100, 60);
    _cp8->setSize(100, 60);
    _cp9->setSize(100, 60);
    _cp10->setSize(100, 60);
    _rp1->setSize(100, 60);
    _rp2->setSize(100, 60);
    _rp3->setSize(100, 60);
    _rp4->setSize(100, 60);
    _rp5->setSize(100, 60);
    _rp6->setSize(100, 60);
    _rp7->setSize(100, 60);
    _rp8->setSize(100, 60);
    _rp9->setSize(100, 60);
    _rp10->setSize(100, 60);

    _cp1->move(20, 70);
    _cp2->move(20, 140);
    _cp3->move(20, 210);
    _cp4->move(20, 280);
    _cp5->move(20, 350);
    _cp6->move(140, 70);
    _cp7->move(140, 140);
    _cp8->move(140, 210);
    _cp9->move(140, 280);
    _cp10->move(140, 350);
    _rp1->move(260, 70);
    _rp2->move(260, 140);
    _rp3->move(260, 210);
    _rp4->move(260, 280);
    _rp5->move(260, 350);
    _rp6->move(380, 70);
    _rp7->move(380, 140);
    _rp8->move(380, 210);
    _rp9->move(380, 280);
    _rp10->move(380, 350);

    rB.push_back(_rp1);
    rB.push_back(_rp2);
    rB.push_back(_rp3);
    rB.push_back(_rp4);
    rB.push_back(_rp5);
    rB.push_back(_rp6);
    rB.push_back(_rp7);
    rB.push_back(_rp8);
    rB.push_back(_rp9);
    rB.push_back(_rp10);
    cB.push_back(_cp1);
    cB.push_back(_cp2);
    cB.push_back(_cp3);
    cB.push_back(_cp4);
    cB.push_back(_cp5);
    cB.push_back(_cp6);
    cB.push_back(_cp7);
    cB.push_back(_cp8);
    cB.push_back(_cp9);
    cB.push_back(_cp10);

    this->_Csearch->connect([this](){
        cSearchMostProbable(this->_c->getTxt());
    });
    this->_Rsearch->connect([this](){
        rSearchMostProbable(this->_r->getTxt());
    });

    this->connect();
}

CultureReligionScene::~CultureReligionScene() {} 

void CultureReligionScene::connect() {
    this->_cp1->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setPrimaryCulture(_cp1->getText());
        this->setNewInfo(tst);
        this->tCulture->setText(_cp1->getText());
    });
    this->_cp2->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setPrimaryCulture(_cp2->getText());
        this->setNewInfo(tst);
        this->tCulture->setText(_cp2->getText());
    });
    this->_cp3->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setPrimaryCulture(_cp3->getText());
        this->setNewInfo(tst);
        this->tCulture->setText(_cp3->getText());
    });
    this->_cp4->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setPrimaryCulture(_cp4->getText());
        this->setNewInfo(tst);
        this->tCulture->setText(_cp4->getText());
    });
    this->_cp5->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setPrimaryCulture(_cp5->getText());
        this->setNewInfo(tst);
        this->tCulture->setText(_cp5->getText());
    });
    this->_cp6->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setPrimaryCulture(_cp6->getText());
        this->setNewInfo(tst);
        this->tCulture->setText(_cp6->getText());
    });
    this->_cp7->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setPrimaryCulture(_cp7->getText());
        this->setNewInfo(tst);
        this->tCulture->setText(_cp7->getText());
    });
    this->_cp8->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setPrimaryCulture(_cp8->getText());
        this->setNewInfo(tst);
        this->tCulture->setText(_cp8->getText());
    });
    this->_cp9->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setPrimaryCulture(_cp9->getText());
        this->setNewInfo(tst);
        this->tCulture->setText(_cp9->getText());
    });
    this->_cp10->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setPrimaryCulture(_cp10->getText());
        this->setNewInfo(tst);
        this->tCulture->setText(_cp10->getText());
    });

    this->_rp1->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setReligion(_rp1->getText());
        this->setNewInfo(tst);
        this->tReligion->setText(_rp1->getText());
    });
    this->_rp2->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setReligion(_rp2->getText());
        this->setNewInfo(tst);
        this->tReligion->setText(_rp2->getText());
    });
    this->_rp3->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setReligion(_rp3->getText());
        this->setNewInfo(tst);
        this->tReligion->setText(_rp3->getText());
    });
    this->_rp4->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setReligion(_rp4->getText());
        this->setNewInfo(tst);
        this->tReligion->setText(_rp4->getText());
    });
    this->_rp5->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setReligion(_rp5->getText());
        this->setNewInfo(tst);
        this->tReligion->setText(_rp5->getText());
    });
    this->_rp6->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setReligion(_rp6->getText());
        this->setNewInfo(tst);
        this->tReligion->setText(_rp6->getText());
    });
    this->_rp7->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setReligion(_rp7->getText());
        this->setNewInfo(tst);
        this->tReligion->setText(_rp7->getText());
    });
    this->_rp8->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setReligion(_rp8->getText());
        this->setNewInfo(tst);
        this->tReligion->setText(_rp8->getText());
    });
    this->_rp9->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setReligion(_rp9->getText());
        this->setNewInfo(tst);
        this->tCulture->setText(_rp9->getText());
    });
    this->_rp10->connect([this](){
        teuton::parser::Country tst = this->getNewInfo();
        tst.setReligion(_rp10->getText());
        this->setNewInfo(tst);
        this->tReligion->setText(_rp10->getText());
    });
}

void CultureReligionScene::cSearchMostProbable(std::string name) {
    std::vector<std::string> sl;
    bool good;

    for (int o = 0; name.size() > 0; o++) {
        good = true;
        for (int i = 0; (size_t)i < cSave.size(); i++) {
            if (name == cSave.at(i).substr(0, name.size())) {
                for (int y = 0; (size_t)y < sl.size(); y++)
                    if (sl.at(y) == cSave.at(i))
                        good = false;
                if (good) {
                    sl.push_back(cSave.at(i));
                }
            }
        }
        name = name.substr(0, name.size() - 1);
    }
    int y = 10 - sl.size();
    for (int i = 0; (size_t)i < sl.size() && i < 10; i++)
        cB.at(i)->setText(sl.at(i));
    for (; y != 0 && y > 0; y--)
        cB.at(10 - y)->setText(cSave.at(10 + y));
}

void CultureReligionScene::rSearchMostProbable(std::string name) {
    std::vector<std::string> sl;
    bool good;

    for (int o = 0; name.size() > 0; o++) {
        good = true;
        for (int i = 0; (size_t)i < rSave.size(); i++) {
            if (name == rSave.at(i).substr(0, name.size())) {
                for (int y = 0; (size_t)y < sl.size(); y++)
                    if (sl.at(y) == rSave.at(i))
                        good = false;
                if (good)
                    sl.push_back(rSave.at(i));
            }
        }
        name = name.substr(0, name.size() - 1);
    }
    int y = 10 - sl.size();
    for (int i = 0; (size_t)i < sl.size() && i < 10; i++)
        rB.at(i)->setText(sl.at(i));
    for (; y != 0 && y > 0; y--)
        rB.at(10 - y)->setText(rSave.at(10 + y));
}

void CultureReligionScene::setVisible(bool show) {
    this->_CultureReligionScene->show(show);
}

std::vector<QWidget*> CultureReligionScene::getWidgets() {
    return this->_local;
}

teuton::parser::Country CultureReligionScene::getNewInfo() {
    return this->country;
}

void CultureReligionScene::setNewInfo(teuton::parser::Country nnew) {
    this->country = nnew;
}

QButton* CultureReligionScene::getReturn() {
    return this->_Return;
}