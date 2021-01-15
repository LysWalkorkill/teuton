#include "../include/ProvincesScene.hpp"

using namespace teuton::graphical;

ProvincesScene::ProvincesScene(std::string name, teuton::parser::Country country, std::vector<teuton::parser::Province> province) {
    this->_ProvincesScene = new Widget;
    this->country = country;
    this->province = province;
    this->_Return = new QButton(*_ProvincesScene->getWidgets());
    this->_Return->move(10,10);
    this->_Return->setSize(50, 50);
    this->_Return->setText("back");

    this->haut = new Label(*_ProvincesScene->getWidgets());
    this->haut->setSize(500, 50);
    this->name = new Label(*haut->getWidgets());
    this->name->move(225, 22);
    this->name->setText("Province");
    this->_Return = new QButton(*haut->getWidgets());
    this->_Return->move(0,0);
    this->_Return->setSize(50, 50);
    this->_Return->setText("back");
    this->haut->setStyleSheet("background-color: red");
    this->_Return->setStyleSheet("background-color: grey");
    this->middle = new Label(*_ProvincesScene->getWidgets());
    this->middle->move(0, 50);
    this->middle->setSize(500, 100);
    this->middle->setStyleSheet("background-color: green");
    this->bas = new Label(*_ProvincesScene->getWidgets());
    this->bas->move(0, 150);
    this->bas->setSize(500, 450);

    infoP = new teuton::parser::infoFile("../client/graphical/scenes/ressources/provincesList.txt");
    infoP->isWorking();
    std::vector<std::string> temp = infoP->getSave();
    std::vector<int> act;
    for (int i = 0; (size_t)i < province.size(); i++) {
        for (int y = 0; (size_t)y < country.getOwnedProvince().size(); y++) {
            if (country.getOwnedProvince().at(y) == std::atoi(province.at(i).getName().substr(1, province.at(i).getName().size()).c_str())) {
                act.push_back(std::atoi(province.at(i).getName().substr(1, province.at(i).getName().size()).c_str()));
                provinceList.push_back(province.at(i));
            }
        }
    }
    for (int i = 0; (size_t)i < temp.size(); i++) {
        int first = 0;
        bool in = false;
        int lo;
        for (int y = 0; (size_t)y < temp.at(i).size(); y++) {
            if (temp.at(i).at(y) == '\t') {
                if (first == 1 && in) {
                    provinceName.push_back(temp.at(i).substr(0, y));
                    provinceID.push_back(lo);
                    y = temp.at(i).size();
                } else if (first == 0) {
                    first ++;
                    lo = std::atoi(temp.at(i).substr(0, y).c_str());
                    for (int c = 0; (size_t)c < act.size(); c++)
                        if (act.at(c) == lo) {
                            in = true;
                        }
                    if (in)
                        temp.at(i) = temp.at(i).substr(y + 1, temp.at(i).size());
                    y = 0;
                }
            }
        }
    }
    int x = 0;
    int y = 1;
    Label *nameP = new Label(*bas->getWidgets());
    Label *nameP2 = new Label(*bas->getWidgets());
    Label *idP = new Label(*bas->getWidgets());
    Label *milP = new Label(*bas->getWidgets());
    Label *admP = new Label(*bas->getWidgets());
    Label *dipP = new Label(*bas->getWidgets());
    Label *idP2 = new Label(*bas->getWidgets());
    Label *milP2 = new Label(*bas->getWidgets());
    Label *admP2 = new Label(*bas->getWidgets());
    Label *dipP2 = new Label(*bas->getWidgets());

    nameP->move(25, 175);
    idP->move(120, 175);
    admP->move(140, 175);
    dipP->move(175, 175);
    milP->move(210, 175);
    nameP2->move(275, 175);
    idP2->move(370, 175);
    admP2->move(390, 175);
    dipP2->move(425, 175);
    milP2->move(460, 175);

    nameP->setText("name");
    idP->setText("ID");
    admP->setText("taxe");
    dipP->setText("prod");
    milP->setText("man");
    nameP2->setText("name");
    idP2->setText("ID");
    admP2->setText("taxe");
    dipP2->setText("prod");
    milP2->setText("man");
    maxPage = 1;
    for (int i = 0; (size_t)i < provinceName.size(); i++) {
        if (i%7 == 0) {
            x += 250;
            y = 1;
        }
        if (i%14 == 0) {
            x = 0;
            y = 1;
            maxPage++;
        }
        Label *addB = new Label(*bas->getWidgets());
        addB->move(25 + x, 200 + (y * 25));
        addB->setText(provinceName.at(i));
        Label *addI = new Label(*bas->getWidgets());
        addI->move(115 + x, 200 + (y * 25));
        addI->setText(std::to_string(provinceID.at(i)));
        Label *addDA = new Label(*bas->getWidgets());
        addDA->move(150 + x, 200 + (y * 25));
        addDA->setSize(25, 10);
        addDA->setText(std::to_string(provinceList.at(i).getBaseTaxe()));
        Label *addDD = new Label(*bas->getWidgets());
        addDD->setSize(25, 10);
        addDD->move(175 + x, 200 + (y * 25));
        addDD->setText(std::to_string(provinceList.at(i).getBaseProduction()));
        Label *addDM = new Label(*bas->getWidgets());
        addDM->setSize(25, 10);
        addDM->move(200 + x, 200 + (y * 25));
        addDM->setText(std::to_string(provinceList.at(i).getBaseManpower()));
        if (i >= 14) {
            addB->show(false);
            addI->show(false);
            addDA->show(false);
            addDD->show(false);
            addDM->show(false);
        }
        infoD.push_back(addB);
        infoD.push_back(addI);
        infoD.push_back(addDA);
        infoD.push_back(addDD);
        infoD.push_back(addDM);
        y++;
    }
    actPage = 0;

    prevP = new QButton(*bas->getWidgets());
    newtP = new QButton(*bas->getWidgets());
    prevP->move(205, 410);
    newtP->move(255, 410);
    prevP->setSize(35, 35);
    newtP->setSize(35, 35);
    newtP->setText("next");
    prevP->setText("prev");

    searchId = new LineEdit(*bas->getWidgets());
    search = new QButton(*bas->getWidgets());
    dipD = new QButton(*bas->getWidgets());
    admD = new QButton(*bas->getWidgets());
    milD = new QButton(*bas->getWidgets());
    nameC = new Label(*bas->getWidgets());
    IDC = new Label(*bas->getWidgets());
    Label dipDT(*bas->getWidgets());
    Label admDT(*bas->getWidgets());
    Label milDT(*bas->getWidgets());

    searchId->move(150, 10);
    searchId->setSize(200, 25);
    searchId->setText("enter ID here");
    search->move(360, 10);
    search->setSize(45, 25);
    search->setText("search");

    nameC->move(100, 95);
    IDC->move(200, 95);
    admD->move(240, 95);
    dipD->move(290, 95);
    milD->move(340, 95);
    admD->setSize(25, 25);
    dipD->setSize(25, 25);
    milD->setSize(25, 25);
    nameC->setSize(150, 25);
    IDC->setSize(50, 25);

    admDT.move(240, 70);
    dipDT.move(290, 70);
    milDT.move(342, 70);
    admDT.setText("taxe");
    dipDT.setText("prod");
    milDT.setText("man");
    if (provinceName.at(0).size() > 0) {
        nameC->setText(provinceName.at(0));
        IDC->setText(std::to_string(provinceID.at(0)));
        admD->setText(std::to_string(provinceList.at(0).getBaseTaxe()));
        dipD->setText(std::to_string(provinceList.at(0).getBaseProduction()));
        milD->setText(std::to_string(provinceList.at(0).getBaseManpower()));
    }
    this->connect();
}

