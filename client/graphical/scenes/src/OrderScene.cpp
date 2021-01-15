#include "../include/OrderScene.hpp"

using namespace teuton::graphical;

OrderScene::OrderScene(std::string name, std::vector<teuton::parser::Estates> estates, teuton::parser::Country country) {
    this->_OrderScene = new Widget;
    this->country = country;
    this->estates = estates;
    this->_Return = new QButton(*_OrderScene->getWidgets());
    this->_Return->move(10,10);
    this->_Return->setSize(50, 50);
    this->_Return->setText("back");

    this->haut = new Label(*_OrderScene->getWidgets());
    this->haut->setSize(500, 50);
    this->name = new Label(*haut->getWidgets());
    this->name->move(240, 22);
    this->name->setText("Orders");
    this->_Return = new QButton(*haut->getWidgets());
    this->_Return->move(0,0);
    this->_Return->setSize(50, 50);
    this->_Return->setText("back");
    this->haut->setStyleSheet("background-color: red");
    this->_Return->setStyleSheet("background-color: grey");
    this->middle = new Label(*_OrderScene->getWidgets());
    this->middle->move(0, 50);
    this->middle->setSize(500, 100);
    this->middle->setStyleSheet("background-color: green");
    this->bas = new Label(*_OrderScene->getWidgets());
    this->bas->move(0, 150);
    this->bas->setSize(500, 450);

    if (country.getReligion() == "catholic" || country.getReligion() =="protestant" || country.getReligion() =="reformed" || country.getReligion() =="orthodox" || country.getReligion() =="coptic" || country.getReligion() =="Anglican" || country.getReligion() =="sunni" || country.getReligion() =="shia" || country.getReligion() =="ibadi") {
        for (int i = 0; (size_t)i < estates.size(); i++) {
            if (estates.at(i).getType().substr(1, estates.at(i).getType().size() - 2) == "estate_nobles") {
                noblesPrivilegies = estates.at(i).getGrantedPrivileges();
            }
            if (estates.at(i).getType().substr(1, estates.at(i).getType().size() - 2) == "estate_burghers") {
                burghersPrivilegies = estates.at(i).getGrantedPrivileges();
            }
            if (estates.at(i).getType().substr(1, estates.at(i).getType().size() - 2) == "estate_church") {
                clericalPrivilegies = estates.at(i).getGrantedPrivileges();
            }
        }

        allNobles.push_back("estate_nobles_land_rights");
        allNobles.push_back("estate_nobles_nobility_primacy");
        allNobles.push_back("estate_nobles_officier_corp");
        allNobles.push_back("estate_nobles_levies");
        allNobles.push_back("estate_nobles_advisors");
        allNobles.push_back("estate_nobles_right_of_counsel");
        allNobles.push_back("estate_nobles_junker_primacy");
        allNobles.push_back("estate_nobles_strong_duchies");
        allNobles.push_back("estate_nobles_statutory_rights");

        allChurch.push_back("estate_church_land_rights");
        allChurch.push_back("estate_church_religious_state");
        allChurch.push_back("estate_church_independent_inquisition");
        allChurch.push_back("estate_church_new_world_mission");
        allChurch.push_back("estate_church_papal_emissary");
        allChurch.push_back("estate_church_clerical_ministers");
        allChurch.push_back("estate_church_clerical_oversight");
        allChurch.push_back("estate_church_inwords_perfection");
        allChurch.push_back("estate_church_enforced_one_faith");

        allBurghers.push_back("estate_burghers_land_rights");
        allBurghers.push_back("estate_burghers_enforced_interfaith_dialogue");
        allBurghers.push_back("estate_burghers_land_of_commerce");
        allBurghers.push_back("estate_burghers_admirals");
        allBurghers.push_back("estate_burghers_commercial_board_of_advice");
        allBurghers.push_back("estate_burghers_new_world_charter");
        allBurghers.push_back("estate_burghers_indebted_to_burghers");
        allBurghers.push_back("estate_burghers_free_enterprise");
        allBurghers.push_back("estate_burghers_patrognage_of_the_arts");

        burghers();
        nobles();
        clergy();
        connectBurghers();
        connectClergy();
        connectNobles();
    }
}

