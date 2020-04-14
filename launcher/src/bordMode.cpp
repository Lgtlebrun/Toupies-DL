#include "../headers/bordMode.h"

BordMode::BordMode(QWidget* parent) : QWidget(parent), m_formatChoisi(1), m_b1(0), m_b2(0), m_b3(0), m_labelMode(0), m_path(QCoreApplication::applicationDirPath().toStdString()) {



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



    //Connexioooon!


      QObject::connect(m_b3, &QPushButton::clicked, this, &BordMode::setToFichier);
      QObject::connect(m_b2, &QPushButton::clicked, this, &BordMode::setToImage);
      QObject::connect(m_b1, &QPushButton::clicked, this, &BordMode::setToText);

}




QPushButton* BordMode::getBouton(int n){

    switch (n) {

    default:
        return m_b1;
    case 2:
        return m_b2;
    case 3:
        return m_b3;

    }
}



void BordMode::setToText() {m_formatChoisi = 1;}

void BordMode::setToImage() {m_formatChoisi = 2;}

void BordMode::setToFichier() {

    m_formatChoisi = 3;
    m_path = QFileDialog::getExistingDirectory(this).toStdString();
    pathCheck();
}


void BordMode::pathCheck(){

    if(m_path.back() != '/') {m_path += '/';}
    m_path += "UltimateSimulation.txt";

    std::ofstream flux(m_path);

    if(flux.fail()){

        QMessageBox::critical(this, "Erreur", "Une erreur est survenue lors de l'ouverture du dossier.");
        setToFichier();
    }
    else{
        emit fichierPret();
    }

}


