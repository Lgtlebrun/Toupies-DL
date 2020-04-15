#include "../headers/Grillage.h"

Grillage::Grillage(QWidget* parent) :  QWidget(parent), m_typeChoisi(Null), m_BoxIntegrateur(0), m_bCone(0),
m_bChinoise(0), m_bBille(0), m_bOscillateur(0), m_vX(0), m_vY(0), m_vZ(0),
m_pX(0), m_pY(0), m_pZ(0), m_LabParam(0){

 setFixedSize(1900, 1200); // Un GRAND grillage

 QVBoxLayout* mainLay = new QVBoxLayout;
 mainLay->setAlignment(Qt::AlignTop);
 mainLay->setSpacing(20);

 QHBoxLayout* layParam = new QHBoxLayout;
 layParam->setAlignment(Qt::AlignCenter);

 QHBoxLayout* layVitesse = new QHBoxLayout;
 layVitesse->setAlignment(Qt::AlignCenter);

 QHBoxLayout* layIntegrateur = new QHBoxLayout;
 layIntegrateur->setAlignment(Qt::AlignCenter);

 QHBoxLayout* grillePlusBouton = new QHBoxLayout;
 grillePlusBouton->setAlignment(Qt::AlignRight);

 QGridLayout* laygrille = new QGridLayout;
 laygrille->setSpacing(0);


 //NDP : c'est ici qu'on connectera les boutons
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


 //Setup Param

 m_LabParam = new QLabel("Paramètres initiaux :", this);
 m_pX = new QDoubleSpinBox(this);
 m_pY = new QDoubleSpinBox(this);
 m_pZ = new QDoubleSpinBox(this);

 m_pX->setPrefix("Theta : ");
 m_pY->setPrefix("Psy : ");
 m_pZ->setPrefix("Phi : ");

 m_pX->setValue(0);
 m_pY->setValue(0);
 m_pZ->setValue(0);

 m_pX->setMinimum(-1e15);
 m_pY->setMinimum(-1e15);
 m_pZ->setMinimum(-1e15);

 m_pX->setSingleStep(0.1);
 m_pY->setSingleStep(0.1);
 m_pZ->setSingleStep(0.1);

 m_pX->setDecimals(2);
 m_pY->setDecimals(2);
 m_pZ->setDecimals(2);

 m_pX->setAccelerated(true);
 m_pY->setAccelerated(true);
 m_pZ->setAccelerated(true);

 layParam->addWidget(m_LabParam);
 layParam->addWidget(m_pX);
 layParam->addWidget(m_pY);
 layParam->addWidget(m_pZ);


 mainLay->addLayout(layParam);





 //Setup Vitesse

 QLabel* vitesse = new QLabel("Vitesse initiale :", this);
 m_vX = new QDoubleSpinBox(this);
 m_vY = new QDoubleSpinBox(this);
 m_vZ = new QDoubleSpinBox(this);

 m_vX->setPrefix("X : ");
 m_vY->setPrefix("Y : ");
 m_vZ->setPrefix("Z : ");

 m_vX->setValue(0);
 m_vY->setValue(0);
 m_vZ->setValue(0);

 m_vX->setMinimum(-1e15);
 m_vY->setMinimum(-1e15);
 m_vZ->setMinimum(-1e15);

 m_vX->setSingleStep(0.1);
 m_vY->setSingleStep(0.1);
 m_vZ->setSingleStep(0.1);

 m_vX->setDecimals(2);
 m_vY->setDecimals(2);
 m_vZ->setDecimals(2);

 m_vX->setAccelerated(true);
 m_vY->setAccelerated(true);
 m_vZ->setAccelerated(true);

 layVitesse->addWidget(vitesse);
 layVitesse->addWidget(m_vX);
 layVitesse->addWidget(m_vY);
 layVitesse->addWidget(m_vZ);


 mainLay->addLayout(layVitesse);


 //Setup Integrateur

    m_BoxIntegrateur = new QComboBox(this);
    QLabel* integrateur = new QLabel("Integrateur :", this);

    m_BoxIntegrateur->addItem("Euler-Cromer");
    m_BoxIntegrateur->addItem("Newmark");

    layIntegrateur->addWidget(integrateur);
    layIntegrateur->addWidget(m_BoxIntegrateur);

    mainLay->addLayout(layIntegrateur);


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
    if(m_typeChoisi == BILLE){

        m_LabParam->hide();
        m_pX->hide();
        m_pY->hide();
        m_pZ->hide();
    }
    else{

        m_LabParam->show();
        m_pX->show();
        m_pY->show();
        m_pZ->show();
    }

    if(m_typeChoisi == OSCILLATEUR){

        m_pX->setPrefix("X :");
        m_pY->setPrefix("Y :");
        m_pZ->setPrefix("Z :");
    }

    if (m_typeChoisi == CONE || m_typeChoisi == CHINOISE){

        m_pX->setPrefix("Theta :");
        m_pY->setPrefix("Psi :");
        m_pZ->setPrefix("Phi :");
    }


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

    }
    else {

        TextViewer t(std::cout); // Par défaut
        Vecteur vitesse({m_vX->value(), m_vY->value(), m_vZ->value()});

        if(m_typeChoisi == CONE){

            Vecteur param({m_pX->value(), m_pY->value(), m_pZ->value()});
            m_sys.push_back(new ConeSimple(t, param, vitesse, pos, m_bCone->getRayon(), m_bCone->getHauteur(), m_bCone->getMVol()));

        }

        else if (m_typeChoisi == CHINOISE){

            Vecteur param({m_pX->value(), m_pY->value(), m_pZ->value()});
            m_sys.push_back(new ConeSimple(t, param, vitesse, pos, m_bChinoise->getRayon(), m_bChinoise->getHauteur(), m_bChinoise->getMVol()));

            //NDP : A mettre à jour lorsque nous aurons des toupies chinoises
        }

        else if (m_typeChoisi == BILLE){

            m_sys.push_back(new Bille(t, pos, vitesse, m_bBille->getRayon()));

        }

        else if (m_typeChoisi == OSCILLATEUR){
            Vecteur param({m_pX->value(), m_pY->value(), m_pZ->value()});
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