void OrderScene::burghers() {
    b1 = new QButton(*this->bas->getWidgets());
    b2 = new QButton(*this->bas->getWidgets());
    b3 = new QButton(*this->bas->getWidgets());
    b4 = new QButton(*this->bas->getWidgets());
    Label estateName(*this->bas->getWidgets());

    estateName.move(30, 70);
    estateName.setText("burghers");
    estateName.show(true);

    b1->move(105, 50);
    b1->setSize(90, 50);
    b2->move(205, 50);
    b2->setSize(90, 50);
    b3->move(305, 50);
    b3->setSize(90, 50);
    b4->move(405, 50);
    b4->setSize(90, 50);
    if (burghersPrivilegies.size() >= 1) {
        std::string ln = burghersPrivilegies.at(0).substr(16, burghersPrivilegies.at(0).size());
        int under = 0;
        for (int y = 0; (size_t)y < ln.size(); y++) {
                if (ln.at(y) == '_' && under == 0) {
                    under++;
                    ln.at(y) = '\n';
                } else if (ln.at(y) == '_') {
                    ln.at(y) = ' ';
                }
            }
        b1->setText(ln);
    } else 
        b1->setText("empty");
    if (burghersPrivilegies.size() >= 2) {
        std::string ln = burghersPrivilegies.at(1).substr(16, burghersPrivilegies.at(1).size());
        int under = 0;
        for (int y = 0; (size_t)y < ln.size(); y++) {
                if (ln.at(y) == '_' && under == 0) {
                    under++;
                    ln.at(y) = '\n';
                } else if (ln.at(y) == '_') {
                    ln.at(y) = ' ';
                }
            }
        b2->setText(ln);
    } else 
        b2->setText("empty");
    if (burghersPrivilegies.size() >= 3) {
        std::string ln = burghersPrivilegies.at(2).substr(16, burghersPrivilegies.at(2).size());
        int under = 0;
        for (int y = 0; (size_t)y < ln.size(); y++) {
                if (ln.at(y) == '_' && under == 0) {
                    under++;
                    ln.at(y) = '\n';
                } else if (ln.at(y) == '_') {
                    ln.at(y) = ' ';
                }
            }
        b3->setText(ln);
    } else 
        b3->setText("empty");
    if (burghersPrivilegies.size() >= 4) {
        std::string ln = burghersPrivilegies.at(3).substr(16, burghersPrivilegies.at(3).size());
        int under = 0;
        for (int y = 0; (size_t)y < ln.size(); y++) {
                if (ln.at(y) == '_' && under == 0) {
                    under++;
                    ln.at(y) = '\n';
                } else if (ln.at(y) == '_') {
                    ln.at(y) = ' ';
                }
            }
        b4->setText(ln);
    } else 
        b4->setText("empty");
}

