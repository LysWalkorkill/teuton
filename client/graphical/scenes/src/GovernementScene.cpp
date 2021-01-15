#include "../include/GovernmentScene.hpp"

using namespace teuton::graphical;

GovernementScene::GovernementScene(std::string name, teuton::parser::Government government) {
    this->_GovernementScene = new Widget;
    this->government = government;
    this->_GovernementScene->setSize(500, 600);
    this->_GovernementScene->setTransparentBackground(false);

    this->haut = new Label(*_GovernementScene->getWidgets());
    this->haut->setSize(500, 50);
    this->Name = new Label(*haut->getWidgets());
    this->Name->move(200, 22);
    this->Name->setText("Government");
    this->_Return = new QButton(*haut->getWidgets());
    this->_Return->move(0,0);
    this->_Return->setSize(50, 50);
    this->_Return->setText("back");
    this->haut->setStyleSheet("background-color: red");
    this->_Return->setStyleSheet("background-color: grey");

    this->reset();
    this->connect();
}

GovernementScene::~GovernementScene() {} 

void GovernementScene::connect() {
    std::vector<std::string> t1 = {"feudalism_reform","autocracy_reform"};
    std::vector<std::string> t2 = {"enforce_privileges_reform", "quash_noble_power_reform", "enforce_trader_privileges_reform"};
    std::vector<std::string> t3 = {"centralize_reform", "decentralize_reform"};
    std::vector<std::string> t4 = {"clergy_in_administration_reform", "of_noble_bearing_reform","meritocratic_focus_reform"};
    std::vector<std::string> t5 = {"royal_decree_reform", "aristocratic_court_reform","states_general_reform", "general_estates_reform"};
 
    this->gName->connect([this](){
        this->dGName = new DialogBox("new government name", "write new government name", DialogBox::TEXT, this->gName->getWidgets());
        teuton::parser::Government newG = this->getNewInfo();
        if (this->dGName->getText() != "") {
            newG.setGovernmentName('"' + this->dGName->getText() + '"');
            this->setNewInfo(newG);
            this->gName->setText(this->dGName->getText());
        }
    });
    this->g->connect([this](){
        this->dG = new DialogBox("new government", "write new government", DialogBox::TEXT, this->g->getWidgets());
        teuton::parser::Government newG = this->getNewInfo();
        if (this->dG->getText() != "") {
            newG.setGovernment('"' + this->dG->getText() + '"');
            this->setNewInfo(newG);
            this->g->setText(this->dG->getText());
        }
    });
    this->gRankUp->connect([this](){
        if (this->getNewInfo().getGovernmentRank() != 3) {
            teuton::parser::Government newG = this->getNewInfo();
            newG.setGovernmentRank(newG.getGovernmentRank() + 1);
            this->setNewInfo(newG);
            if (newG.getGovernmentRank() == 2)
                this->gRank->setText("government Rank :\nKingdom");
            else
                this->gRank->setText("government Rank :\nEmpire");
        }
    });
    this->gRankDown->connect([this](){
        if (this->getNewInfo().getGovernmentRank() != 1) {
            teuton::parser::Government newG = this->getNewInfo();
            newG.setGovernmentRank(newG.getGovernmentRank() - 1);
            this->setNewInfo(newG);
            if (newG.getGovernmentRank() == 2)
                this->gRank->setText("government Rank :\nKingdom");
            else
                this->gRank->setText("government Rank :\nDuchy");
        }
    });

    this->tier1.at(0).bt->connect([this, t1](){
        for (int i = 0; (size_t)i != tier1.size(); i++)
            this->tier1.at(i).lb->setStyleSheet("background-color: red");
        this->tier1.at(0).lb->setStyleSheet("background-color: green");
        this->government.changeReform(1,'"' + t1.at(0) + '"');
    });
    this->tier1.at(1).bt->connect([this, t1](){
        for (int i = 0; (size_t)i != tier1.size(); i++)
            this->tier1.at(i).lb->setStyleSheet("background-color: red");
        this->tier1.at(1).lb->setStyleSheet("background-color: green");
        this->government.changeReform(1, '"'+ t1.at(1)+'"');
    });
    if (tier1.size() == 3)
        this->tier1.at(2).bt->connect([this, t1](){
            for (int i = 0; (size_t)i != tier1.size(); i++)
                this->tier1.at(i).lb->setStyleSheet("background-color: red");
            this->tier1.at(2).lb->setStyleSheet("background-color: green");
            this->government.changeReform(1,this->tier1.at(2).refrom);
    });

    this->tier2.at(0).bt->connect([this, t2](){
        for (int i = 0; (size_t)i != tier2.size(); i++)
            this->tier2.at(i).lb->setStyleSheet("background-color: red");
        this->tier2.at(0).lb->setStyleSheet("background-color: green");
        if (this->government.getReform().size() <= 2)
            this->government.addReform('"' + t2.at(0) + '"');
        this->government.changeReform(2, '"' + t2.at(0) + '"');
    });
    this->tier2.at(1).bt->connect([this, t2](){
        for (int i = 0; (size_t)i != tier2.size(); i++)
            this->tier2.at(i).lb->setStyleSheet("background-color: red");
        this->tier2.at(1).lb->setStyleSheet("background-color: green");
        if (this->government.getReform().size() <= 2)
            this->government.addReform('"' + t2.at(0) + '"');
        this->government.changeReform(2, '"' + t2.at(1) + '"');
    });
    this->tier2.at(2).bt->connect([this, t2](){
        for (int i = 0; (size_t)i != tier2.size(); i++)
            this->tier2.at(i).lb->setStyleSheet("background-color: red");
        this->tier2.at(2).lb->setStyleSheet("background-color: green");
        if (this->government.getReform().size() <= 2)
            this->government.addReform('"' + t2.at(0) + '"');
        this->government.changeReform(2, '"' + t2.at(2) + '"');
    });
    if (tier2.size() == 4)
        this->tier2.at(3).bt->connect([this, t2](){
            for (int i = 0; (size_t)i != tier2.size(); i++)
                this->tier2.at(i).lb->setStyleSheet("background-color: red");
            this->tier2.at(3).lb->setStyleSheet("background-color: green");
            if (this->government.getReform().size() <= 2)
                this->government.addReform('"' + t2.at(0) + '"');
            this->government.changeReform(1,this->tier2.at(3).refrom);
    });

    this->tier3.at(0).bt->connect([this, t3](){
        for (int i = 0; (size_t)i != tier3.size(); i++)
            this->tier3.at(i).lb->setStyleSheet("background-color: red");
        this->tier3.at(0).lb->setStyleSheet("background-color: green");
        if (this->government.getReform().size() <= 3)
            this->government.addReform('"' + t3.at(0) + '"');
        this->government.changeReform(3,  '"' + t3.at(0) + '"');
    });
    this->tier3.at(1).bt->connect([this, t3](){
        for (int i = 0; (size_t)i != tier3.size(); i++)
            this->tier3.at(i).lb->setStyleSheet("background-color: red");
        this->tier3.at(1).lb->setStyleSheet("background-color: green");
        if (this->government.getReform().size() <= 3)
            this->government.addReform('"' + t3.at(0) + '"');
        this->government.changeReform(3,  '"' + t3.at(1) + '"');
    });
    if (tier3.size() == 3)
        this->tier3.at(2).bt->connect([this, t3](){
            for (int i = 0; (size_t)i != tier3.size(); i++)
                this->tier3.at(i).lb->setStyleSheet("background-color: red");
            this->tier3.at(2).lb->setStyleSheet("background-color: green");
            if (this->government.getReform().size() <= 3)
                this->government.addReform('"' + t3.at(0) + '"');
            this->government.changeReform(3,  this->tier3.at(2).refrom);
    });

    this->tier4.at(0).bt->connect([this, t4](){
        for (int i = 0; (size_t)i != tier4.size(); i++)
            this->tier4.at(i).lb->setStyleSheet("background-color: red");
        this->tier4.at(0).lb->setStyleSheet("background-color: green");
        if (this->government.getReform().size() <= 4)
            this->government.addReform('"' + t4.at(0) + '"');
        this->government.changeReform(4, '"' + t4.at(0) + '"');
    });
    this->tier4.at(1).bt->connect([this, t4](){
        for (int i = 0; (size_t)i != tier4.size(); i++)
            this->tier4.at(i).lb->setStyleSheet("background-color: red");
        this->tier4.at(1).lb->setStyleSheet("background-color: green");
        if (this->government.getReform().size() <= 4)
            this->government.addReform('"' + t4.at(0) + '"');
        this->government.changeReform(4, '"' + t4.at(1) + '"');
    });
    this->tier4.at(2).bt->connect([this, t4](){
        for (int i = 0; (size_t)i != tier4.size(); i++)
            this->tier4.at(i).lb->setStyleSheet("background-color: red");
        this->tier4.at(2).lb->setStyleSheet("background-color: green");
        if (this->government.getReform().size() <= 4)
            this->government.addReform('"' + t4.at(0) + '"');
        this->government.changeReform(4, '"' + t4.at(2) + '"');
    });
    if (tier4.size() == 4)
        this->tier4.at(3).bt->connect([this, t4](){
            for (int i = 0; (size_t)i != tier4.size(); i++)
                this->tier4.at(i).lb->setStyleSheet("background-color: red");
            this->tier4.at(3).lb->setStyleSheet("background-color: green");
            if (this->government.getReform().size() <= 4)
                this->government.addReform('"' + t4.at(0) + '"');
            this->government.changeReform(4, this->tier4.at(3).refrom);
    });

    this->tier5.at(0).bt->connect([this, t5](){
        for (int i = 0; (size_t)i != tier5.size(); i++)
            this->tier5.at(i).lb->setStyleSheet("background-color: red");
        this->tier5.at(0).lb->setStyleSheet("background-color: green");
        if (this->government.getReform().size() <= 5)
            this->government.addReform('"' + t5.at(0) + '"');
        this->government.changeReform(5, '"' + t5.at(0) + '"');
    });
    this->tier5.at(1).bt->connect([this, t5](){
        for (int i = 0; (size_t)i != tier5.size(); i++)
            this->tier5.at(i).lb->setStyleSheet("background-color: red");
        this->tier5.at(1).lb->setStyleSheet("background-color: green");
        if (this->government.getReform().size() <= 5)
            this->government.addReform('"' + t5.at(0) + '"');
        this->government.changeReform(5, '"' + t5.at(1) + '"');
    });
    this->tier5.at(2).bt->connect([this, t5](){
        for (int i = 0; (size_t)i != tier5.size(); i++)
            this->tier5.at(i).lb->setStyleSheet("background-color: red");
        this->tier5.at(2).lb->setStyleSheet("background-color: green");
        if (this->government.getReform().size() <= 5)
            this->government.addReform('"' + t5.at(0) + '"');
        this->government.changeReform(5, '"' + t5.at(2) + '"');
    });
    this->tier5.at(3).bt->connect([this, t5](){
        for (int i = 0; (size_t)i != tier5.size(); i++)
            this->tier5.at(i).lb->setStyleSheet("background-color: red");
        this->tier5.at(3).lb->setStyleSheet("background-color: green");
        if (this->government.getReform().size() <= 5)
            this->government.addReform('"' + t5.at(0) + '"');
        this->government.changeReform(5, '"' + t5.at(3) + '"');
    });
    if (tier5.size() == 5)
        this->tier5.at(4).bt->connect([this, t5](){
            for (int i = 0; (size_t)i != tier5.size(); i++)
                this->tier5.at(i).lb->setStyleSheet("background-color: red");
            this->tier5.at(4).lb->setStyleSheet("background-color: green");
            if (this->government.getReform().size() <= 5)
                this->government.addReform('"' + t5.at(0) + '"');
            this->government.changeReform(5,  this->tier5.at(4).refrom);
    });
}

