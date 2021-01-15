#include "../include/CountryScene.hpp"

using namespace teuton::graphical;

CountryScene::CountryScene(std::string name, HomeScene* home, teuton::parser::Country country, std::vector<teuton::parser::Province> province, std::vector<std::string> tag) {
    this->_home = home;
    this->_home->setVisible(false);
    this->country = country;
    this->_CountryScene = new Widget;
    this->_tag = name;
    this->province = province;
    this->tag = tag;

    this->_CountryScene->setSize(500, 600);
    this->_CountryScene->setTransparentBackground(false);

    this->_gov = new QButton(*_CountryScene->getWidgets());
    this->_tIdea = new QButton(*_CountryScene->getWidgets());
    this->_ord = new QButton(*_CountryScene->getWidgets());
    this->_stViews = new QButton(*_CountryScene->getWidgets());
    this->_col = new QButton(*_CountryScene->getWidgets());
    this->_pro = new QButton(*_CountryScene->getWidgets());
    this->_culReligion = new QButton(*_CountryScene->getWidgets());
    _saveQuit = new QButton(*_CountryScene->getWidgets());
    this->_Return = new QButton(*_CountryScene->getWidgets());

    _Return->setSize(100, 25);
    _saveQuit->setSize(100, 25);
    this->_gov->setSize(150, 75);
    this->_tIdea->setSize(150, 75);
    this->_ord->setSize(150, 75);
    this->_stViews->setSize(150, 75);
    this->_col->setSize(150, 75);
    this->_pro->setSize(150, 75);
    this->_culReligion->setSize(150, 75);

    _saveQuit->move(130, 25);
    _Return->move(25, 25);
    this->_gov->move(25, 100);
    this->_tIdea->move(25, 225);
    this->_ord->move(25, 350);
    this->_stViews->move(25, 475);
    this->_col->move(300, 100);
    this->_pro->move(300, 225);
    this->_culReligion->move(300, 350);

    _saveQuit->setText("save and quit");
    _saveQuit->show(true);
    _Return->setText("Return");
    _Return->show(true);
    this->_gov->setText("government");
    this->_tIdea->setText("tech & idea");
    this->_ord->setText("orders");
    this->_stViews->setText("state view");
    this->_col->setText("colors");
    this->_pro->setText("provinces");
    this->_culReligion->setText("culture & religion");


    this->_saveQuit->connect([this]() {
        this->endW();
    });

    this->_gov->connect([this](){
        this->setScene(SCENE::GOVERNEMENT);
        this->hideScene(SCENE::GOVERNEMENT);
    });
    this->_tIdea->connect([this](){
        this->setScene(SCENE::TECHIDEA);
        this->hideScene(SCENE::TECHIDEA);
    });
    this->_ord->connect([this](){
        this->setScene(SCENE::ORDER);
        this->hideScene(SCENE::ORDER);
    });
    this->_stViews->connect([this](){
        this->setScene(SCENE::STATEVIEWS);
        this->hideScene(SCENE::STATEVIEWS);
    });
    this->_col->connect([this](){
        this->setScene(SCENE::COLORS);
        this->hideScene(SCENE::COLORS);
    });
    this->_pro->connect([this](){
        this->setScene(SCENE::PROVINCE);
        this->hideScene(SCENE::PROVINCE);
    });
    this->_culReligion->connect([this](){
        this->setScene(SCENE::CULTURERELIGION);
        this->hideScene(SCENE::CULTURERELIGION);
    });
}

CountryScene::~CountryScene() {
    this->_home->~HomeScene();
} 

void CountryScene::setVisible(bool show) {
    this->_CountryScene->show(show);
}

void CountryScene::endW() {

}

std::vector<QWidget*> CountryScene::getWidgets() {
    return this->_local;
}

void CountryScene::hideScene(SCENE exept) {
    /*this->_colors->setVisible(false);
    this->_CountryScene->show(false);
    this->_culturReligion->setVisible(false);
    this->_government->setVisible(false);
    this->_order->setVisible(false);
    this->_provinces->setVisible(false);
    this->_stateViews->setVisible(false);
    this->_techIdea->setVisible(false);*/
    if (exept == SCENE::COLORS)
        this->_colors->setVisible(true);
    if (exept == SCENE::CULTURERELIGION)
        this->_culturReligion->setVisible(true);
    if (exept == SCENE::ORDER)
        this->_order->setVisible(true);
    if (exept == SCENE::PROVINCE)
        this->_provinces->setVisible(true);
    if (exept == SCENE::STATEVIEWS)
        this->_stateViews->setVisible(true);
    if (exept == SCENE::TECHIDEA)
        this->_techIdea->setVisible(true);
    if (exept == SCENE::GOVERNEMENT)
        this->_government->setVisible(true);
}

