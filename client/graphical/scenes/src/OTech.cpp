#include "../include/OTech.hpp"

using namespace teuton::graphical;

OTech::OTech(std::string name, int lvl, Label *scene) {
    this->scene = scene;
    this->name = name;
    this->lvl = new Idea(lvl);
    idea = new Label(*scene->getWidgets());
    this->idea->show(true);
    this->idea->setStyleSheet("background-color: grey");
    b1 = new QButton(*idea->getWidgets());
    b2 = new QButton(*idea->getWidgets());
    b3 = new QButton(*idea->getWidgets());
    b4 = new QButton(*idea->getWidgets());
    b5 = new QButton(*idea->getWidgets());
    b6 = new QButton(*idea->getWidgets());
    b7 = new QButton(*idea->getWidgets());
    deleteIdea = new QButton(*idea->getWidgets());

    b1->setSize(20, 20);
    b2->setSize(20, 20);
    b3->setSize(20, 20);
    b4->setSize(20, 20);
    b5->setSize(20, 20);
    b6->setSize(20, 20);
    b7->setSize(20, 20);

    b1->setText("");
    b2->setText("");
    b3->setText("");
    b4->setText("");
    b5->setText("");
    b6->setText("");
    b7->setText("");
    
    newIdea = new QButton(*idea->getWidgets());
    newIdea->setSize(240, 50);
    newIdea->move(0, 25);
    newIdea->setText("new idea");
    newIdea->show(false);

    deleteIdea->setSize(45, 30);
    deleteIdea->setStyleSheet("background-color: red");
    deleteIdea->setText("delete");

    this->setLvl(lvl);
    //this->connect();
}
OTech::~OTech() {
}

void OTech::setLvl(int lvl) {
    this->lvl->setLvl(lvl);
        for (int i = 0; i <= lvl; i++) {
        if (i == 1) {
            b1->setStyleSheet("background-color: green");
        }
        if (i == 2)
            b2->setStyleSheet("background-color: green");
        if (i == 3)
            b3->setStyleSheet("background-color: green");
        if (i == 4)
            b4->setStyleSheet("background-color: green");
        if (i == 5)
            b5->setStyleSheet("background-color: green");
        if (i == 6)
            b6->setStyleSheet("background-color: green");
        if (i == 7)
            b7->setStyleSheet("background-color: green");
    }
    for (int i = lvl + 1; i <= 7; i++) {
        if (i == 1)
            b1->setStyleSheet("background-color: red");
        if (i == 2)
            b2->setStyleSheet("background-color: red");
        if (i == 3)
            b3->setStyleSheet("background-color: red");
        if (i == 4)
            b4->setStyleSheet("background-color: red");
        if (i == 5)
            b5->setStyleSheet("background-color: red");
        if (i == 6)
            b6->setStyleSheet("background-color: red");
        if (i == 7)
            b7->setStyleSheet("background-color: red");
    }
}

void OTech::setName(std::string name) {
    this->name = name;
    this->idea->setText(name);
}

void OTech::access(bool isOn, int tech) {
    this->acces = isOn;
    this->tech = tech;
    if (!isOn) {
        std::string exp;
        if (tech <= 4)
            exp = "Unlocked at tech adm 4";
        else if (tech <= 7)
            exp = "Unlocked at tech adm 7";
        else if (tech <= 10)
            exp = "Unlocked at tech adm 10";
        else if (tech <= 14)
            exp = "Unlocked at tech adm 14";
        else if (tech <= 18)
            exp = "Unlocked at tech adm 18";
        else if (tech <= 22)
            exp = "Unlocked at tech adm 22";
        else if (tech <= 26)
            exp = "Unlocked at tech adm 26";
        else if (tech <= 29)
            exp = "Unlocked at tech adm 29";
        this->idea->setText(exp);
        b1->show(false);
        b2->show(false);
        b3->show(false);
        b4->show(false);
        b5->show(false);
        b6->show(false);
        b7->show(false);
        deleteIdea->show(false);
        //this->newIdea->show(true);
    }
    if (isOn) {
        this->idea->setText(this->name);
        b1->show(true);
        b2->show(true);
        b3->show(true);
        b4->show(true);
        b5->show(true);
        b6->show(true);
        b7->show(true);
        deleteIdea->show(true);
        newIdea->show(false);
    }
}

void OTech::setLabel(int x, int y, int w, int h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->idea->move(x, y);
    this->idea->setSize(w, h);
    b1->move(20, 70);
    b2->move(50, 70);
    b3->move(80, 70);
    b4->move(110, 70);
    b5->move(140, 70);
    b6->move(170, 70);
    b7->move(200, 70);

    deleteIdea->move(195, 5);
}

int OTech::getLvl() {
    return this->lvl->getLvl();
}

std::string OTech::getName() {
    return this->name;
}

void OTech::reset() {
    if (this->getName() == "new idea") {
        b1->show(false);
        b2->show(false);
        b3->show(false);
        b4->show(false);
        b5->show(false);
        b6->show(false);
        b7->show(false);
        deleteIdea->show(false);
    } else {
        this->setLvl(this->lvl->getLvl());
        this->setName(this->name);
        this->access(this->acces, this->lvl->getLvl());
    }
}

void OTech::connect() {
    b1->connect([this](){
        this->setLvl(1);
    });
    b2->connect([this](){
        this->setLvl(2);
    });
    b3->connect([this](){
        this->setLvl(3);
    });
    b4->connect([this](){
        this->setLvl(4);
    });
    b5->connect([this](){
        this->setLvl(5);
    });
    b6->connect([this](){
        this->setLvl(6);
    });
    b7->connect([this](){
        this->setLvl(7);
    });
    deleteIdea->connect([this](){
        this->name = "";
        this->setName("new idea");
        this->newIdea->show(true);
        this->setLvl(0);
        this->reset();
    });
}