#include "../headers/Grillage.h"

Grillage::Grillage(QWidget* parent) :  QWidget(parent), m_typeChoisi(Null), m_BoxIntegrateur(0), m_bCone(0),
m_bChinoise(0), m_bBille(0), m_bOscillateur(0), m_go(0){

 setFixedSize(1900, 1200); // Un GRAND grillage

 QVBoxLayout* mainLay = new QVBoxLayout;
 mainLay->setAlignment(Qt::AlignTop);
 mainLay->setSpacing(20);

 QHBoxLayout* layIntegrateur = new QHBoxLayout;
 QVBoxLayout* layIntegBis = new QVBoxLayout;
 layIntegBis->setAlignment((Qt::AlignLeft));
 layIntegrateur->setAlignment(Qt::AlignLeft);

 QHBoxLayout* grillePlusBouton = new QHBoxLayout;
 grillePlusBouton->setAlignment(Qt::AlignRight);

 QGridLayout* laygrille = new QGridLayout;
 laygrille->setSpacing(0);



 //Setup Integrateur

    m_BoxIntegrateur = new QComboBox(this);
    QLabel* integrateur = new QLabel("Integrateur :", this);

    m_BoxIntegrateur->addItem("Euler-Cromer");
    m_BoxIntegrateur->addItem("Newmark");

    layIntegBis->addWidget(integrateur);
    layIntegBis->addWidget(m_BoxIntegrateur);
    layIntegBis->setSpacing(5);

    layIntegrateur->addLayout(layIntegBis);

    grillePlusBouton->addLayout(layIntegrateur);


 //Setup Boutons Positions

    for(double i(0); i < 10; i++) {

        for(double j(0); j < 10; j++) {


            BoutonPosition* b = new BoutonPosition({i, j, 0});
            b->setFixedSize(80,80);
            b->setCursor(Qt::PointingHandCursor);

            if (m_boutonsPos.size() < (i + 1)) {m_boutonsPos.push_back({});}
            m_boutonsPos[i].push_back(b);

            QObject::connect(b, &QPushButton::clicked, b, &BoutonPosition::clickGestion);
            QObject::connect(b, &BoutonPosition::newIntegrable, this, &Grillage::addIntegrable);
            QObject::connect(b, &BoutonPosition::supprIntegrable, this, &Grillage::delIntegrable);

            //NDP : Dernière commande de la boucle
            laygrille->addWidget(b,i,j);
        }

    }

 grillePlusBouton->addLayout(laygrille);



//Setup des boutons types

 QVBoxLayout* layBoutons = new QVBoxLayout;

 m_bCone = new TypeBouton(CONE, this);
 m_bChinoise = new TypeBouton(CHINOISE, this);
 m_bBille = new TypeBouton(BILLE, this);
 m_bOscillateur = new TypeBouton(OSCILLATEUR, this);

 layBoutons->addWidget(m_bCone);
 layBoutons->addWidget(m_bChinoise);
 layBoutons->addWidget(m_bBille);
 layBoutons->addWidget(m_bOscillateur);

 layBoutons->setSpacing(0);

 grillePlusBouton->addLayout(layBoutons);


  mainLay->addLayout(grillePlusBouton);

    //Setup bouton GO


    m_go = new QPushButton("GO !",this);
    m_go->setFont(QFont("Cooper Black", 70, 30));
    m_go->setFixedSize(350, 155);
    m_go->setStyleSheet("background: cyan; color: white");

    m_go->move(1540, 815);
    mainLay->setSpacing(5);

 //DERNIERE COMMANDE!
 setLayout(mainLay);



 //CONNEXIOOOOOOON

 QObject::connect(m_bCone, &TypeBouton::statutChange, this, &Grillage::clickTypeBouton);
 QObject::connect(m_bCone, &QPushButton::clicked, m_bCone, &TypeBouton::changeStatut);

 QObject::connect(m_bChinoise, &TypeBouton::statutChange, this, &Grillage::clickTypeBouton);
 QObject::connect(m_bChinoise, &QPushButton::clicked, m_bChinoise, &TypeBouton::changeStatut);

 QObject::connect(m_bBille, &TypeBouton::statutChange, this, &Grillage::clickTypeBouton);
 QObject::connect(m_bBille, &QPushButton::clicked, m_bBille, &TypeBouton::changeStatut);

 QObject::connect(m_bOscillateur, &TypeBouton::statutChange, this, &Grillage::clickTypeBouton);
 QObject::connect(m_bOscillateur, &QPushButton::clicked, m_bOscillateur, &TypeBouton::changeStatut);
}





Grillage::~Grillage(){

    for (auto& elt:m_sys){
        delete elt;
    }
}




