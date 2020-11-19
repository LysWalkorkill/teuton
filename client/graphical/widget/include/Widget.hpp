/*
** EPITECH PROJECT, 2020
** teuton
** File description:
** TODO: add description
*/

#ifndef TEUTON_WIDGET_HPP
#define TEUTON_WIDGET_HPP

#include <QPushButton>
#include <QObject>
#include <QApplication>
#include "IWidgets.hpp"

namespace teuton::graphical
{
    /*
        this classes encapsulate QWidget
    */
    class Widget: public IWidgets {
        public:
             /*
                constructor 
            */
            Widget();
            /*
                constructor copy
                it take a Widget to copy him
            */
            Widget(Widget&);
            ~Widget();

            /*
                not used in Widget
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

            void setTransparentBackground(bool transparent);

            void setID(int id) override;
            /*
                return the widget ID
            */
            int getID() const override;

        private:
            QWidget *_widget;
            int _x;
            int _y;
            int _length;
            int _width;
            int _id;
    };
}

#endif //teuton_Widget_HPP
