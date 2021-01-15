#include "../include/HomeScene.hpp"

using namespace teuton::graphical;

HomeScene::HomeScene(std::vector<std::string> tag) {
    this->_look = "";
    this->_homeScene = new Widget;
    this->_ledger = new LineEdit(*_homeScene->getWidgets());
    this->_cp1 = new QButton(*_homeScene->getWidgets());
    this->_cp2 = new QButton(*_homeScene->getWidgets());
    this->_cp3 = new QButton(*_homeScene->getWidgets());
    this->_cp4 = new QButton(*_homeScene->getWidgets());
    this->_cp5 = new QButton(*_homeScene->getWidgets());
    this->_cp6 = new QButton(*_homeScene->getWidgets());
    this->_cp7 = new QButton(*_homeScene->getWidgets());
    this->_cp8 = new QButton(*_homeScene->getWidgets());
    this->_search = new QButton(*_homeScene->getWidgets());

    _cp1->setSize(100, 50);
    _cp1->move(300, 100);

    _cp2->move(300, 200);
    _cp2->setSize(100, 50);
    _cp3->move(300, 300);
    _cp3->setSize(100, 50);
    _cp4->move(300, 400);
    _cp4->setSize(100, 50);
    _cp5->move(500, 100);
    _cp5->setSize(100, 50);
    _cp6->move(500, 200);
    _cp6->setSize(100, 50);
    _cp7->move(500, 300);
    _cp7->setSize(100, 50);
    _cp8->move(500, 400);
    _cp8->setSize(100, 50);

    _search->move(610, 33);
    _search->setSize(50, 34);
    _search->setText("search");

   this->_tag = tag;
    _cp1->setText(_tag.at(0));
    _cp2->setText(_tag.at(1));
    _cp3->setText(_tag.at(2));
    _cp4->setText(_tag.at(3));
    _cp5->setText(_tag.at(4));
    _cp6->setText(_tag.at(5));
    _cp7->setText(_tag.at(6));
    _cp8->setText(_tag.at(7));

    _search->connect([this](){
        searchAcces();
    });

    _homeScene->setSize(900, 600);
    _homeScene->setTransparentBackground(false);
    this->_ledger->setSize(300, 34);
    this->_ledger->move(300, 33);

    this->_Widgets.insert(std::pair<std::string, int>("homeScene", 0));
    this->_Widgets.insert(std::pair<std::string, int>("ledger", 1));
    this->_Widgets.insert(std::pair<std::string, int>("cp1", 2));
    this->_Widgets.insert(std::pair<std::string, int>("cp2", 3));
    this->_Widgets.insert(std::pair<std::string, int>("cp3", 4));
    this->_Widgets.insert(std::pair<std::string, int>("cp4", 5));
    this->_Widgets.insert(std::pair<std::string, int>("cp5", 6));
    this->_Widgets.insert(std::pair<std::string, int>("cp6", 7));
    this->_Widgets.insert(std::pair<std::string, int>("cp7", 8));
    this->_Widgets.insert(std::pair<std::string, int>("cp8", 9));
    this->_Widgets.insert(std::pair<std::string, int>("search", 10));

    this->_local.push_back(_homeScene->getWidgets());
    this->_local.push_back(this->_ledger->getWidgets());
    this->_local.push_back(_cp1->getWidgets());
    this->_local.push_back(_cp2->getWidgets());
    this->_local.push_back(_cp3->getWidgets());
    this->_local.push_back(_cp4->getWidgets());
    this->_local.push_back(_cp5->getWidgets());
    this->_local.push_back(_cp6->getWidgets());
    this->_local.push_back(_cp7->getWidgets());
    this->_local.push_back(_cp8->getWidgets());
    this->_local.push_back(_search->getWidgets());

    _cp.push_back(_cp1);
    _cp.push_back(_cp2);
    _cp.push_back(_cp3);
    _cp.push_back(_cp4);
    _cp.push_back(_cp5);
    _cp.push_back(_cp6);
    _cp.push_back(_cp7);
    _cp.push_back(_cp8);
}

HomeScene::~HomeScene() {
    this->_homeScene->~Widget();
} 

std::vector<QWidget*> HomeScene::getWidgets() {
    return this->_local;
}

void HomeScene::searchAcces() {
    this->_look = this->_ledger->getTxt();
    //std::cout << this->_look << std::endl;
    this->mostProbableCountry(this->_tag, this->_look);
}

std::string HomeScene::cp1Acces() {
    return _cp.at(0)->getText();
}
std::string HomeScene::cp2Acces() {
    return _cp.at(1)->getText();
}
std::string HomeScene::cp3Acces() {
    return _cp.at(2)->getText();
}
std::string HomeScene::cp4Acces() {
    return _cp.at(3)->getText();
}
std::string HomeScene::cp5Acces() {
    return _cp.at(4)->getText();
}
std::string HomeScene::cp6Acces() {
    return _cp.at(5)->getText();
}
std::string HomeScene::cp7Acces() {
    return _cp.at(6)->getText();
}
std::string HomeScene::cp8Acces() {
    return _cp.at(7)->getText();
}

void HomeScene::mostProbableCountry(std::vector<std::string> tag, std::string name) {
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

void HomeScene::setVisible(bool show) {
    this->_homeScene->show(show);
}

std::vector<QButton*> HomeScene::getCp() {
    return this->_cp;
}