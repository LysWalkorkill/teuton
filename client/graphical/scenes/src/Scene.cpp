#include "../include/Scene.hpp"

using namespace teuton::graphical;

Scene::Scene(std::vector<teuton::parser::Country> cnt, std::vector<teuton::parser::Province> province, std::string path, std::vector<std::string> save) {
    this->country = cnt;
    this->province = province;
    this->save = save;
    this->path = path;
    for (int i = 0; (size_t)i < cnt.size(); i++)
        _tag.push_back(cnt.at(i).getTag());
    this->setScene("Home", "");
}

Scene::~Scene() {} 

void Scene::setScene(std::string sceneName, std::string name) {
    if (sceneName == "Home")
        this->startSceneHome();
    else if (sceneName == "Country") {
        this->startSceneCountry(name);
        this->_Country->_saveQuit->connect([this](){
            this->choosedC = this->_Country->getNewCountry();
            this->province = this->_Country->getNewProvince();
            this->tagList.push_back(this->_Country->getNewCountry().getTag());
            this->endSave();
            this->_Country->~CountryScene();
        });
        this->_Country->_Return->connect([this](){
            this->choosedC = this->_Country->getNewCountry();
            this->province = this->_Country->getNewProvince();
            this->tagList.push_back(this->_Country->getNewCountry().getTag());
            for (int i = 0; country.size() > (size_t)i ; i++) {
               if (country.at(i).getTag() == choosedC.getTag())
                    country.at(i) = choosedC;
                    
            }
            this->_Country->setVisible(false);
            this->setScene("Home", "");
        });
    }
}

void Scene::endSave() {
    for (int i = 0; country.size() > (size_t)i ; i++) {
        if (country.at(i).getTag() == choosedC.getTag())
            country.at(i) = choosedC;
    }
    this->_Country->setVisible(false);
    Widget finalPage;
    finalPage.show(true);
    finalPage.setTransparentBackground(false);
    finalPage.setSize(300, 300);
    Label Lbl(*finalPage.getWidgets());
    Lbl.setSize(300, 300);
    Lbl.setStyleSheet("background-color: grey");
    Lbl.show(true);
    Label textExit(*Lbl.getWidgets());
    textExit.move(50, 25);
    textExit.setSize(200, 50);
    textExit.setStyleSheet("background-color: grey");
    textExit.setText("pls wait");
    textExit.show(true);
    teuton::parser::Write endAtAll(this->path,this->save,this->country, this->province, this->tagList);
    textExit.setText("save as been created \n pls quit the app");
}

void Scene::startSceneHome() {
    this->_Home = new HomeScene(_tag);
    this->connectHome();
    this->_Home->setVisible(true);
}
void Scene::startSceneCountry(std::string name) {
    teuton::parser::Country newCnt;
    for (int i = 0; (size_t)i < this->country.size(); i++)
        if (this->country.at(i).getTag() == name)
            newCnt = this->country.at(i);
    this->choosedC = newCnt;
    this->_Country = new CountryScene(name, this->_Home, newCnt, this->province, this->_tag);
    this->_Country->setVisible(true);
    this->_Home->setVisible(false);
}

void Scene::connectHome() {
    this->_Home->getCp().at(0)->connect([this](){
        this->setScene("Country", this->_Home->cp1Acces());
    });
    this->_Home->getCp().at(1)->connect([this](){
        this->setScene("Country", this->_Home->cp2Acces());
    });
    this->_Home->getCp().at(2)->connect([this](){
        this->setScene("Country", this->_Home->cp3Acces());
    });
    this->_Home->getCp().at(3)->connect([this](){
        this->setScene("Country", this->_Home->cp4Acces());
    });
    this->_Home->getCp().at(4)->connect([this](){
        this->setScene("Country", this->_Home->cp5Acces());
    });
    this->_Home->getCp().at(5)->connect([this](){
        this->setScene("Country", this->_Home->cp6Acces());
    });
    this->_Home->getCp().at(6)->connect([this](){
        this->setScene("Country", this->_Home->cp7Acces());
    });
    this->_Home->getCp().at(7)->connect([this](){
        this->setScene("Country", this->_Home->cp8Acces());
    });
}