void CountryScene::setScene(SCENE exept) {
    if (exept == SCENE::COLORS)
        this->startSceneColors();
    if (exept == SCENE::CULTURERELIGION)
        this->startSceneCultureReligion();
    if (exept == SCENE::ORDER)
        this->startSceneOrder();
    if (exept == SCENE::PROVINCE)
        this->startSceneProvince();
    if (exept == SCENE::STATEVIEWS)
        this->startSceneStateViews();
    if (exept == SCENE::TECHIDEA)
        this->startSceneTechIdea();
    if (exept == SCENE::GOVERNEMENT)
        this->startSceneGovernement();
    if (exept == SCENE::COUNTRY)
        this->startSceneGovernement();
}

void CountryScene::startSceneColors() {
    this->_colors = new ColorsScene(_tag, country.getColors());
    this->connectSceneColors();
}
void CountryScene::startSceneCultureReligion() {
    this->_culturReligion = new CultureReligionScene(_tag, country);
    this->connectSceneCultureReligion();
}
void CountryScene::startSceneOrder() {
    this->_order = new OrderScene(_tag, country.getEstates(), country);
    this->connectSceneOrder();
}
void CountryScene::startSceneProvince() {
    this->_provinces = new ProvincesScene(_tag, country, province);
    this->connectSceneProvince();
}
void CountryScene::startSceneStateViews() {
    this->_stateViews = new StateViewsScene(_tag, country.getStateViews(), this->country.getRival(), this->tag);
    this->connectSceneStateViews();
}
void CountryScene::startSceneTechIdea() {
    this->_techIdea = new TechIdeaScene(_tag, country.getTechnology(), country.getActiveIdeaGroup());
    this->connectSceneTechIdea();
}
void CountryScene::startSceneGovernement() {
    this->_government = new GovernementScene(_tag, country.getGovernment());
    this->connectSceneGovernement();
}

void CountryScene::connectSceneColors() {
    this->_colors->getReturn()->connect([this](){
        this->hideScene(SCENE::COUNTRY);
        this->_colors->setVisible(false);
        this->country.setColor(this->_colors->getNewInfo());
    });
}
void CountryScene::connectSceneCultureReligion() {
    this->_culturReligion->getReturn()->connect([this](){
        this->hideScene(SCENE::COUNTRY);
        this->_culturReligion->setVisible(false);
        this->country.setPrimaryCulture(this->_culturReligion->getNewInfo().getPrimaryCulture());
        this->country.setReligion(this->_culturReligion->getNewInfo().getReligion());
    });
}
void CountryScene::connectSceneOrder() {
    this->_order->getReturn()->connect([this](){
        this->hideScene(SCENE::COUNTRY);
        this->_order->setVisible(false);
        this->country.setEstates(this->_order->getNewInfo());
    });
}
void CountryScene::connectSceneProvince() {
    this->_provinces->getReturn()->connect([this](){
        this->hideScene(SCENE::COUNTRY);
        this->_provinces->setVisible(false);
        this->province = this->_provinces->getNewInfo();
    });
}
void CountryScene::connectSceneStateViews() {
    this->_stateViews->getReturn()->connect([this](){
        this->hideScene(SCENE::COUNTRY);
        this->_stateViews->setVisible(false);
        this->country.setStateViews(this->_stateViews->getNewInfo());
        this->country.setRival(this->_stateViews->getRival());
    });
}
void CountryScene::connectSceneTechIdea() {
    this->_techIdea->getReturn()->connect([this](){
        this->hideScene(SCENE::COUNTRY);
        this->_techIdea->setVisible(false);
        this->country.setTechnology(this->_techIdea->getNewInfoTech());
        this->country.setActiveIdeaGroup(this->_techIdea->getNewInfoIdea());
    });
}
void CountryScene::connectSceneGovernement() {
    this->_government->getReturn()->connect([this](){
        this->hideScene(SCENE::COUNTRY);
        this->_government->setVisible(false);
        this->country.setGovernment(this->_government->getNewInfo());
    });
}

void CountryScene::hideAll() {
    this->_gov->show(false);
    this->_tIdea->show(false);
    this->_ord->show(false);
    this->_stViews->show(false);
    this->_col->show(false);
    this->_pro->show(false);
    this->_culReligion->show(false);
}

teuton::parser::Country CountryScene::getNewCountry() {
    return this->country;
}
std::vector<teuton::parser::Province> CountryScene::getNewProvince() {
    return this->province;
}