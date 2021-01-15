#include "../include/TechIdeaScene.hpp"

using namespace teuton::graphical;

TechIdeaScene::TechIdeaScene(std::string name, teuton::parser::Technology tech, std::vector<teuton::parser::ActiveIdeaGroup> idea) {
    this->_TechIdeaScene = new Widget;
    this->technology = tech;
    this->activeIdeaGroup = idea;
    this->_Return = new QButton(*_TechIdeaScene->getWidgets());
    this->_Return->move(10,10);
    this->_Return->setSize(50, 50);
    this->_Return->setText("back");

    this->haut = new Label(*_TechIdeaScene->getWidgets());
    this->haut->setSize(500, 50);
    this->name = new Label(*haut->getWidgets());
    this->name->move(200, 22);
    this->name->setText("Tech & Idea");
    this->_Return = new QButton(*haut->getWidgets());
    this->_Return->move(0,0);
    this->_Return->setSize(50, 50);
    this->_Return->setText("back");
    this->haut->setStyleSheet("background-color: red");
    this->_Return->setStyleSheet("background-color: grey");
    this->middle = new Label(*_TechIdeaScene->getWidgets());
    this->middle->move(0, 50);
    this->middle->setSize(500, 100);
    this->middle->setStyleSheet("background-color: green");
    this->bas = new Label(*_TechIdeaScene->getWidgets());
    this->bas->move(0, 150);
    this->bas->setSize(500, 450);

    teuton::parser::infoFile *info = new teuton::parser::infoFile("../client/graphical/scenes/ressources/techGroup.txt");
    info->isWorking();
    this->techGroup = info->getSave();

    Label techGName(*middle->getWidgets());
    techGName.move(300, 25);
    techGName.setText("technological group");
    techGName.show(true);
    changeTG = new QButton(*middle->getWidgets());
    changeTG->move(300, 50);
    changeTG->setSize(150, 25);
    changeTG->setText(this->technology.getTechnologyGroup());
    changeTG->show(true);

    changeTG->connect([this](){
        this->newTechGroup = new Widget;
        this->newTechGroup->show(true);
        this->newTechGroup->setSize(110, 10 + this->techGroup.size() * 25);
        this->newTechGroup->setTransparentBackground(false);
        for (int i = 0; (size_t)i < this->techGroup.size(); i++) {
            QButton *newC = new QButton(*this->newTechGroup->getWidgets());
            newC->show(true);
            newC->move(5, 5 + (25 * i));
            newC->setSize(100, 25);
            newC->setText(this->techGroup.at(i));
            this->vecTech.push_back(newC);
            this->vecTech.at(i)->connect([this, i]() {
                this->changeTG->setText(this->vecTech.at(i)->getText());
                this->newTechGroup->show(false);
            });
        }
    });

    Label techName(*middle->getWidgets());
    techName.move(50, 25);
    techName.setText("technological level");
    techName.show(true);
    admTech = new QButton(*middle->getWidgets());
    dipTech = new QButton(*middle->getWidgets());
    milTech = new QButton(*middle->getWidgets());
    admTech->move(50, 50);
    dipTech->move(100, 50);
    milTech->move(150, 50);
    admTech->setSize(40, 40);
    dipTech->setSize(40, 40);
    milTech->setSize(40, 40);
    admTech->setText(std::to_string(this->technology.getAdmTech()));
    dipTech->setText(std::to_string(this->technology.getDipTech()));
    milTech->setText(std::to_string(this->technology.getMilTech()));
    admTech->show(true);
    dipTech->show(true);
    milTech->show(true);

    admTech->connect([this](){
        DialogBox box("new adm tech", "new value", DialogBox::TEXT, this->admTech->getWidgets());
        int val = std::atoi(box.getText().c_str());
        this->admTech->setText(box.getText());
        this->technology.setAdmTech(std::stoi(this->admTech->getText()));
        for (int i = 0; this->_tech.size() > i ; i++) {
            if (this->_tech.at(i).name == "" && this->_tech.at(i).tech <= std::stoi(this->admTech->getText())) {
                this->_tech.at(i).access(true, std::stoi(this->admTech->getText()));
                this->_tech.at(i).setName("new idea");
                this->_tech.at(i).newIdea->show(true);
                this->_tech.at(i).setLvl(0);
                this->_tech.at(i).reset();
            }
        }
    });
    dipTech->connect([this](){
        DialogBox box("new dip tech", "new value", DialogBox::TEXT, dipTech->getWidgets());
        int val = std::atoi(box.getText().c_str());
        this->dipTech->setText(box.getText());
        this->technology.setDipTech(std::stoi(this->admTech->getText()));
    });
    milTech->connect([this](){
        DialogBox box("new mil tech", "new value", DialogBox::TEXT, this->milTech->getWidgets());
        int val = std::atoi(box.getText().c_str());
        this->milTech->setText(box.getText());
        this->technology.setMilTech(std::stoi(this->admTech->getText()));
    });

    std::vector<int> techNb = {4,7,10,14,18,22,26,29};

    for (int i = 0;i < 8; i++ ) {
        if (i <= 3 && (size_t)i < idea.size()) {
            OTech nTech(idea.at(i).getIdeaName(), idea.at(i).getIdeaLevel(), this->bas);
            nTech.setLabel(5, 5 + i * 110, 240, 100);
            nTech.access(true, techNb.at(i));
            connectOTech(nTech, i);
            this->_tech.push_back(nTech);
        } else if (i <= 3) {
            OTech nTech("", 0, this->bas);
            nTech.setLabel(5, 5 + i * 110, 240, 100);
            nTech.access(false, techNb.at(i));
            connectOTech(nTech, i);
            this->_tech.push_back(nTech);
        } else if (i > 3 && (size_t)i < idea.size()) {
            OTech nTech(idea.at(i).getIdeaName(), idea.at(i).getIdeaLevel(), this->bas);
            nTech.setLabel(255, 5 + (i - 4) * 110, 240, 100);
            nTech.access(true, techNb.at(i));
            connectOTech(nTech, i);
            this->_tech.push_back(nTech);
        } else {
            OTech nTech("", 0, this->bas);
            nTech.setLabel(255, 5 + (i - 4) * 110, 240, 100);
            nTech.access(false, techNb.at(i));
            connectOTech(nTech, i);
            this->_tech.push_back(nTech);
        }

    }
}

