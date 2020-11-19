/*
** EPITECH PROJECT, 2020
** teuton
*/

#ifndef TEUTON_LABEL_HPP
#define TEUTON_LABEL_HPP

#include <QLabel>
#include <QObject>
#include <QApplication>
#include "IWidgets.hpp"

namespace teuton::graphical
{
    /*
        this classes encapsulate QLabel
    */
    class Label: public IWidgets {
        public:
            /*
                constructor 
                QWidget is the window (Widget) this Widget is on
            */
            Label(QWidget&);
            /*
                constructor copy
                it take a Label to copy him
            */
            Label(Label&);
            /*
                constructor
                string is the text inside the Qbutton
                QWidget is the window (Widget) this Widget is on
            */
            Label(const std::string&, QWidget&);
            ~Label();

            /*
                encapsulation of QT setText method
                string is the text shown on this widget
            */
            void setText(const std::string&) override;
            /*
                encapsulation of QT show method
                it choose if the widget is visible
                it's alway visible if this method isn't call
            */
            void show(bool) override;
            /*
                encapsualtion of QT move method
                it place the widget on a window, with x-coordinate and y-coordinate 
            */
            void move(int, int) override;
            /*
                encapsualtion of QT Size method
                it change the size of a widget,
                the result may be different widget to widegt, as Label.
            */
            void setSize(int, int) override;
            /*
                encapsulation of QT Gemoetry
                it work as move and size, but do both in a time.
            */
            void setGeometry(int, int, int, int) override;

            /*
                string is the path to an image
            */
            void setImage(const std::string &path);

            /*
                return X-coordinate
            */
            int getX() const override;
            /*
                return Y-coordinate
            */
            int getY() const override;
            /*
                return Lenght
            */
            int getLength() const override;
            /*
                return Width
            */
            int getWidth() const override;
            /*
                return the actual widget
            */
            QWidget* getWidgets() const override;

            /*
                encaplustion of QT setStyleSheet
                it customize the Foreground and Background Colors
            */
            void setStyleSheet(const std::string &style) override;
            void setObjectName(const std::string &name) override;

            /*
                QFont is a QT Font that change Label text font
            */
            void setFont(const QFont &font);

            void setID(int id) override;
            /*
                return the widget ID
            */
            int getID() const override;

        private:
            QLabel *_label;
            int _x;
            int _y;
            int _length;
            int _width;
            int _id;
    };
}

#endif //TEUTON_QButton_HPP