void GovernementScene::reset() {
    this->middle = new Label(*_GovernementScene->getWidgets());
    this->middle->move(0, 50);
    this->middle->setSize(500, 100);
    this->gRank = new Label(*middle->getWidgets());
    if (government.getGovernmentRank() == 1)
        this->gRank->setText("government Rank :\nDuchy");
    if (government.getGovernmentRank() == 2)
        this->gRank->setText("government Rank :\nKingdom");
    if (government.getGovernmentRank() == 3)
        this->gRank->setText("government Rank :\nEmpire");
    this->gRank->move(50, 25);
    this->gRankUp = new QButton(*middle->getWidgets());
    this->gRankDown = new QButton(*middle->getWidgets());
    this->gRankDown->setSize(75, 50);
    this->gRankUp->setSize(75, 50);
    this->gRankDown->move(25, 50);
    this->gRankUp->move(100, 50);
    this->gRankDown->setText("rank down");
    this->gRankUp->setText("rank up");
    this->middle->setStyleSheet("background-color: green");
    this->gRankDown->setStyleSheet("background-color: red");
    this->gRankUp->setStyleSheet("background-color: green");
    this->gName = new QButton(*middle->getWidgets());
    this->g = new QButton(*middle->getWidgets());
    this->gName->move(300, 25);
    this->g->move(300, 50);
    this->gName->setSize(150, 25);
    this->g->setSize(150, 25);
    this->gName->setText(government.getGovernmentName().substr(1, government.getGovernmentName().size() - 2));
    this->g->setText(government.getGovernment().substr(1, government.getGovernment().size() - 2));
    this->gName->setStyleSheet("background-color: grey");
    this->g->setStyleSheet("background-color: grey");

    this->g->show(false);

    this->bas = new Label(*_GovernementScene->getWidgets());
    this->bas->move(0, 150);
    this->bas->setSize(500, 450);
    int x = 0;
    int y = 0;
    int size = government.getReform().size();
    std::vector<std::string> t1 = {"feudalism_reform","autocracy_reform"};
    std::vector<std::string> t2 = {"enforce_privileges_reform", "quash_noble_power_reform", "enforce_trader_privileges_reform"};
    std::vector<std::string> t3 = {"centralize_reform", "decentralize_reform"};
    std::vector<std::string> t4 = {"clergy_in_administration_reform", "of_noble_bearing_reform","meritocratic_focus_reform"};
    std::vector<std::string> t5 = {"royal_decree_reform", "aristocratic_court_reform","states_general_reform", "general_estates_reform"};
    std::vector<std::string> tt1 = {"feudalism","autocracy"};
    std::vector<std::string> tt2 = {"enforce\nprivileges", "quash\nnoble power", "enforce trader\nprivileges"};
    std::vector<std::string> tt3 = {"centralize", "decentralize"};
    std::vector<std::string> tt4 = {"clergy in\nadministration", "of noble\nbearing","meritocratic\nfocus"};
    std::vector<std::string> tt5 = {"royal decree", "aristocratic\ncourt","states\ngeneral", "general\nestates"};
    bool found = false;

    for (int i = 0; size_t(i) != tt1.size(); i++) {
        tier cp;
        cp.bt = new QButton(*bas->getWidgets());
        cp.lb = new Label(*bas->getWidgets());
        cp.bt->setSize(105, 60);
        cp.lb->setSize(10, 10);
        cp.bt->move(10 + (125 * x), 15 + (90 * y));
        cp.lb->move(110 + (125 * x), 60 + (90 * y));
        cp.bt->setText(tt1.at(i));
        cp.bt->setStyleSheet("background-color: grey");
        if ('"' + (t1.at(i) + '"') == government.getReform().at(1)) {
            cp.lb->setStyleSheet("background-color: green");
            found = true;
        } else
            cp.lb->setStyleSheet("background-color: red");
        tier1.push_back(cp);
        x++;
    }
    tier cp1;
    if (!found && size > 1) {
        cp1.bt = new QButton(*bas->getWidgets());
        cp1.lb = new Label(*bas->getWidgets());
        cp1.bt->setSize(105, 60);
        cp1.lb->setSize(10, 10);
        cp1.bt->move(10 + (125 * x), 15 + (90 * y));
        cp1.lb->move(110 + (125 * x), 60 + (90 * y));
        cp1.refrom = government.getReform().at(1);
        std::string lcl = government.getReform().at(1).substr(0, government.getReform().at(1).size() - 8);
        lcl += '"';
        cp1.bt->setText(lcl);
        cp1.bt->setStyleSheet("background-color: grey");
        cp1.lb->setStyleSheet("background-color: green");
        tier1.push_back(cp1);
    }
    x = 0;
    y++;
    found = false;
    for (int i = 0; size_t(i) != tt2.size(); i++) {
        tier cp;
        cp.bt = new QButton(*bas->getWidgets());
        cp.lb = new Label(*bas->getWidgets());
        cp.bt->setSize(105, 60);
        cp.lb->setSize(10, 10);
        cp.bt->move(10 + (125 * x), 15 + (90 * y));
        cp.lb->move(110 + (125 * x), 60 + (90 * y));
        cp.bt->setText(tt2.at(i));
        cp.bt->setStyleSheet("background-color: grey");
        if (government.getReform().size() > 2 && ('"' + t2.at(i) + '"') == government.getReform().at(2)) {
            cp.lb->setStyleSheet("background-color: green");
            found = true;
        } else
            cp.lb->setStyleSheet("background-color: red");
        tier2.push_back(cp);
        x++;
    }
    tier cp2;
    if (!found && size > 2) {
        cp2.bt = new QButton(*bas->getWidgets());
        cp2.lb = new Label(*bas->getWidgets());
        cp2.bt->setSize(105, 60);
        cp2.lb->setSize(10, 10);
        cp2.bt->move(10 + (125 * x), 15 + (90 * y));
        cp2.lb->move(110 + (125 * x), 60 + (90 * y));
        cp2.refrom = government.getReform().at(2);
        std::string lcl = government.getReform().at(2).substr(0, government.getReform().at(2).size() - 8);
        lcl += '"';
        cp2.bt->setStyleSheet("background-color: grey");
        cp2.lb->setStyleSheet("background-color: green");
        tier2.push_back(cp2);
    }
    x = 0;
    y++;
    found = false;
        for (int i = 0; size_t(i) != tt3.size(); i++) {
        tier cp;
        cp.bt = new QButton(*bas->getWidgets());
        cp.lb = new Label(*bas->getWidgets());
        cp.bt->setSize(105, 60);
        cp.lb->setSize(10, 10);
        cp.bt->move(10 + (125 * x), 15 + (90 * y));
        cp.lb->move(110 + (125 * x), 60 + (90 * y));
        cp.bt->setText(tt3.at(i));
        cp.bt->setStyleSheet("background-color: grey");
        if (government.getReform().size() > 3 && ('"' + t3.at(i) + '"') == government.getReform().at(3)) {
            cp.lb->setStyleSheet("background-color: green");
            found = true;
        } else
            cp.lb->setStyleSheet("background-color: red");
        tier3.push_back(cp);
        x++;
    }
    tier cp3;
    if (!found && size > 3) {
        cp3.bt = new QButton(*bas->getWidgets());
        cp3.lb = new Label(*bas->getWidgets());
        cp3.bt->setSize(105, 60);
        cp3.lb->setSize(10, 10);
        cp3.bt->move(10 + (125 * x), 15 + (90 * y));
        cp3.lb->move(110 + (125 * x), 60 + (90 * y));
        cp3.refrom = government.getReform().at(3);
        std::string lcl = government.getReform().at(3).substr(0, government.getReform().at(3).size() - 8);
        lcl += '"';
        cp3.bt->setStyleSheet("background-color: grey");
        cp3.lb->setStyleSheet("background-color: green");
        tier3.push_back(cp3);
    }
    x = 0;
    y++;
    found = false;
        for (int i = 0; size_t(i) != tt4.size(); i++) {
        tier cp;
        cp.bt = new QButton(*bas->getWidgets());
        cp.lb = new Label(*bas->getWidgets());
        cp.bt->setSize(105, 60);
        cp.lb->setSize(10, 10);
        cp.bt->move(10 + (125 * x), 15 + (90 * y));
        cp.lb->move(110 + (125 * x), 60 + (90 * y));
        cp.bt->setText(tt4.at(i));
        cp.bt->setStyleSheet("background-color: grey");
        if (government.getReform().size() > 4 && ('"' + t4.at(i) + '"') == government.getReform().at(4)) {
            cp.lb->setStyleSheet("background-color: green");
            found = true;
        } else
            cp.lb->setStyleSheet("background-color: red");
        tier4.push_back(cp);
        x++;
    }
    tier cp4;
    if (!found && size > 4) {
        cp4.bt = new QButton(*bas->getWidgets());
        cp4.lb = new Label(*bas->getWidgets());
        cp4.bt->setSize(105, 60);
        cp4.lb->setSize(10, 10);
        cp4.bt->move(10 + (125 * x), 15 + (90 * y));
        cp4.lb->move(110 + (125 * x), 60 + (90 * y));
        cp4.refrom = government.getReform().at(4);
        std::string lcl = government.getReform().at(4).substr(0, government.getReform().at(4).size() - 8);
        lcl += '"';
        cp4.bt->setStyleSheet("background-color: grey");
        cp4.lb->setStyleSheet("background-color: green");
        tier4.push_back(cp4);
    }
    x = 0;
    y++;
    found = false;
        for (int i = 0; size_t(i) != tt5.size(); i++) {
        tier cp;
        cp.bt = new QButton(*bas->getWidgets());
        cp.lb = new Label(*bas->getWidgets());
        cp.bt->setSize(105, 60);
        cp.lb->setSize(10, 10);
        cp.bt->move(10 + (125 * x), 15 + (90 * y));
        cp.lb->move(110 + (125 * x), 60 + (90 * y));
        cp.bt->setText(tt5.at(i));
        cp.bt->setStyleSheet("background-color: grey");
        if (government.getReform().size() > 5 && ('"' + t5.at(i) + '"') == government.getReform().at(5)) {
            cp.lb->setStyleSheet("background-color: green");
            found = true;
        } else
            cp.lb->setStyleSheet("background-color: red");
        tier5.push_back(cp);
        x++;
    }
    tier cp5;
    if (!found && size > 5) {
        x--;
        cp5.bt = new QButton(*bas->getWidgets());
        cp5.lb = new Label(*bas->getWidgets());
        cp5.bt->setSize(105, 60);
        cp5.lb->setSize(10, 10);
        cp5.bt->move(10 + (125 * x), 15 + (90 * y));
        cp5.lb->move(110 + (125 * x), 60 + (90 * y));
        cp5.refrom = government.getReform().at(5);
        std::string lcl = government.getReform().at(5).substr(0, government.getReform().at(5).size() - 8);
        lcl += '"';
        cp5.bt->setStyleSheet("background-color: grey");
        cp5.lb->setStyleSheet("background-color: green");
        tier5.push_back(cp5);
    }
    x = 0;
    y++;
    found = false;
}

void GovernementScene::setNewInfo(teuton::parser::Government gov) {
    this->government = gov;
}

void GovernementScene::setVisible(bool show) {
    this->_GovernementScene->show(show);
}

std::vector<QWidget*> GovernementScene::getWidgets() {
    return this->_local;
}

teuton::parser::Government GovernementScene::getNewInfo() {
    return this->government;
}

QButton* GovernementScene::getReturn() {
    return this->_Return;
}