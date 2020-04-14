#include "../headers/LauncherAccueil.h"
#include <iostream>


LauncherAccueil::LauncherAccueil() : m_titre(0), m_bord(0) {

    setFixedSize(1400,621);
    setStyleSheet("background: cyan");

    m_titre = new QLabel("Ultimate Toupie Simulator 2020", this);
    m_titre->setAlignment(Qt::AlignTop);
    m_titre->setFont(QFont("Comic sans MS", 46, 30, true));

    m_bord = new BordMode(this);
    m_bord->setFixedSize(700, 317);
    m_bord->move(350, 270);




    //Path vers les toupies ojala
    QString path(QCoreApplication::applicationDirPath());
    QString pathTv(path + "/tav.gif");

    //setup des gifs de toupies
    QMovie* m_toupieVisage = new QMovie(pathTv);
    QLabel* cadreToupieVisage = new QLabel(this);

    cadreToupieVisage->setFixedSize(200,200);
    cadreToupieVisage->move(110, 160);
    m_toupieVisage->start();

    cadreToupieVisage->setAttribute(Qt::WA_NoSystemBackground);
    cadreToupieVisage->setMovie(m_toupieVisage);





    QString pathTb(path + "/data/toupie-bleue-marine.gif");


    QMovie* m_toupieBleue = new QMovie(pathTb);
    QLabel* cadreToupieBleue = new QLabel(this);

    cadreToupieBleue->setFixedSize(200,200);
    cadreToupieBleue->move(1170, 160);
    m_toupieBleue->start();

    cadreToupieBleue->setAttribute(Qt::WA_NoSystemBackground);
    cadreToupieBleue->setMovie(m_toupieBleue);

    //Connexioooooon !

    for(int i(1); i < 3; i++){

        QObject::connect(m_bord->getBouton(i), SIGNAL(clicked()), this, SLOT(suppInit()));
    }

    QObject::connect(m_bord, &BordMode::fichierPret, this, &LauncherAccueil::suppInit);

}

void LauncherAccueil::suppInit(){

    switch(m_bord->getFormat()){

    default:
    case 1: //Format Texte
        m_support = new TextViewer(std::cout);
        break;

    case 2: //Format Image
        m_support = new TextViewer(std::cout);  // A COMPLETER
        break;

    case 3: //Format Fichier
        std::ofstream flux(m_bord->getPath());
        m_support = new TextViewer(flux);
        break;



    }

    hide();
}



//QObject::connect(m_bord->getFenetre()->getBlocBoutons()->getBOk(), &QPushButton::clicked, this, &LauncherAccueil::filePathCheck);