void TechIdeaScene::connectOTech(OTech &tech, int nb) {
    tech.b1->connect([tech, nb, this](){
        tech.lvl->setLvl(1);
        this->activeIdeaGroup.at(nb).setIdeaLevel(1);
        for (int i = 0; i <= 1; i++) {
            if (i == 1)
                tech.b1->setStyleSheet("background-color: green");
            if (i == 2)
                tech.b2->setStyleSheet("background-color: green");
            if (i == 3)
                tech.b3->setStyleSheet("background-color: green");
            if (i == 4)
                tech.b4->setStyleSheet("background-color: green");
            if (i == 5)
                tech.b5->setStyleSheet("background-color: green");
            if (i == 6)
                tech.b6->setStyleSheet("background-color: green");
            if (i == 7)
                tech.b7->setStyleSheet("background-color: green");
        }
        for (int i = 1 + 1; i <= 7; i++) {
            if (i == 1)
                tech.b1->setStyleSheet("background-color: red");
            if (i == 2)
                tech.b2->setStyleSheet("background-color: red");
            if (i == 3)
                tech.b3->setStyleSheet("background-color: red");
            if (i == 4)
                tech.b4->setStyleSheet("background-color: red");
            if (i == 5)
                tech.b5->setStyleSheet("background-color: red");
            if (i == 6)
                tech.b6->setStyleSheet("background-color: red");
            if (i == 7)
                tech.b7->setStyleSheet("background-color: red");
        }

    });
    tech.b2->connect([tech, this, nb](){
        this->activeIdeaGroup.at(nb).setIdeaLevel(2);
        tech.lvl->setLvl(2);
        for (int i = 0; i <= 2; i++) {
            if (i == 1)
                tech.b1->setStyleSheet("background-color: green");
            if (i == 2)
                tech.b2->setStyleSheet("background-color: green");
            if (i == 3)
                tech.b3->setStyleSheet("background-color: green");
            if (i == 4)
                tech.b4->setStyleSheet("background-color: green");
            if (i == 5)
                tech.b5->setStyleSheet("background-color: green");
            if (i == 6)
                tech.b6->setStyleSheet("background-color: green");
            if (i == 7)
                tech.b7->setStyleSheet("background-color: green");
        }
        for (int i = 2 + 1; i <= 7; i++) {
            if (i == 1)
                tech.b1->setStyleSheet("background-color: red");
            if (i == 2)
                tech.b2->setStyleSheet("background-color: red");
            if (i == 3)
                tech.b3->setStyleSheet("background-color: red");
            if (i == 4)
                tech.b4->setStyleSheet("background-color: red");
            if (i == 5)
                tech.b5->setStyleSheet("background-color: red");
            if (i == 6)
                tech.b6->setStyleSheet("background-color: red");
            if (i == 7)
                tech.b7->setStyleSheet("background-color: red");
        }
    });
    tech.b3->connect([tech, nb , this](){
        tech.lvl->setLvl(3);
        this->activeIdeaGroup.at(nb).setIdeaLevel(3);
        for (int i = 0; i <= 3; i++) {
            if (i == 1)
                tech.b1->setStyleSheet("background-color: green");
            if (i == 2)
                tech.b2->setStyleSheet("background-color: green");
            if (i == 3)
                tech.b3->setStyleSheet("background-color: green");
            if (i == 4)
                tech.b4->setStyleSheet("background-color: green");
            if (i == 5)
                tech.b5->setStyleSheet("background-color: green");
            if (i == 6)
                tech.b6->setStyleSheet("background-color: green");
            if (i == 7)
                tech.b7->setStyleSheet("background-color: green");
        }
        for (int i = 3 + 1; i <= 7; i++) {
            if (i == 1)
                tech.b1->setStyleSheet("background-color: red");
            if (i == 2)
                tech.b2->setStyleSheet("background-color: red");
            if (i == 3)
                tech.b3->setStyleSheet("background-color: red");
            if (i == 4)
                tech.b4->setStyleSheet("background-color: red");
            if (i == 5)
                tech.b5->setStyleSheet("background-color: red");
            if (i == 6)
                tech.b6->setStyleSheet("background-color: red");
            if (i == 7)
                tech.b7->setStyleSheet("background-color: red");
        }
    });
    tech.b4->connect([tech, this, nb](){
        this->activeIdeaGroup.at(nb).setIdeaLevel(4);
        tech.lvl->setLvl(4);
        for (int i = 0; i <= 4; i++) {
            if (i == 1)
                tech.b1->setStyleSheet("background-color: green");
            if (i == 2)
                tech.b2->setStyleSheet("background-color: green");
            if (i == 3)
                tech.b3->setStyleSheet("background-color: green");
            if (i == 4)
                tech.b4->setStyleSheet("background-color: green");
            if (i == 5)
                tech.b5->setStyleSheet("background-color: green");
            if (i == 6)
                tech.b6->setStyleSheet("background-color: green");
            if (i == 7)
                tech.b7->setStyleSheet("background-color: green");
        }
        for (int i = 4 + 1; i <= 7; i++) {
            if (i == 1)
                tech.b1->setStyleSheet("background-color: red");
            if (i == 2)
                tech.b2->setStyleSheet("background-color: red");
            if (i == 3)
                tech.b3->setStyleSheet("background-color: red");
            if (i == 4)
                tech.b4->setStyleSheet("background-color: red");
            if (i == 5)
                tech.b5->setStyleSheet("background-color: red");
            if (i == 6)
                tech.b6->setStyleSheet("background-color: red");
            if (i == 7)
                tech.b7->setStyleSheet("background-color: red");
        }
    });
    tech.b5->connect([tech, this, nb](){
        this->activeIdeaGroup.at(nb).setIdeaLevel(5);
        tech.lvl->setLvl(5);
        for (int i = 0; i <= 5; i++) {
            if (i == 1)
                tech.b1->setStyleSheet("background-color: green");
            if (i == 2)
                tech.b2->setStyleSheet("background-color: green");
            if (i == 3)
                tech.b3->setStyleSheet("background-color: green");
            if (i == 4)
                tech.b4->setStyleSheet("background-color: green");
            if (i == 5)
                tech.b5->setStyleSheet("background-color: green");
            if (i == 6)
                tech.b6->setStyleSheet("background-color: green");
            if (i == 7)
                tech.b7->setStyleSheet("background-color: green");
        }
        for (int i = 5 + 1; i <= 7; i++) {
            if (i == 1)
                tech.b1->setStyleSheet("background-color: red");
            if (i == 2)
                tech.b2->setStyleSheet("background-color: red");
            if (i == 3)
                tech.b3->setStyleSheet("background-color: red");
            if (i == 4)
                tech.b4->setStyleSheet("background-color: red");
            if (i == 5)
                tech.b5->setStyleSheet("background-color: red");
            if (i == 6)
                tech.b6->setStyleSheet("background-color: red");
            if (i == 7)
                tech.b7->setStyleSheet("background-color: red");
        }
    });
    tech.b6->connect([tech, this ,nb](){
        this->activeIdeaGroup.at(nb).setIdeaLevel(6);
        tech.lvl->setLvl(6);
        for (int i = 0; i <= 6; i++) {
            if (i == 1)
                tech.b1->setStyleSheet("background-color: green");
            if (i == 2)
                tech.b2->setStyleSheet("background-color: green");
            if (i == 3)
                tech.b3->setStyleSheet("background-color: green");
            if (i == 4)
                tech.b4->setStyleSheet("background-color: green");
            if (i == 5)
                tech.b5->setStyleSheet("background-color: green");
            if (i == 6)
                tech.b6->setStyleSheet("background-color: green");
            if (i == 7)
                tech.b7->setStyleSheet("background-color: green");
        }
        for (int i = 6 + 1; i <= 7; i++) {
            if (i == 1)
                tech.b1->setStyleSheet("background-color: red");
            if (i == 2)
                tech.b2->setStyleSheet("background-color: red");
            if (i == 3)
                tech.b3->setStyleSheet("background-color: red");
            if (i == 4)
                tech.b4->setStyleSheet("background-color: red");
            if (i == 5)
                tech.b5->setStyleSheet("background-color: red");
            if (i == 6)
                tech.b6->setStyleSheet("background-color: red");
            if (i == 7)
                tech.b7->setStyleSheet("background-color: red");
        }
    });
    tech.b7->connect([tech, this, nb](){
        this->activeIdeaGroup.at(nb).setIdeaLevel(7);
        tech.lvl->setLvl(7);
        for (int i = 0; i <= 7; i++) {
            if (i == 1)
                tech.b1->setStyleSheet("background-color: green");
            if (i == 2)
                tech.b2->setStyleSheet("background-color: green");
            if (i == 3)
                tech.b3->setStyleSheet("background-color: green");
            if (i == 4)
                tech.b4->setStyleSheet("background-color: green");
            if (i == 5)
                tech.b5->setStyleSheet("background-color: green");
            if (i == 6)
                tech.b6->setStyleSheet("background-color: green");
            if (i == 7)
                tech.b7->setStyleSheet("background-color: green");
        }
        for (int i = 7 + 1; i <= 7; i++) {
            if (i == 1)
                tech.b1->setStyleSheet("background-color: red");
            if (i == 2)
                tech.b2->setStyleSheet("background-color: red");
            if (i == 3)
                tech.b3->setStyleSheet("background-color: red");
            if (i == 4)
                tech.b4->setStyleSheet("background-color: red");
            if (i == 5)
                tech.b5->setStyleSheet("background-color: red");
            if (i == 6)
                tech.b6->setStyleSheet("background-color: red");
            if (i == 7)
                tech.b7->setStyleSheet("background-color: red");
        }
    });
    tech.deleteIdea->connect([tech](){
        tech.newIdea->show(true);
        tech.b1->show(false);
        tech.b2->show(false);
        tech.b3->show(false);
        tech.b4->show(false);
        tech.b5->show(false);
        tech.b6->show(false);
        tech.b7->show(false);
        tech.deleteIdea->show(false);
    });

    tech.newIdea->connect([this, &tech, nb](){
        this->newIdea(tech, nb);
    });
}