void ProvincesScene::reset() {
    int y = 0;
    for (int i = 0; (size_t)i < provinceName.size(); i++) {
        this->infoD.at(2 + y)->setText(std::to_string(provinceList.at(i).getBaseTaxe()));
        this->infoD.at(3 + y)->setText(std::to_string(provinceList.at(i).getBaseProduction()));
        this->infoD.at(4 + y)->setText(std::to_string(provinceList.at(i).getBaseManpower()));
        y += 5;
    }
    for (int i = 0; (size_t)i < provinceList.size(); i++) {
        for (int y = 0; (size_t)y < this->province.size(); y++) {
            if (provinceList.at(i).getName() == province.at(y).getName())
                province.at(y) = provinceList.at(i);
        }
    }
}

void ProvincesScene::connect() {
    this->search->connect([this](){
        int i = 0;
        bool isOn = false;
        for (; (size_t)i < provinceList.size() && !isOn; i++)
            if (std::to_string(provinceID.at(i)) == this->searchId->getTxt())
                isOn = true;
        i--;
        if (isOn) {
            this->nameC->setText(provinceName.at(i));
            this->IDC->setText(std::to_string(provinceID.at(i)));
            this->admD->setText(std::to_string(provinceList.at(i).getBaseTaxe()));
            this->dipD->setText(std::to_string(provinceList.at(i).getBaseProduction()));
            this->milD->setText(std::to_string(provinceList.at(i).getBaseManpower()));
        }
    });

    this->admD->connect([this](){
        DialogBox box("new taxe", "new value", DialogBox::TEXT, this->admD->getWidgets());
        int val = std::atoi(box.getText().c_str());
        this->admD->setText(box.getText());
        std::string bf = "enter ID here";
        for (int i = 0; (size_t)i < provinceList.size(); i++) {
            if (bf == this->searchId->getTxt()) {
                provinceList.at(0).setBaseTax(val);
            }
            if (std::to_string(provinceID.at(i)) == this->searchId->getTxt()) {
                provinceList.at(i).setBaseTax(val);
            }
        }
        this->reset();
    });
    this->dipD->connect([this](){
        DialogBox box("new taxe", "new value", DialogBox::TEXT, this->dipD->getWidgets());
        int val = std::atoi(box.getText().c_str());
        this->dipD->setText(box.getText());
        std::string bf = "enter ID here";
        for (int i = 0; (size_t)i < provinceList.size(); i++) {
            if (bf == this->searchId->getTxt()) {
                provinceList.at(0).setBaseProduction(val);
            }
            if (std::to_string(provinceID.at(i)) == this->searchId->getTxt()) {
                provinceList.at(i).setBaseProduction(val);
            }
        }
        this->reset();
    });
    this->milD->connect([this](){
        DialogBox box("new taxe", "new value", DialogBox::TEXT, this->milD->getWidgets());
        int val = std::atoi(box.getText().c_str());
        this->milD->setText(box.getText());
        std::string bf = "enter ID here";
        for (int i = 0; (size_t)i < provinceList.size(); i++) {
            if (bf == this->searchId->getTxt()) {
                provinceList.at(0).setBaseManpower(val);
            }
            if (std::to_string(provinceID.at(i)) == this->searchId->getTxt()) {
                provinceList.at(i).setBaseManpower(val);
            }
        }
        this->reset();
    });
    this->newtP->connect([this](){
        if (actPage + 1 < maxPage)
            actPage++;
        else 
            actPage = 0;
        for (int i = 0; (size_t)i < infoD.size(); i++) {
            infoD.at(i)->show(false);
            if (i >= (actPage * 14 * 5) && i < (actPage * 14 * 5 + 14 * 5)) {
                infoD.at(i)->show(true);
            }
        }
    });
    this->prevP->connect([this](){
        if (actPage > 0)
            actPage--;
        else 
            actPage = maxPage - 1;
        for (int i = 0; (size_t)i < infoD.size(); i++) {
            infoD.at(i)->show(false);
            if (i >= (actPage * 14 * 5) && i < (actPage * 14 * 5 + 14 * 5))
                infoD.at(i)->show(true);
        }
    });
}

ProvincesScene::~ProvincesScene() {} 

void ProvincesScene::setVisible(bool show) {
    this->_ProvincesScene->show(show);
}

std::vector<QWidget*> ProvincesScene::getWidgets() {
    return this->_local;
}    

std::vector<teuton::parser::Province> ProvincesScene::getNewInfo() {
    return this->province;
}

QButton* ProvincesScene::getReturn() {
    return this->_Return;
}