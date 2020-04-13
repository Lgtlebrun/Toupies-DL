#include "../headers/bordMode.h"

BordMode::BordMode(QWidget* parent) : QWidget(parent), m_b1(0), m_b2(0), m_b3(0), m_labelMode(0) {



    int bx(30);    //Coords des boutons
    int by(80);

    int bl(640);    //Dimensions des boutons
    int bw(60);

    QFont police("courier", 14, 18);        // Police des boutons


    m_b1 = new QPushButton("Texte", this);
    m_b2 = new QPushButton("Image", this);
    m_b3 = new QPushButton("Fichier", this);

    m_b1->setStyleSheet("background-color: light grey");
    m_b1->setCursor(Qt::PointingHandCursor);
    m_b1->setFixedSize(bl, bw);
    m_b1->setFont(police);
    m_b1->move(bx, by);

    m_b2->setStyleSheet("background-color: light grey");
    m_b2->setCursor(Qt::PointingHandCursor);
    m_b2->setFixedSize(bl, bw);
    m_b2->setFont(police);
    m_b2->move(bx, by + 70);

    m_b3->setStyleSheet("background-color: light grey");
    m_b3->setCursor(Qt::PointingHandCursor);
    m_b3->setFixedSize(bl, bw);
    m_b3->setFont(police);
    m_b3->move(bx, by + 140);



    m_labelMode = new QLabel("Mode d'affichage : ", this);
    m_labelMode->setFont(QFont("Agency FB", 19, 19));
    m_labelMode->move(30, 10);


}