TechIdeaScene::~TechIdeaScene() {} 

void TechIdeaScene::newIdea(OTech &actual, int nb) {
    Widget *newIdeaSet = new Widget;
    newIdeaSet->setSize(600, 700);
    newIdeaSet->show(true);
    newIdeaSet->setTransparentBackground(false);
    Label *Pr = new Label(*newIdeaSet->getWidgets());
    Pr->show(true);
    Pr->setSize(600, 700);
    QButton *adm1 = new QButton(*Pr->getWidgets());
    adm1->setText("administrative_ideas");
    adm1->move(5, 5);
    adm1->setSize(190, 90);
    adm1->show(true);
    QButton *adm2 = new QButton(*Pr->getWidgets());
    adm2->setText("economic_ideas");
    adm2->move(5, 100);
    adm2->setSize(190, 90);
    adm2->show(true);
    QButton *adm3 = new QButton(*Pr->getWidgets());
    adm3->setText("expansion_ideas");
    adm3->move(5, 195);
    adm3->setSize(190, 90);
    adm3->show(true);
    QButton *adm4 = new QButton(*Pr->getWidgets());
    adm4->setText("humanist_ideas");
    adm4->move(5, 290);
    adm4->setSize(190, 90);
    adm4->show(true);
    QButton *adm5 = new QButton(*Pr->getWidgets());
    adm5->setText("innovative_ideas");
    adm5->move(5, 385);
    adm5->setSize(190, 90);
    adm5->show(true);
    QButton *adm6 = new QButton(*Pr->getWidgets());
    adm6->setText("religious_ideas");
    adm6->move(5, 480);
    adm6->setSize(190, 90);
    adm6->show(true);

    QButton *dip1 = new QButton(*Pr->getWidgets());
    dip1->setText("diplomatic_ideas");
    dip1->move(205, 5);
    dip1->setSize(190, 90);
    dip1->show(true);
    QButton *dip2 = new QButton(*Pr->getWidgets());
    dip2->setText("espionage_ideas");
    dip2->move(205, 100);
    dip2->setSize(190, 90);
    dip2->show(true);
    QButton *dip3 = new QButton(*Pr->getWidgets());
    dip3->setText("exploration_ideas");
    dip3->move(205, 195);
    dip3->setSize(190, 90);
    dip3->show(true);
    QButton *dip4 = new QButton(*Pr->getWidgets());
    dip4->setText("influence_ideas");
    dip4->move(205, 290);
    dip4->setSize(190, 90);
    dip4->show(true);
    QButton *dip5 = new QButton(*Pr->getWidgets());
    dip5->setText("maritime_ideas");
    dip5->move(205, 385);
    dip5->setSize(190, 90);
    dip5->show(true);
    QButton *dip6 = new QButton(*Pr->getWidgets());
    dip6->setText("trade_ideas");
    dip6->move(205, 480);
    dip6->setSize(190, 90);
    dip6->show(true);

    QButton *mil1 = new QButton(*Pr->getWidgets());
    mil1->setText("aristocratic_ideas");
    mil1->move(405, 5);
    mil1->setSize(190, 90);
    mil1->show(true);
    QButton *mil2 = new QButton(*Pr->getWidgets());
    mil2->setText("defensive_ideas");
    mil2->move(405, 100);
    mil2->setSize(190, 90);
    mil2->show(true);
    QButton *mil3 = new QButton(*Pr->getWidgets());
    mil3->setText("naval_ideas");
    mil3->move(405, 195);
    mil3->setSize(190, 90);
    mil3->show(true);
    QButton *mil4 = new QButton(*Pr->getWidgets());
    mil4->setText("offensive_ideas");
    mil4->move(405, 290);
    mil4->setSize(190, 90);
    mil4->show(true);
    QButton *mil5 = new QButton(*Pr->getWidgets());
    mil5->setText("plutocratic_ideas");
    mil5->move(405, 385);
    mil5->setSize(190, 90);
    mil5->show(true);
    QButton *mil6 = new QButton(*Pr->getWidgets());
    mil6->setText("quality_ideas");
    mil6->move(405, 480);
    mil6->setSize(190, 90);
    mil6->show(true);
    QButton *mil7 = new QButton(*Pr->getWidgets());
    mil7->setText("quantity_ideas");
    mil7->move(405, 575);
    mil7->setSize(190, 90);
    mil7->show(true);

    adm1->connect([adm1, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(adm1->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(adm1->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(adm1->getText());
        }
    });
    adm2->connect([adm2, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(adm2->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(adm2->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(adm2->getText());
        }
    });
    adm3->connect([adm3, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(adm3->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(adm3->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(adm3->getText());
        }
    });
    adm4->connect([adm4, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(adm4->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(adm4->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(adm4->getText());
        }
    });
    adm5->connect([adm5, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(adm5->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(adm5->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(adm5->getText());
        }
    });
    adm6->connect([adm6, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(adm6->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(adm6->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(adm6->getText());
        }
    });

    dip1->connect([dip1, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(dip1->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(dip1->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(dip1->getText());
        }
    });
    dip2->connect([dip2, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(dip2->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(dip2->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(dip2->getText());
        }
    });
    dip3->connect([dip3, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(dip3->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(dip3->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(dip3->getText());
        }
    });
    dip4->connect([dip4, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(dip4->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(dip4->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(dip4->getText());
        }
    });
    dip5->connect([dip5, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(dip5->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(dip5->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(dip5->getText());
        }
    });
    dip6->connect([dip6, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(dip6->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(dip6->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(dip6->getText());
        }
    });

    mil1->connect([mil1, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(mil1->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(mil1->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(mil1->getText());
        }
    });
    mil2->connect([mil2, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(mil2->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(mil2->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(mil2->getText());
        }
    });
    mil3->connect([mil3, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(mil3->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(mil3->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(mil3->getText());
        }
    });
    mil4->connect([mil4, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(mil4->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(mil4->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(mil4->getText());
        }
    });
    mil5->connect([mil5, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(mil5->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(mil5->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(mil5->getText());
        }
    });
    mil6->connect([mil6, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(mil6->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(mil6->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(mil6->getText());
        }
    });
    mil7->connect([mil7, this, newIdeaSet, nb]() {
        this->_tech.at(nb).setName(mil7->getText());
        this->_tech.at(nb).setLvl(0);
        this->_tech.at(nb).access(true, this->_tech.at(nb).tech);
        newIdeaSet->show(false);
        if (nb >= this->activeIdeaGroup.size()) {
            teuton::parser::ActiveIdeaGroup newI;
            newI.setIdeaLevel(0);
            newI.setIdeaName(mil7->getText());
            this->activeIdeaGroup.push_back(newI);
        }
        else {
            this->activeIdeaGroup.at(nb).setIdeaLevel(0);
            this->activeIdeaGroup.at(nb).setIdeaName(mil7->getText());
        }
    });

}

void TechIdeaScene::setVisible(bool show) {
    this->_TechIdeaScene->show(show);
}

std::vector<QWidget*> TechIdeaScene::getWidgets() {
    return this->_local;
}

std::vector<teuton::parser::ActiveIdeaGroup> TechIdeaScene::getNewInfoIdea() {
    return this->activeIdeaGroup;
}

teuton::parser::Technology TechIdeaScene::getNewInfoTech() {
    return this->technology;
}

QButton* TechIdeaScene::getReturn() {
    return this->_Return;
}