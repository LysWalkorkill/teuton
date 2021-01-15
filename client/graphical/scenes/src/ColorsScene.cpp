#include "../include/ColorsScene.hpp"

using namespace teuton::graphical;

ColorsScene::ColorsScene(std::string name, teuton::parser::Colors colors) {
    this->_ColorsScene = new Widget;
    this->colors = colors;

    this->haut = new Label(*_ColorsScene->getWidgets());
    this->_Return = new QButton(*haut->getWidgets());
    this->_Return->move(0,0);
    this->_Return->setSize(50, 50);
    this->_Return->setText("back");
    this->_Return->setStyleSheet("background-color: grey");
    this->_Return->show(true);
    Label *Name = new Label(*haut->getWidgets());
    Name->move(225, 22);
    Name->setText("Colors");
    this->middle = new Label(*_ColorsScene->getWidgets());
    Label *exp = new Label(*middle->getWidgets());
    exp->move(175, 50);
    exp->setText("this are RGB colors");
    this->bas  = new Label(*_ColorsScene->getWidgets());
    this->name1 = new Label(*bas->getWidgets());
    this->name2 = new Label(*bas->getWidgets());
    this->name3 = new Label(*bas->getWidgets());
    this->colors1 = new Label(*bas->getWidgets());
    this->colors2 = new Label(*bas->getWidgets());
    this->colors3 = new Label(*bas->getWidgets());
    this->cC1 = new QButton(*bas->getWidgets());
    this->cC2 = new QButton(*bas->getWidgets());
    this->cC3 = new QButton(*bas->getWidgets());
    this->cC4 = new QButton(*bas->getWidgets());
    this->cC5 = new QButton(*bas->getWidgets());
    this->cC6 = new QButton(*bas->getWidgets());
    this->cC7 = new QButton(*bas->getWidgets());
    this->cC8 = new QButton(*bas->getWidgets());
    this->cC9 = new QButton(*bas->getWidgets());

    this->haut->setSize(500, 50);
    this->haut->setStyleSheet("background-color: red");
    this->middle->move(0, 50);
    this->middle->setSize(500, 100);
    this->middle->setStyleSheet("background-color: green");
    this->bas->move(0, 150);
    this->bas->setSize(500, 450);

    this->name1->move(100, 50);
    this->name2->move(100, 200);
    this->name3->move(100, 350);
    this->name1->setSize(100, 25);
    this->name2->setSize(200, 25);
    this->name3->setSize(100, 25);
    this->name1->setText("country colors");
    this->name2->setText("revolutionary colors");
    this->name3->setText("border colors");

    this->cC1->move(100, 75);
    this->cC2->move(200, 75);
    this->cC3->move(300, 75);
    this->cC4->move(100, 225);
    this->cC5->move(200, 225);
    this->cC6->move(300, 225);
    this->cC7->move(100, 375);
    this->cC8->move(200, 375);
    this->cC9->move(300, 375);

    this->cC1->setSize(50, 25);
    this->cC2->setSize(50, 25);
    this->cC3->setSize(50, 25);
    this->cC4->setSize(50, 25);
    this->cC5->setSize(50, 25);
    this->cC6->setSize(50, 25);
    this->cC7->setSize(50, 25);
    this->cC8->setSize(50, 25);
    this->cC9->setSize(50, 25);

    this->cC1->setText(std::to_string(colors.getCountryColors().at(0)));
    this->cC2->setText(std::to_string(colors.getCountryColors().at(1)));
    this->cC3->setText(std::to_string(colors.getCountryColors().at(2)));
    this->cC4->setText(std::to_string(colors.getRevolutionaryColors().at(0)));
    this->cC5->setText(std::to_string(colors.getRevolutionaryColors().at(1)));
    this->cC6->setText(std::to_string(colors.getRevolutionaryColors().at(2)));
    this->cC7->setText(std::to_string(colors.getMapColors().at(0)));
    this->cC8->setText(std::to_string(colors.getMapColors().at(1)));
    this->cC9->setText(std::to_string(colors.getMapColors().at(2)));

    this->colors1->move(355, 35);
    this->colors2->move(355, 185);
    this->colors3->move(355, 335);
    this->colors1->setSize(100, 100);
    this->colors2->setSize(100, 100);
    this->colors3->setSize(100, 100);
    std::string tst1 = "background-color: rgb(" + this->cC1->getText() + "," + this->cC2->getText() + "," + this->cC3->getText() + ");";
    this->colors1->setStyleSheet(tst1);
    this->colors2->setStyleSheet("background:rgb(" + this->cC4->getText() + "," + this->cC5->getText() + "," + this->cC6->getText() + ");");
    this->colors3->setStyleSheet("background:rgb(" + this->cC7->getText() + "," + this->cC8->getText() + "," + this->cC9->getText() + ");");

    this->connect();
}

