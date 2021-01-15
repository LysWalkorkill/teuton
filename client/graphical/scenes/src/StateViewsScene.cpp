#include "../include/StateViewsScene.hpp"

using namespace teuton::graphical;

StateViewsScene::StateViewsScene(std::string name, teuton::parser::StateViews st, std::vector<std::string> rival, std::vector<std::string> tag) {
    this->_StateViewsScene = new Widget;
    this->stateViews = st;
    this->rival = rival;
    this->tag = tag;

    this->haut = new Label(*_StateViewsScene->getWidgets());
    this->middle = new Label(*_StateViewsScene->getWidgets());
    this->bas  = new Label(*_StateViewsScene->getWidgets());
    this->powerProjection = new Label(*bas->getWidgets());
    this->prestige = new Label(*bas->getWidgets());
    this->stability = new Label(*bas->getWidgets());
    this->manpower = new Label(*bas->getWidgets());
    this->innovation = new Label(*bas->getWidgets());
    this->reformProgress = new Label(*bas->getWidgets());
    this->cC1 = new QButton(*bas->getWidgets());
    this->cC2 = new QButton(*bas->getWidgets());
    this->cC3 = new QButton(*bas->getWidgets());
    this->cC4 = new QButton(*bas->getWidgets());
    this->cC5 = new QButton(*bas->getWidgets());
    this->cC6 = new QButton(*bas->getWidgets());

    this->haut->setSize(500, 50);
    this->haut->setStyleSheet("background-color: red");
    this->name = new Label(*haut->getWidgets());
    this->name->move(200, 22);
    this->name->setText("State Views");
    this->middle->move(0, 50);
    this->middle->setSize(500, 100);
    this->middle->setStyleSheet("background-color: green");
    this->bas->move(0, 150);
    this->bas->setSize(500, 450);

    this->_Return = new QButton(*haut->getWidgets());
    this->_Return->move(0,0);
    this->_Return->setSize(50, 50);
    this->_Return->setText("back");
    this->_Return->setStyleSheet("background-color: grey");
    this->_Return->show(true);

    this->powerProjection->setSize(150, 50);
    this->prestige->setSize(150, 50);
    this->stability->setSize(150, 50);
    this->manpower->setSize(150, 50);
    this->innovation->setSize(150, 50);
    this->reformProgress->setSize(150, 50);

    this->powerProjection->move(50, 50);
    this->prestige->move(50, 150);
    this->stability->move(50, 250);
    this->manpower->move(300, 50);
    this->innovation->move(300, 150);
    this->reformProgress->move(275, 250);

    this->cC1->move(160, 50);
    this->cC2->move(160, 150);
    this->cC3->move(160, 250);
    this->cC4->move(375, 50);
    this->cC5->move(375, 150);
    this->cC6->move(375, 250);

    this->cC1->setSize(100, 50);
    this->cC2->setSize(100, 50);
    this->cC3->setSize(100, 50);
    this->cC4->setSize(100, 50);
    this->cC5->setSize(100, 50);
    this->cC5->setSize(100, 50);
    this->cC6->setSize(100, 50);

    this->powerProjection->setText("PowerProjection");
    this->prestige->setText("Prestige");
    this->stability->setText("Stability");
    this->manpower->setText("Manpower");
    this->innovation->setText("Innovation");
    this->reformProgress->setText("reformProgress");

    this->R1 = new QButton(*bas->getWidgets());
    this->R2 = new QButton(*bas->getWidgets());
    this->R3 = new QButton(*bas->getWidgets());
    this->txtR1 = new Label(*bas->getWidgets());
    this->txtR2 = new Label(*bas->getWidgets());
    this->txtR3 = new Label(*bas->getWidgets());

    R1->move(100, 350);
    R2->move(200, 350);
    R3->move(300, 350);
    txtR1->move(100, 340);
    txtR2->move(200, 340);
    txtR3->move(300, 340);

    if (rival.size() >= 1)
        R1->setText(rival.at(0).substr(1, rival.at(0).size() - 2));
    else
        R1->setText("noRival");
    if (rival.size() >= 2)
        R2->setText(rival.at(1).substr(1, rival.at(1).size() - 2));
    else
        R2->setText("noRival");
    if (rival.size() >= 3)
        R3->setText(rival.at(2).substr(1, rival.at(2).size() - 2));
    else
        R3->setText("noRival");

    txtR1->setText("Rival n° 1");
    txtR2->setText("Rival n° 2");
    txtR3->setText("Rival n° 3");

    R1->show(true);
    R2->show(true);
    R3->show(true);
    txtR1->show(true);
    txtR2->show(true);
    txtR3->show(true);
    if (R1->getText() == "noRival") {
        R1->show(false);
        txtR1->show(false);
    }
    if (R2->getText() == "noRival") {
        R2->show(false);
        txtR2->show(false);
    }
    if (R3->getText() == "noRival") {
        R3->show(false);
        txtR3->show(false);
    }

    _R.push_back(R1);
    _R.push_back(R2);
    _R.push_back(R3);

    if (stateViews.getCurrentPowerProjection() >= 0 && stateViews.getCurrentPowerProjection() <=100)
        this->cC1->setText(std::to_string(stateViews.getCurrentPowerProjection()));
    else 
        this->cC1->setText(std::to_string(0));
    this->cC2->setText(std::to_string(stateViews.getPrestige()));
    this->cC3->setText(std::to_string(stateViews.getStability()));
    this->cC4->setText(std::to_string(stateViews.getManpower()));
    this->cC5->setText(std::to_string(stateViews.getInnovativeness()));
    this->cC6->setText(std::to_string(stateViews.getRefromProgress()));

    this->connection();
}

