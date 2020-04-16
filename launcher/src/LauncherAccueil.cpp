#include "../headers/LauncherAccueil.h"
#include <iostream>


LauncherAccueil::LauncherAccueil() : m_titre(0), m_bord(0), m_grillage(0), m_integ(0), m_simulation(0),
m_support(0){

    setFixedSize(1400,621);
    setStyleSheet("background: cyan");

    m_titre = new QLabel("Ultimate Toupie Simulator 2020", this);
    m_titre->setAlignment(Qt::AlignTop);
    m_titre->setFont(QFont("Comic sans MS", 46, 30, true));

    m_bord = new BordMode(this);
    m_bord->setFixedSize(700, 317);
    m_bord->move(350, 270);




    //Path vers les toupies ojala
    QString pathTv(":/icons/launcher/data/tav.gif");

    //setup des gifs de toupies
    QMovie* m_toupieVisage = new QMovie(pathTv);
    QLabel* cadreToupieVisage = new QLabel(this);

    cadreToupieVisage->setFixedSize(200,200);
    cadreToupieVisage->move(110, 160);
    m_toupieVisage->start();

    cadreToupieVisage->setAttribute(Qt::WA_NoSystemBackground);
    cadreToupieVisage->setMovie(m_toupieVisage);





    QString pathTb(":/icons/launcher/data/toupie-bleue-marine.gif");


    QMovie* m_toupieBleue = new QMovie(pathTb);
    QLabel* cadreToupieBleue = new QLabel(this);

    cadreToupieBleue->setFixedSize(200,200);
    cadreToupieBleue->move(1170, 160);
    m_toupieBleue->start();

    cadreToupieBleue->setAttribute(Qt::WA_NoSystemBackground);
    cadreToupieBleue->setMovie(m_toupieBleue);

    //Connexioooooon !

    //Bouton Texte
    QObject::connect(m_bord->getBouton(1), &QPushButton::clicked, this, &LauncherAccueil::suppPret);


    // Bouton Image
    QObject::connect(m_bord->getBouton(2), &QPushButton::clicked, this, &LauncherAccueil::suppPret);



    QObject::connect(m_bord->getSearch(), &FichierSearch::fichierPret, this, &LauncherAccueil::suppPret);


}

void LauncherAccueil::suppPret(){


    hide();


    switch(m_bord->getFormat()){


    case TEXTE:
        break;

    case FICHIER:
    case IMAGE:
        m_support = new TextViewer(std::cout);  //Par défaut : le glwidget s'occupe de tout!

        launchGrillage();
        break;



    }

}


void LauncherAccueil::launchGrillage() {

    m_grillage = new Grillage;

    //CONNEXIOOOOOOOON
    QObject::connect(m_grillage->getGo(), &QPushButton::clicked, this, &LauncherAccueil::go);

    m_grillage->show();
}



LauncherAccueil::~LauncherAccueil(){

    delete m_integ;
    delete m_support;
}


void LauncherAccueil::go(){

    setInteg();
    m_grillage->hide();

    switch(m_bord->getFormat()){

    case TEXTE:
        goTexte();
        break;
    case IMAGE:
        goImage();
        break;
    case FICHIER:
        this->goFichier();
        break;

    }

}




void LauncherAccueil::setInteg(){

    switch(m_grillage->getInteg()){

    default:
    case EC:
        m_integ = new IntegrateurEulerCromer(0);
        break;
    case NEWMARK:
        m_integ = new IntegrateurNewmark(0);
        break;

    }

}





void LauncherAccueil::goFichier() {

    double secondes = QInputDialog::getInt(this, tr("Information"), tr("Combien de secondes doit durer votre simulation?"), 0, 0);
    double dt = QInputDialog::getDouble(this, tr("Information"), tr("Quel pas de temps désirez-vous ?"), 0, 0);

    if(dt == 0.0){dt = 1;}
    secondes /= dt;



    std::ofstream flux(m_bord->getSearch()->getPath());
    m_support = new TextViewer(flux);

    if(!flux.fail()){

        Systeme S(*m_support, *m_integ);

        for(auto&elt : m_grillage->getCorps()){

            elt->setPosition(m_grillage->getEchelle() * elt->getPosition());
            S.addIntegrable(*elt);
        }


        S.affiche(flux);


      for (int i(0); i < secondes; i++){
          S.evolue(dt);
          S.dessine();
     }

        std::string mess("La simulation s'est correctement déroulée. \nFichier correctement enrigistré à l'adresse " + m_bord->getSearch()->getPath());

        QMessageBox::information(this, "Succès!", QString::fromStdString(mess));

    }
    else {
        std::string mess("Une erreur est survenue en fin de processus. Toutes nos excuses.\nLe fichier " + m_bord->getSearch()->getPath() + " n'a pas été ouvert correctement.");

        QMessageBox::information(this, "Echec!", QString::fromStdString(mess));

    }

    qApp->quit();
}


void LauncherAccueil::goImage() {

    Systeme S(*m_support, *m_integ);

    for(auto&elt : m_grillage->getCorps()){

        elt->setPosition(m_grillage->getEchelle() * elt->getPosition());
        S.addIntegrable(*elt);
    }

    m_simulation = new GLWidget(S, Vecteur({4.5,-1.0,0.0}) * m_grillage->getEchelle());


    m_simulation->show();
    hide();
}


void LauncherAccueil::goTexte() {
     std::ofstream flux(":/txt/launcher/data/Intermezzo.txt");

}