ColorsScene::~ColorsScene() {} 

void ColorsScene::connect() {
    this->cC1->connect([this](){
        DialogBox box("new value", "new value", DialogBox::TEXT, this->cC1->getWidgets());
        teuton::parser::Colors newG = this->getNewInfo();
        try {
            int tst = std::stoi(box.getText());
        }
        catch(std::exception const & e)
        {
            return;
        }
        this->cC1->setText(box.getText());
        std::vector<int> newC = {std::atoi(this->cC1->getText().c_str()),std::atoi(this->cC2->getText().c_str()),std::atoi(this->cC3->getText().c_str())};
        colors1->setStyleSheet("background-color: rgb(" + this->cC1->getText() + "," + this->cC2->getText() + "," + this->cC3->getText() + ");");
        newG.setMapColors(newC);
        this->setNewInfo(newG);
    });
    this->cC2->connect([this](){
        DialogBox box("new value", "new value", DialogBox::TEXT, this->cC2->getWidgets());
        teuton::parser::Colors newG = this->getNewInfo();
        try {
            int tst = std::stoi(box.getText());
        }
        catch(std::exception const & e)
        {
            return;
        }
        this->cC2->setText(box.getText());
        std::vector<int> newC = {std::atoi(this->cC1->getText().c_str()),std::atoi(this->cC2->getText().c_str()),std::atoi(this->cC3->getText().c_str())};
        colors1->setStyleSheet("background-color: rgb(" + this->cC1->getText() + "," + this->cC2->getText() + "," + this->cC3->getText() + ");");
        newG.setMapColors(newC);
        this->setNewInfo(newG);
    });
    this->cC3->connect([this](){
        DialogBox box("new value", "new value", DialogBox::TEXT, this->cC3->getWidgets());
        teuton::parser::Colors newG = this->getNewInfo();
        try {
            int tst = std::stoi(box.getText());
        }
        catch(std::exception const & e)
        {
            return;
        }
        this->cC3->setText(box.getText());
        std::vector<int> newC = {std::atoi(this->cC1->getText().c_str()),std::atoi(this->cC2->getText().c_str()),std::atoi(this->cC3->getText().c_str())};
        colors1->setStyleSheet("background-color: rgb(" + this->cC1->getText() + "," + this->cC2->getText() + "," + this->cC3->getText() + ");");
        newG.setMapColors(newC);
        this->setNewInfo(newG);
    });

    this->cC4->connect([this](){
        DialogBox box("new value", "new value", DialogBox::TEXT, this->cC4->getWidgets());
        teuton::parser::Colors newG = this->getNewInfo();
        try {
            int tst = std::stoi(box.getText());
        }
        catch(std::exception const & e)
        {
            return;
        }
        this->cC4->setText(box.getText());
        std::vector<int> newC = {std::atoi(this->cC4->getText().c_str()),std::atoi(this->cC5->getText().c_str()),std::atoi(this->cC6->getText().c_str())};
        colors2->setStyleSheet("background-color: rgb(" + this->cC4->getText() + "," + this->cC5->getText() + "," + this->cC6->getText() + ");");
        newG.setRevolutionaryColors(newC);
        this->setNewInfo(newG);
    });
    this->cC5->connect([this](){
        DialogBox box("new value", "new value", DialogBox::TEXT, this->cC5->getWidgets());
        teuton::parser::Colors newG = this->getNewInfo();
        try {
            int tst = std::stoi(box.getText());
        }
        catch(std::exception const & e)
        {
            return;
        }
        this->cC5->setText(box.getText());
        std::vector<int> newC = {std::atoi(this->cC4->getText().c_str()),std::atoi(this->cC5->getText().c_str()),std::atoi(this->cC6->getText().c_str())};
        colors2->setStyleSheet("background-color: rgb(" + this->cC4->getText() + "," + this->cC5->getText() + "," + this->cC6->getText() + ");");
        newG.setRevolutionaryColors(newC);
        this->setNewInfo(newG);
    });
    this->cC6->connect([this](){
        DialogBox box("new value", "new value", DialogBox::TEXT, this->cC6->getWidgets());
        teuton::parser::Colors newG = this->getNewInfo();
        try {
            int tst = std::stoi(box.getText());
        }
        catch(std::exception const & e)
        {
            return;
        }
        this->cC6->setText(box.getText());
        std::vector<int> newC = {std::atoi(this->cC4->getText().c_str()),std::atoi(this->cC5->getText().c_str()),std::atoi(this->cC6->getText().c_str())};
        colors2->setStyleSheet("background-color: rgb(" + this->cC4->getText() + "," + this->cC5->getText() + "," + this->cC6->getText() + ");");
        newG.setRevolutionaryColors(newC);
        this->setNewInfo(newG);
    });

    this->cC7->connect([this](){
        DialogBox box("new value", "new value", DialogBox::TEXT, this->cC7->getWidgets());
        teuton::parser::Colors newG = this->getNewInfo();
        try {
            int tst = std::stoi(box.getText());
        }
        catch(std::exception const & e)
        {
            return;
        }
        this->cC7->setText(box.getText());
        std::vector<int> newC = {std::atoi(this->cC7->getText().c_str()),std::atoi(this->cC8->getText().c_str()),std::atoi(this->cC9->getText().c_str())};
        colors3->setStyleSheet("background-color: rgb(" + this->cC7->getText() + "," + this->cC8->getText() + "," + this->cC9->getText() + ");");
        newG.setCountryColors(newC);
        this->setNewInfo(newG);
    });
    this->cC8->connect([this](){
        DialogBox box("new value", "new value", DialogBox::TEXT, this->cC8->getWidgets());
        teuton::parser::Colors newG = this->getNewInfo();
        try {
            int tst = std::stoi(box.getText());
        }
        catch(std::exception const & e)
        {
            return;
        }
        this->cC8->setText(box.getText());
        std::vector<int> newC = {std::atoi(this->cC8->getText().c_str()),std::atoi(this->cC8->getText().c_str()),std::atoi(this->cC9->getText().c_str())};
        colors3->setStyleSheet("background-color: rgb(" + this->cC7->getText() + "," + this->cC8->getText() + "," + this->cC9->getText() + ");");
        newG.setCountryColors(newC);
        this->setNewInfo(newG);
    });
    this->cC9->connect([this](){
        DialogBox box("new value", "new value", DialogBox::TEXT, this->cC9->getWidgets());
        teuton::parser::Colors newG = this->getNewInfo();
        try {
            int tst = std::stoi(box.getText());
        }
        catch(std::exception const & e)
        {
            return;
        }
        this->cC9->setText(box.getText());
        std::vector<int> newC = {std::atoi(this->cC7->getText().c_str()),std::atoi(this->cC8->getText().c_str()),std::atoi(this->cC9->getText().c_str())};
        colors3->setStyleSheet("background-color: rgb(" + this->cC7->getText() + "," + this->cC8->getText() + "," + this->cC9->getText() + ");");
        newG.setCountryColors(newC);
        this->setNewInfo(newG);
    });
}

void ColorsScene::setNewInfo(teuton::parser::Colors n) {
    this->colors = n;
}

void ColorsScene::setVisible(bool show) {
    this->_ColorsScene->show(show);
}

std::vector<QWidget*> ColorsScene::getWidgets() {
    return this->_local;
}

teuton::parser::Colors ColorsScene::getNewInfo() {
    return this->colors;
}

QButton* ColorsScene::getReturn() {
    return this->_Return;
}