StateViewsScene::~StateViewsScene() {} 

void StateViewsScene::connection() {
    this->R1->connect([this](){
        this->newRival(1);
    });
    this->R2->connect([this](){
        this->newRival(2);
    });
    this->R3->connect([this](){
        this->newRival(3);
    });
    this->cC1->connect([this](){
        DialogBox box("new powerProjection", "new value", DialogBox::TEXT, this->cC1->getWidgets());
        teuton::parser::StateViews newG = this->getNewInfo();
        std::string value = box.getText();
        try {
            int tst = std::stoi(value);
        }
        catch(std::exception const & e)
        {
            return;
        }
        int tst = std::stoi(value);
        if (tst <= 100 && tst >= 0) {
            int pt = 0;
            float ds;
            for (; (size_t)pt < value.size() && value.at(pt) != '.';pt++);
            if ((size_t)pt != value.size()) {
                std::string tsts = value.substr(0, pt) + value.substr(pt + 1, value.size());
                int ts = 1;
                for (; (size_t)pt != value.size(); pt++)
                    ts = ts * 10;
                ts = ts / 10;
                ds = ((float)std::stoi(tsts) / ts);
            } else {
                ds = std::stof(value);
            }

            this->cC1->setText(value);
            newG.setCurrentPowerProjection(ds);
            this->setNewInfo(newG);
        }
    });
    this->cC2->connect([this](){
        DialogBox box("new powerProjection", "new value", DialogBox::TEXT, this->cC2->getWidgets());
        teuton::parser::StateViews newG = this->getNewInfo();
        std::string value = box.getText();
        try {
            int tst = std::stoi(value);
        }
        catch(std::exception const & e)
        {
            return;
        }
        int tst = std::stoi(value);
        if (tst <= 100 && tst >= -100) {
            int pt = 0;
            float ds;
            for (; (size_t)pt < value.size() && value.at(pt) != '.';pt++);
            if ((size_t)pt != value.size()) {
                std::string tsts = value.substr(0, pt) + value.substr(pt + 1, value.size());
                int ts = 1;
                for (; (size_t)pt != value.size(); pt++)
                    ts = ts * 10;
                ts = ts / 10;
                ds = ((float)std::stoi(tsts) / ts);
            } else {
                ds = std::stof(value);
            }

            this->cC2->setText(value);
            newG.setPrestige(ds);
            this->setNewInfo(newG);
        }
    });
    this->cC3->connect([this](){
        DialogBox box("new powerProjection", "new value", DialogBox::TEXT, this->cC3->getWidgets());
        teuton::parser::StateViews newG = this->getNewInfo();
        std::string value = box.getText();
        try {
            int tst = std::stoi(value);
        }
        catch(std::exception const & e)
        {
            return;
        }
        int tst = std::stoi(value);
        if (tst <= 3 && tst >= -3) {
            int pt = 0;
            float ds;
            for (; (size_t)pt < value.size() && value.at(pt) != '.';pt++);
            if ((size_t)pt != value.size()) {
                std::string tsts = value.substr(0, pt) + value.substr(pt + 1, value.size());
                int ts = 1;
                for (; (size_t)pt != value.size(); pt++)
                    ts = ts * 10;
                ts = ts / 10;
                ds = ((float)std::stoi(tsts) / ts);
            } else {
                ds = std::stof(value);
            }

            this->cC3->setText(value);
            newG.setStability(ds);
            this->setNewInfo(newG);
        }
    });
    this->cC4->connect([this](){
        DialogBox box("new powerProjection", "new value", DialogBox::TEXT, this->cC4->getWidgets());
        teuton::parser::StateViews newG = this->getNewInfo();
        std::string value = box.getText();
        try {
            int tst = std::stoi(value);
        }
        catch(std::exception const & e)
        {
            return;
        }
        int tst = std::stoi(value);
        int pt = 0;
        float ds;
        for (; (size_t)pt < value.size() && value.at(pt) != '.';pt++);
        if ((size_t)pt != value.size()) {
            std::string tsts = value.substr(0, pt) + value.substr(pt + 1, value.size());
            int ts = 1;
            for (; (size_t)pt != value.size(); pt++)
                ts = ts * 10;
            ts = ts / 10;
            ds = ((float)std::stoi(tsts) / ts);
        } else {
            ds = std::stof(value);
        }

        this->cC4->setText(value);
        newG.setManpower(ds);
        this->setNewInfo(newG);
    });
    this->cC5->connect([this](){
        DialogBox box("new powerProjection", "new value", DialogBox::TEXT, this->cC5->getWidgets());
        teuton::parser::StateViews newG = this->getNewInfo();
        std::string value = box.getText();
        try {
            int tst = std::stoi(value);
        }
        catch(std::exception const & e)
        {
            return;
        }
        int tst = std::stoi(value);
        if (tst <= 100 && tst >= 0) {
            int pt = 0;
            float ds;
            for (; (size_t)pt < value.size() && value.at(pt) != '.';pt++);
            if ((size_t)pt != value.size()) {
                std::string tsts = value.substr(0, pt) + value.substr(pt + 1, value.size());
                int ts = 1;
                for (; (size_t)pt != value.size(); pt++)
                    ts = ts * 10;
                ts = ts / 10;
                ds = ((float)std::stoi(tsts) / ts);
            } else {
                ds = std::stof(value);
            }

            this->cC5->setText(value);
            newG.setInnovativeness(ds);
            this->setNewInfo(newG);
        }
    });
    this->cC6->connect([this](){
        DialogBox box("new reformProgress", "new value", DialogBox::TEXT, this->cC6->getWidgets());
        teuton::parser::StateViews newG = this->getNewInfo();
        std::string value = box.getText();
        try {
            int tst = std::stoi(value);
        }
        catch(std::exception const & e)
        {
            return;
        }
        int tst = std::stoi(value);
        if (tst <= 10000 && tst >= 0) {
            int pt = 0;
            float ds;
            for (; (size_t)pt < value.size() && value.at(pt) != '.';pt++);
            if ((size_t)pt != value.size()) {
                std::string tsts = value.substr(0, pt) + value.substr(pt + 1, value.size());
                int ts = 1;
                for (; (size_t)pt != value.size(); pt++)
                    ts = ts * 10;
                ts = ts / 10;
                ds = ((float)std::stoi(tsts) / ts);
            } else {
                ds = std::stof(value);
            }

            this->cC6->setText(value);
            newG.setRefromProgress(ds);
            this->setNewInfo(newG);
        }
    });
}

