/*
** EPITECH PROJECT, 2020
** teuton
*/

#include "../include/Label.hpp"

using namespace teuton::graphical;

Label::Label(QWidget &NWindow) {
    this->_label = new QLabel(&NWindow);
}

Label::Label(Label &Label) {
    this->_label = qobject_cast<QLabel*>(Label.getWidgets());
}

Label::Label(const std::string &text, QWidget &NWindow) {
    QString qstr = QString::fromStdString(text);
    this->_label = new QLabel(qstr, &NWindow);
}

Label::~Label() = default;

void Label::setText(const std::string &text) {
    QString qstr = QString::fromStdString(text);
    this->_label->setText(qstr);
}

void Label::show(bool show) {
    if (show)
        this->_label->show();
    else
        this->_label->hide();
}

void Label::move(int x, int y) {
    this->_label->move(x, y);
    this->_x = x;
    this->_y = y;
}

void Label::setSize(int length, int width) {
    this->_label->resize(length, width);
    this->_length = length;
    this->_width = width;
}

void Label::setGeometry(int x, int y, int length, int width) {
    this->_label->setGeometry(x, y, length, width);
    this->_length = length;
    this->_width = width;
    this->_x = x;
    this->_y = y;
}

int Label::getX() const {
    return this->_x;
}

int Label::getY() const {
    return this->_y;
}

int Label::getLength() const {
    return this->_length;
}

int Label::getWidth() const {
    return this->_width;
}

QWidget* Label::getWidgets() const {
    return qobject_cast<QWidget*>(this->_label);
}

void Label::setStyleSheet(const std::string &style)
{
    _label->setStyleSheet(style.c_str());
}

void Label::setObjectName(const std::string &name)
{
    _label->setObjectName(name.c_str());
}

void Label::setFont(const QFont &font)
{
    _label->setFont(font);
}

void Label::setImage(const std::string &path)
{
    _label->setPixmap(QPixmap(path.c_str()));
}

void Label::setID(int id)
{
    this->_id = id;
}

int Label::getID() const
{
    return (this->_id);
}