void OrderScene::nobles() {
    n1 = new QButton(*this->bas->getWidgets());
    n2 = new QButton(*this->bas->getWidgets());
    n3 = new QButton(*this->bas->getWidgets());
    n4 = new QButton(*this->bas->getWidgets());
    Label estateName(*this->bas->getWidgets());

    estateName.move(30, 220);
    estateName.setText("nobles");
    estateName.show(true);

    n1->move(105, 200);
    n1->setSize(90, 50);
    n2->move(205, 200);
    n2->setSize(90, 50);
    n3->move(305, 200);
    n3->setSize(90, 50);
    n4->move(405, 200);
    n4->setSize(90, 50);
    if (noblesPrivilegies.size() >= 1) {
        std::string ln = noblesPrivilegies.at(0).substr(14, noblesPrivilegies.at(0).size());
        int under = 0;
        for (int y = 0; (size_t)y < ln.size(); y++) {
            if (ln.at(y) == '_' && under == 0) {
                under++;
                ln.at(y) = '\n';
            } else if (ln.at(y) == '_') {
                ln.at(y) = ' ';
            }
        }
        n1->setText(ln);
    } else 
        n1->setText("empty");
    if (noblesPrivilegies.size() >= 2) {
        std::string ln = noblesPrivilegies.at(1).substr(14, noblesPrivilegies.at(1).size());
        int under = 0;
        for (int y = 0; (size_t)y < ln.size(); y++) {
            if (ln.at(y) == '_' && under == 0) {
                under++;
                ln.at(y) = '\n';
            } else if (ln.at(y) == '_') {
                ln.at(y) = ' ';
            }
        }
        n2->setText(ln);
    } else 
        n2->setText("empty");
    if (noblesPrivilegies.size() >= 3) {
        std::string ln = noblesPrivilegies.at(2).substr(14, noblesPrivilegies.at(2).size());
        int under = 0;
        for (int y = 0; (size_t)y < ln.size(); y++) {
            if (ln.at(y) == '_' && under == 0) {
                under++;
                ln.at(y) = '\n';
            } else if (ln.at(y) == '_') {
                ln.at(y) = ' ';
            }
        }
        n3->setText(ln);
    } else 
        n3->setText("empty");
    if (noblesPrivilegies.size() >= 4) {
        std::string ln = noblesPrivilegies.at(3).substr(14, noblesPrivilegies.at(3).size());
        int under = 0;
        for (int y = 0; (size_t)y < ln.size(); y++) {
            if (ln.at(y) == '_' && under == 0) {
                under++;
                ln.at(y) = '\n';
            } else if (ln.at(y) == '_') {
                ln.at(y) = ' ';
            }
        }
        n4->setText(ln);
    } else 
        n4->setText("empty");
}

void OrderScene::clergy() {    
    c1 = new QButton(*this->bas->getWidgets());
    c2 = new QButton(*this->bas->getWidgets());
    c3 = new QButton(*this->bas->getWidgets());
    c4 = new QButton(*this->bas->getWidgets());
    Label estateName(*this->bas->getWidgets());

    estateName.move(30, 370);
    estateName.setText("clergy");
    estateName.show(true);

    c1->move(105, 350);
    c1->setSize(90, 50);
    c2->move(205, 350);
    c2->setSize(90, 50);
    c3->move(305, 350);
    c3->setSize(90, 50);
    c4->move(405, 350);
    c4->setSize(90, 50);
    if (clericalPrivilegies.size() >= 1) {
        std::string ln = clericalPrivilegies.at(0).substr(14, clericalPrivilegies.at(0).size());
        int under = 0;
        for (int y = 0; (size_t)y < ln.size(); y++) {
            if (ln.at(y) == '_' && under == 0) {
                under++;
                ln.at(y) = '\n';
            } else if (ln.at(y) == '_') {
                ln.at(y) = ' ';
            }
        }
        c1->setText(ln);
    } else 
        c1->setText("empty");
    if (clericalPrivilegies.size() >= 2) {
        std::string ln = clericalPrivilegies.at(1).substr(14, clericalPrivilegies.at(1).size());
        int under = 0;
        for (int y = 0; (size_t)y < ln.size(); y++) {
            if (ln.at(y) == '_' && under == 0) {
                under++;
                ln.at(y) = '\n';
            } else if (ln.at(y) == '_') {
                ln.at(y) = ' ';
            }
        }
        c2->setText(ln);
    } else 
        c2->setText("empty");
    if (clericalPrivilegies.size() >= 3) {
        std::string ln = clericalPrivilegies.at(2).substr(14, clericalPrivilegies.at(2).size());
        int under = 0;
        for (int y = 0; (size_t)y < ln.size(); y++) {
            if (ln.at(y) == '_' && under == 0) {
                under++;
                ln.at(y) = '\n';
            } else if (ln.at(y) == '_') {
                ln.at(y) = ' ';
            }
        }
        c3->setText(ln);
    } else 
        c3->setText("empty");
    if (clericalPrivilegies.size() >= 4) {
        std::string ln = clericalPrivilegies.at(3).substr(14, clericalPrivilegies.at(3).size());
        int under = 0;
        for (int y = 0; (size_t)y < ln.size(); y++) {
            if (ln.at(y) == '_' && under == 0) {
                under++;
                ln.at(y) = '\n';
            } else if (ln.at(y) == '_') {
                ln.at(y) = ' ';
            }
        }
        c4->setText(ln);
    } else 
        c4->setText("empty");
}