void StateViewsScene::setNewInfo(teuton::parser::StateViews st) {
    this->stateViews = st;
}

void StateViewsScene::setVisible(bool show) {
    this->_StateViewsScene->show(show);
}

std::vector<QWidget*> StateViewsScene::getWidgets() {
    return this->_local;
}

teuton::parser::StateViews StateViewsScene::getNewInfo() {
    return this->stateViews;
}

QButton* StateViewsScene::getReturn() {
    return this->_Return;
}

std::vector<std::string> StateViewsScene::getRival() {
    return this->rival;
}

void StateViewsScene::mostProbableCountry(std::vector<std::string> tag, std::string name) {
    std::vector<std::string> potentiel;
    std::vector<std::string> potentiel2;
    std::vector<std::string> potentiel3;
    if (name == "")
        return;
    for (int i = 0; name.size() >= 1 && (size_t)i < tag.size(); i++) {
        if (tag.at(i).at(0) == name.at(0))
            potentiel.push_back(tag.at(i));
    }
    potentiel3 = tag;
    if (name.size() >= 2) {
        for (int i = 0; name.size() >= 2 && (size_t)i < potentiel.size(); i++) {
            if (potentiel.at(i).at(1) == name.at(1))
                potentiel2.push_back(potentiel.at(i));
        }
        potentiel3 = potentiel;
        potentiel = potentiel2;
        potentiel2.clear();
        if (name.size() >= 3) {
            for (int i = 0; name.size() >= 3 && (size_t)i < potentiel.size(); i++) {
                if (potentiel.at(i).at(2) == name.at(2))
                    potentiel2.push_back(potentiel.at(i));
            }
            potentiel3 = potentiel;
            potentiel = potentiel2;
            potentiel2.clear();
        }
    }

    int nb = potentiel.size();
    for (int i = 0; i < nb && i < 8; i++) {
        _cp.at(i)->setText(potentiel.at(i));
    }
    
    for (; nb < 8 && (size_t)nb < potentiel3.size(); nb++)
        _cp.at(nb)->setText(potentiel3.at(nb));
}

