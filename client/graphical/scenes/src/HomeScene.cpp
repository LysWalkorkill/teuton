#include "../include/HomeScene.hpp"

using namespace teuton::graphical;

HomeScene::HomeScene() {
    Widget homeScene;
    LineEdit ledger(*homeScene.getWidgets());
    QButton proposal(*homeScene.getWidgets());

    homeScene.setSize(900, 600);
    ledger.setText("looking for a country");
    ledger.move(250, 100);

    homeScene.show(true);

    this->_Widgets.insert(std::pair<std::string, int>("homeScene", 0));
    this->_Widgets.insert(std::pair<std::string, int>("ledger", 1));
    this->_Widgets.insert(std::pair<std::string, int>("proposal", 2));

    this->_local.push_back(homeScene.getWidgets());
    this->_local.push_back(ledger.getWidgets());
    this->_local.push_back(proposal.getWidgets());
}

HomeScene::~HomeScene() {} 

std::vector<QWidget*> HomeScene::getWidgets() {
    return this->_local;
}

/*
HomeScene::HomeScene() {
    Widget homeScene;
    LineEdit ledger(*homeScene.getWidgets());
    QButton proposal(*homeScene.getWidgets());

    homeScene.setSize(900, 600);
    ledger.setText("looking for a country");
    ledger.move(250, 100);

    this->_Widgets.insert("homeScene", 0);
    this->_Widgets.insert("ledger", 1);
    this->_Widgets.insert("proposal", 2);

    this->_local.push_back(homeScene);
    this->_local.push_back(ledger);
    this->_local.push_back(proposal);
}

HomeScene::~HomeScene() {} 

std::vector<IWidgets> HomeScene::getWidgets() {
    return this->_local;
}
*/

/*

Widget fenetre;
    fenetre.setSize(300, 150);

    //DialogBox message(fenetre, "nom de la box", "text dans la box", DialogBox::Dlevel::INFORMATION);
    
    //DialogBox message(fenetre, "quel est ton nom?", " quel est ton nom?", DialogBox::Dlevel::TEXT);
    //DialogBox message2(fenetre, "sure?", message.getText() + " est bien ton nom?", DialogBox::Dlevel::QUESTION);

    Label img(*fenetre.getWidgets());
    img.setImage("../client/ressources/greenDot.png");

    /*QButton test("test du code", *fenetre.getWidgets());
    test.move(100,100);
    test.setIcon("../client/ressources/ABB.tga");
    QObject::connect(test.getWidgets(), SIGNAL(clicked()), &_app, SLOT(quit())); //connect(const QObject *sender, const char *signal, const QObject *receiver, const char *method, Qt::ConnectionType type)
    
    LineEdit nom("put your name", *fenetre.getWidgets());
    nom.move(75, 75);

    Label box("mettre du text dedans", *fenetre.getWidgets());
    box.move(50,50);

    std::string contenu = nom.getTxt();

    std::cout << contenu << "1" <<  std::endl;

    fenetre.show(true);

*/