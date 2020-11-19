/*
** EPITECH PROJECT, 2020
** teuton
** File description:
** TODO: add description
*/

/*#include "graphical/widget/include/QButton.hpp"
#include "graphical/widget/include/DialogBox.hpp"
#include "graphical/widget/include/LineEdit.hpp"
#include "graphical/widget/include/Widget.hpp"
#include "graphical/widget/include/Label.hpp"
#include "graphical/widget/include/IWidgets.hpp"
#include <QPushButton>
#include <QApplication>
#include <QObject>
#include <QPainter>
#include <QWidget>
#include <QPaintDevice>
#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/QGLPixelBuffer>*/
#include <iostream>
#include "parser/read/include/read.hpp"
#include "parser/write/include/write.hpp"

//using namespace teuton::graphical;

using namespace teuton::parser;

int main (int argc, char **argv)
{
    read rd(argv[1]);
    //write wr(argv[1], rd.getSave(), rd.getCountry(), rd.getProvince());
    return (0);
}


/*
QApplication _app(argc, argv);
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



    /*QString qstr = QString::fromStdString("client/ressources/army_organiser_female.dds");
    QImage image1;
    QGLWidget glWidget;
    glWidget.makeCurrent();
 
    GLuint texture = glWidget.bindTexture(qstr);

    // Determine the size of the DDS image
    GLint width, height;
    glBindTexture(GL_TEXTURE_2D, texture);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);
 
    QGLPixelBuffer pbuffer(QSize(width, height), glWidget.format(), &glWidget);

    pbuffer.drawTexture(QRectF(-1, -1, 2, 2), texture);
    image1 = pbuffer.toImage();

    QLabel myLabel(fenetre.getWidgets());
    myLabel.setPixmap(QPixmap::fromImage(image1));

    return _app.exec();
*/