void StateViewsScene::newRival(int nb) {
    Rival = new Widget;
    Rival->setSize(210, 60 + 60 * 8);
    Rival->setTransparentBackground(false);
    Rival->show(true);
    Pr = new Label(*Rival->getWidgets());
    //Pr->setStyleSheet("background-color: grey");
    Pr->move(5, 5);
    Pr->setSize(200, 60 + 60 * 8);
    Pr->show(true);
    _cp.clear();

    newName = new LineEdit(*Rival->getWidgets());
    newName->move(5,25);
    newName->setSize(150, 20);
    newName->show(true);
    research = new QButton(*Pr->getWidgets());
    research->move(160, 19);
    research->setSize(45, 25);
    research->setText("search");
    research->show(true);

    QButton *add1 = new QButton(*Pr->getWidgets());
    QButton *add2 = new QButton(*Pr->getWidgets());
    QButton *add3 = new QButton(*Pr->getWidgets());
    QButton *add4 = new QButton(*Pr->getWidgets());
    QButton *add5 = new QButton(*Pr->getWidgets());
    QButton *add6 = new QButton(*Pr->getWidgets());
    QButton *add7 = new QButton(*Pr->getWidgets());
    QButton *add8 = new QButton(*Pr->getWidgets());

    _cp.push_back(add1);
    _cp.push_back(add2);
    _cp.push_back(add3);
    _cp.push_back(add4);
    _cp.push_back(add5);
    _cp.push_back(add6);
    _cp.push_back(add7);
    _cp.push_back(add8);

    _cp.at(0)->setText(tag.at(0));
    _cp.at(2)->setText(tag.at(2));
    _cp.at(3)->setText(tag.at(3));
    _cp.at(4)->setText(tag.at(4));
    _cp.at(5)->setText(tag.at(5));
    _cp.at(6)->setText(tag.at(6));
    _cp.at(7)->setText(tag.at(7));
    _cp.at(1)->setText(tag.at(1));

    for (int i = 0; 8 > (size_t)i; i++) {
        _cp.at(i)->setSize(190, 50);
        _cp.at(i)->move(5, 5 + 45 + 60 * i);
        _cp.at(i)->show(true);
    }


    research->connect([this](){
        this->mostProbableCountry(this->tag, this->newName->getTxt());
    });
    _cp.at(0)->connect([this, nb](){
        this->_R.at(nb - 1)->setText(this->_cp.at(0)->getText());
        if (this->rival.size() >= nb)
            this->rival.at(nb - 1) = '"' + this->_R.at(nb - 1)->getText() + '"';
        else
            this->rival.push_back('"' + this->_R.at(nb - 1)->getText() + '"');
        this->Rival->show(false);
    });
    _cp.at(1)->connect([this, nb](){
        this->_R.at(nb - 1)->setText(this->_cp.at(1)->getText());
        if (this->rival.size() >= nb)
            this->rival.at(nb - 1) = '"' + this->_R.at(nb - 1)->getText() + '"';
        else
            this->rival.push_back('"' + this->_R.at(nb - 1)->getText() + '"');
        this->Rival->show(false);
    });
    _cp.at(2)->connect([this, nb](){
        this->_R.at(nb - 1)->setText(this->_cp.at(2)->getText());
        if (this->rival.size() >= nb)
            this->rival.at(nb - 1) = '"' + this->_R.at(nb - 1)->getText() + '"';
        else
            this->rival.push_back('"' + this->_R.at(nb - 1)->getText() + '"');
        this->Rival->show(false);
    });
    _cp.at(3)->connect([this, nb](){
        this->_R.at(nb - 1)->setText(this->_cp.at(3)->getText());
        if (this->rival.size() >= nb)
            this->rival.at(nb - 1) = '"' + this->_R.at(nb - 1)->getText() + '"';
        else
            this->rival.push_back('"' + this->_R.at(nb - 1)->getText() + '"');
        this->Rival->show(false);
    });
    _cp.at(4)->connect([this, nb](){
        this->_R.at(nb - 1)->setText(this->_cp.at(4)->getText());
        if (this->rival.size() >= nb)
            this->rival.at(nb - 1) = '"' + this->_R.at(nb - 1)->getText() + '"';
        else
            this->rival.push_back('"' + this->_R.at(nb - 1)->getText() + '"');
        this->Rival->show(false);
    });
    _cp.at(5)->connect([this, nb](){
        this->_R.at(nb - 1)->setText(this->_cp.at(5)->getText());
        if (this->rival.size() >= nb)
            this->rival.at(nb - 1) = '"' + this->_R.at(nb - 1)->getText() + '"';
        else
            this->rival.push_back('"' + this->_R.at(nb - 1)->getText() + '"');
        this->Rival->show(false);
    });
    _cp.at(6)->connect([this, nb](){
        this->_R.at(nb - 1)->setText(this->_cp.at(6)->getText());
        if (this->rival.size() >= nb)
            this->rival.at(nb - 1) = '"' + this->_R.at(nb - 1)->getText() + '"';
        else
            this->rival.push_back('"' + this->_R.at(nb - 1)->getText() + '"');
        this->Rival->show(false);
    });
    _cp.at(7)->connect([this, nb](){
        this->_R.at(nb - 1)->setText(this->_cp.at(7)->getText());
        if (this->rival.size() >= nb)
            this->rival.at(nb - 1) = '"' + this->_R.at(nb - 1)->getText() + '"';
        else
            this->rival.push_back('"' + this->_R.at(nb - 1)->getText() + '"');
        this->Rival->show(false);
    });
}