void OrderScene::connectBurghers() {
    b1->connect([this](){
        newPrivilegies(allBurghers, 1);
    });
    b2->connect([this](){
        newPrivilegies(allBurghers, 2);
    });
    b3->connect([this](){
        newPrivilegies(allBurghers, 3);
    });
    b4->connect([this](){
        newPrivilegies(allBurghers, 4);
    });
}

void OrderScene::connectClergy() {
    c1->connect([this](){
        newPrivilegies(allChurch, 5);
    });
    c2->connect([this](){
        newPrivilegies(allChurch, 6);
    });
    c3->connect([this](){
        newPrivilegies(allChurch, 7);
    });
    c4->connect([this](){
        newPrivilegies(allChurch, 8);
    });
}

void OrderScene::connectNobles() {
    n1->connect([this](){
        newPrivilegies(allNobles, 9);
    });
    n2->connect([this](){
        newPrivilegies(allNobles, 10);
    });
    n3->connect([this](){
        newPrivilegies(allNobles, 11);
    });
    n4->connect([this](){
        newPrivilegies(allNobles, 12);
    });
}

void OrderScene::newPrivilegies(std::vector<std::string> orders, int nbt) {
    newPrivilegie = new Widget;
    Label *Pr = new Label(*newPrivilegie->getWidgets());
    Pr->setSize(200, 60 + 60 * orders.size());
    nP.clear();
    this->bt = nbt;

    if (orders.at(0).substr(0, 15) == "estate_burghers") {
        QButton *add1 = new QButton(*Pr->getWidgets());
        QButton *add2 = new QButton(*Pr->getWidgets());
        QButton *add3 = new QButton(*Pr->getWidgets());
        QButton *add4 = new QButton(*Pr->getWidgets());
        QButton *add5 = new QButton(*Pr->getWidgets());
        QButton *add6 = new QButton(*Pr->getWidgets());
        QButton *add7 = new QButton(*Pr->getWidgets());
        QButton *add8 = new QButton(*Pr->getWidgets());
        QButton *add9 = new QButton(*Pr->getWidgets());
        QButton *add10 = new QButton(*Pr->getWidgets());
        nP.push_back(add1);
        nP.push_back(add2);
        nP.push_back(add3);
        nP.push_back(add4);
        nP.push_back(add5);
        nP.push_back(add6);
        nP.push_back(add7);
        nP.push_back(add8);
        nP.push_back(add9);
        nP.push_back(add10);
    }
    else {
        QButton *add1 = new QButton(*Pr->getWidgets());
        QButton *add2 = new QButton(*Pr->getWidgets());
        QButton *add3 = new QButton(*Pr->getWidgets());
        QButton *add4 = new QButton(*Pr->getWidgets());
        QButton *add5 = new QButton(*Pr->getWidgets());
        QButton *add6 = new QButton(*Pr->getWidgets());
        QButton *add7 = new QButton(*Pr->getWidgets());
        QButton *add8 = new QButton(*Pr->getWidgets());
        QButton *add9 = new QButton(*Pr->getWidgets());
        QButton *add10 = new QButton(*Pr->getWidgets());
        nP.push_back(add1);
        nP.push_back(add2);
        nP.push_back(add3);
        nP.push_back(add4);
        nP.push_back(add5);
        nP.push_back(add6);
        nP.push_back(add7);
        nP.push_back(add8);
        nP.push_back(add9);
        nP.push_back(add10);
    }
    for (int i = 0; 10 > (size_t)i; i++) {
        nP.at(i)->setSize(190, 50);
        nP.at(i)->move(5, 5 + 60 * i);
        if (i < 9) {
            std::string ln = orders.at(i);
            int under = 0;

            for (int y = 0; (size_t)y < ln.size() && under < 2; y++)
                if (ln.at(y) == '_') {
                    under++;
                    ln = ln.substr(y, ln.size());
                }
            under = 0;
            if (ln.at(0) == '_')
                ln = ln.substr(1, ln.size());
            for (int y = 0; (size_t)y < ln.size(); y++) {
                if (ln.at(y) == '_' && under == 0) {
                    under++;
                    ln.at(y) = '\n';
                } else if (ln.at(y) == '_') {
                    ln.at(y) = ' ';
                }
            }
            nP.at(i)->setText(ln);
        } else {
            nP.at(i)->setText("empty");
        }
        nP.at(i)->show(true);
    }
    nP.at(0)->connect([this](){
        toR = nP.at(0)->getText();
        rWrite(bt);
    });
    nP.at(1)->connect([this](){
        toR = nP.at(1)->getText();
        rWrite(bt);
    });
    nP.at(2)->connect([this](){
        toR = nP.at(2)->getText();
        rWrite(bt);
    });
    nP.at(3)->connect([this](){
        toR = nP.at(3)->getText();
        rWrite(bt);
    });
    nP.at(4)->connect([this](){
        toR = nP.at(4)->getText();
        rWrite(bt);
    });
    nP.at(5)->connect([this](){
        toR = nP.at(5)->getText();
        rWrite(bt);
    });
    nP.at(6)->connect([this](){
        toR = nP.at(6)->getText();
        rWrite(bt);
    });
    nP.at(7)->connect([this](){
        toR = nP.at(7)->getText();
        rWrite(bt);
    });
    nP.at(8)->connect([this](){
        toR = nP.at(8)->getText();
        rWrite(bt);
    });
    nP.at(9)->connect([this](){
        toR = nP.at(9)->getText();
        rWrite(bt);
    });
    newPrivilegie->show(true);
}