void Grillage::clickTypeBouton() {

    std::vector<TypeBouton*> boutons({m_bCone, m_bChinoise, m_bBille, m_bOscillateur});

    Type newType(Null);

    for (auto& elt : boutons) {

        if(elt->isPresse() && m_typeChoisi != elt->getType()){
            newType = elt->getType();
        }
        else if(elt->isPresse() && m_typeChoisi == elt->getType()){
            elt->setPresse(false);
        }

        elt->changeSkin();
    }

    m_typeChoisi = newType;
}



Vecteur Grillage::findNewPos(){


    for(auto& ligne:m_boutonsPos){
        for (auto& bouton:ligne){

            if(bouton->getCouleur() == BLEU){

                bool isInSys(false);
                for (auto& corps : m_sys){

                    if(corps->getPosition() == bouton->getPos()){
                        isInSys = true;
                    }
                }

                if (!isInSys) {return bouton->getPos();}

                }

            }
        }

    return Vecteur({0,0,0});
}








bool Grillage::checkAllCaracs() const {

     /// Vérifie que toutes les données sont réunies pour la création
     /// d'un nouvel intégrable

    switch(m_typeChoisi){

    case Null:
        return false;

    case CONE:
        return ((m_bCone->getRayon() > 0) && (m_bCone->getHauteur() > 0) && (m_bCone->getMVol() > 0));

    case CHINOISE:
        return ((m_bChinoise->getRayon() > 0) && (m_bChinoise->getHauteur() > 0) && (m_bChinoise->getMVol() > 0));

    case BILLE:
        return (m_bBille->getRayon() > 0);

    case OSCILLATEUR:
        return (m_bOscillateur->getRayon() > 0);
    }

}


void Grillage::addIntegrable(){

    Vecteur pos(findNewPos());

    if(!checkAllCaracs()){

        for(auto& ligne : m_boutonsPos){

            for(auto& bouton : ligne){

                // SI PAS TOUTES LES CARACS : le bouton redevient gris
                if(bouton->getPos() == pos){

                    bouton->changeCouleur(GRIS);}
            }
        }

        sendCaracErrorMess();

    }
    else {

        TextViewer t(std::cout); // Par défaut
        Vecteur vitesse({getSelectedButton()->getVX(), getSelectedButton()->getVY(), getSelectedButton()->getVZ()});

        if(m_typeChoisi == CONE){

            Vecteur param({getSelectedButton()->getPX(), getSelectedButton()->getPY(), getSelectedButton()->getPZ()});
            m_sys.push_back(new ConeSimple(t, param, vitesse, pos, m_bCone->getRayon(), m_bCone->getHauteur(), m_bCone->getMVol()));

        }

        else if (m_typeChoisi == CHINOISE){

            Vecteur param({getSelectedButton()->getPX(), getSelectedButton()->getPY(), getSelectedButton()->getPZ()});
            m_sys.push_back(new ConeSimple(t, param, vitesse, pos, m_bChinoise->getRayon(), m_bChinoise->getHauteur(), m_bChinoise->getMVol()));

            //NDP : A mettre à jour lorsque nous aurons des toupies chinoises
        }

        else if (m_typeChoisi == BILLE){

            m_sys.push_back(new Bille(t, pos, vitesse, m_bBille->getRayon()));

        }

        else if (m_typeChoisi == OSCILLATEUR){
            Vecteur param({getSelectedButton()->getPX(), getSelectedButton()->getPY(), getSelectedButton()->getPZ()});
            m_sys.push_back(new Oscillateur(t, param, vitesse, pos, m_bOscillateur->getRayon()));
        }

    }

}


void Grillage::delIntegrable(){

    for(size_t k(0); k < m_sys.size(); k++){

        int i(m_sys[k]->getPosition().getCoord(0));
        int j(m_sys[k]->getPosition().getCoord(1));

        //On vérifie si le bouton correspondant est désactivé
        if (m_boutonsPos[i][j]->getCouleur() == GRIS){
            delete m_sys[k];
            m_sys[k] = m_sys.back();
            m_sys.pop_back();
            k--;
        }

    }
}


void Grillage::sendCaracErrorMess(){

    switch(m_typeChoisi){

    case Null:
        return;

    case CHINOISE:
    case CONE:
        QMessageBox::information(this, "Erreur", "Veuillez renseigner un rayon, une hauteur et une masse volumique.");
        break;

    case OSCILLATEUR:
    case BILLE:
        QMessageBox::information(this, "Erreur", "Veuillez renseigner un rayon.");
        break;


    }


}




TypeBouton* Grillage::getSelectedButton() const{

    switch(m_typeChoisi){

    case Null:
        return nullptr;

    case CONE:
        return m_bCone;

    case CHINOISE:
        return m_bChinoise;

    case BILLE:
        return m_bBille;

    case OSCILLATEUR:
        return m_bOscillateur;

    }

}