void OrderScene::rWrite(int bt) {
    if (bt == 1) {
        b1->setText(toR);
    }
    if (bt == 2)
        b2->setText(toR);
    if (bt == 3)
        b3->setText(toR);
    if (bt == 4)
        b4->setText(toR);
    if (bt == 5)
        c1->setText(toR);
    if (bt == 6)
        c2->setText(toR);
    if (bt == 7)
        c3->setText(toR);
    if (bt == 8)
        c4->setText(toR);
    if (bt == 9)
        n1->setText(toR);
    if (bt == 10)
        n2->setText(toR);
    if (bt == 11)
        n3->setText(toR);
    if (bt == 12)
        n4->setText(toR);
    std::vector<teuton::parser::Estates> change = this->estates;
    teuton::parser::Estates noble;
    teuton::parser::Estates burgher;
    teuton::parser::Estates clerg;
    for (int i = 0; (size_t)i < change.size(); i++) {
        if (change.at(i).getType().substr(1, change.at(i).getType().size() - 2) == "estate_nobles") {
            std::vector<std::string> newP;
            if (n1->getText() != "empty") {
                std::string ln = "estate_nobles_" + n1->getText();
                for (int x = 0; (size_t)x < ln.size(); x++)
                    if (ln.at(x) == '\n')
                        ln.at(x) = '_';
                newP.push_back(ln);
            }
            if (n2->getText() != "empty") {
                std::string ln = "estate_nobles_" + n2->getText();
                for (int x = 0; (size_t)x < ln.size(); x++)
                    if (ln.at(x) == '\n')
                        ln.at(x) = '_';
                newP.push_back(ln);
            }
            if (n3->getText() != "empty") {
                std::string ln = "estate_nobles_" + n3->getText();
                for (int x = 0; (size_t)x < ln.size(); x++)
                    if (ln.at(x) == '\n')
                        ln.at(x) = '_';
                newP.push_back(ln);
            }
            if (n4->getText() != "empty") {
                std::string ln = "estate_nobles_" + n4->getText();
                for (int x = 0; (size_t)x < ln.size(); x++)
                    if (ln.at(x) == '\n')
                        ln.at(x) = '_';
                newP.push_back(ln);
            }
            change.at(i).changePrivileges(newP);
        }
        if (change.at(i).getType().substr(1, change.at(i).getType().size() - 2) == "estate_burghers") {
            std::vector<std::string> newP;
            if (b1->getText() != "empty") {
                std::string ln = "estate_burghers_" + b1->getText();
                for (int x = 0; (size_t)x < ln.size(); x++)
                    if (ln.at(x) == '\n')
                        ln.at(x) = '_';
                newP.push_back(ln);
            }
            if (b2->getText() != "empty") {
                std::string ln = "estate_burghers_" + b2->getText();
                for (int x = 0; (size_t)x < ln.size(); x++)
                    if (ln.at(x) == '\n')
                        ln.at(x) = '_';
                newP.push_back(ln);
            }
            if (b3->getText() != "empty") {
                std::string ln = "estate_burghers_" + b3->getText();
                for (int x = 0; (size_t)x < ln.size(); x++)
                    if (ln.at(x) == '\n')
                        ln.at(x) = '_';
                newP.push_back(ln);
            }
            if (b4->getText() != "empty") {
                std::string ln = "estate_burghers_" + b4->getText();
                for (int x = 0; (size_t)x < ln.size(); x++)
                    if (ln.at(x) == '\n')
                        ln.at(x) = '_';
                newP.push_back(ln);
            }
            change.at(i).changePrivileges(newP);
        }
        if (change.at(i).getType().substr(1, change.at(i).getType().size() - 2) == "estate_church") {
            std::vector<std::string> newP;
            if (c1->getText() != "empty") {
                std::string ln = "estate_church_" + c1->getText();
                for (int x = 0; (size_t)x < ln.size(); x++)
                    if (ln.at(x) == '\n')
                        ln.at(x) = '_';
                newP.push_back(ln);
            }
            if (c2->getText() != "empty") {
                std::string ln = "estate_church_" + c2->getText();
                for (int x = 0; (size_t)x < ln.size(); x++)
                    if (ln.at(x) == '\n')
                        ln.at(x) = '_';
                newP.push_back(ln);
            }
            if (c3->getText() != "empty") {
                std::string ln = "estate_church_" + c3->getText();
                for (int x = 0; (size_t)x < ln.size(); x++)
                    if (ln.at(x) == '\n')
                        ln.at(x) = '_';
                newP.push_back(ln);
            }
            if (c4->getText() != "empty") {
                std::string ln = "estate_church_" + c4->getText();
                for (int x = 0; (size_t)x < ln.size(); x++)
                    if (ln.at(x) == '\n')
                        ln.at(x) = '_';
                newP.push_back(ln);
            }
            change.at(i).changePrivileges(newP);
        }
    }
    this->estates = change;
    this->newPrivilegie->show(false);
}

OrderScene::~OrderScene() {} 

void OrderScene::setVisible(bool show) {
    this->_OrderScene->show(show);
}

std::vector<QWidget*> OrderScene::getWidgets() {
    return this->_local;
}

std::vector<teuton::parser::Estates> OrderScene::getNewInfo() {
    return this->estates;
}

QButton* OrderScene::getReturn() {
    return this->_Return;
}