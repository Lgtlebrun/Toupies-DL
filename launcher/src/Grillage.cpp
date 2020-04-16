#include "../headers/Grillage.h"



Grillage::Grillage(QWidget* parent) :  QWidget(parent), m_typeChoisi(Null), m_BoxIntegrateur(0), m_bCone(0),
m_bChinoise(0), m_bBille(0), m_bOscillateur(0), m_go(0), m_echelle(0), m_slider(0){

 setFixedSize(1900, 1200); // Un GRAND grillage


 QVBoxLayout* mainLay = new QVBoxLayout;
 mainLay->setAlignment(Qt::AlignTop);
 mainLay->setSpacing(0);

 QHBoxLayout* layIntegrateur = new QHBoxLayout;
 QVBoxLayout* layIntegBis = new QVBoxLayout;
 layIntegBis->setAlignment((Qt::AlignBottom));
 layIntegBis->setSpacing(5);
 layIntegrateur->setAlignment(Qt::AlignLeft);

 QHBoxLayout* grillePlusBoutonPlusSlider = new QHBoxLayout;
 grillePlusBoutonPlusSlider->setAlignment(Qt::AlignRight);

 QGridLayout* laygrille = new QGridLayout;
 laygrille->setSpacing(0);



 //Setup Integrateur

    QLabel* labEchelle = new QLabel("Echelle :",this);
    labEchelle->move(40, 5);

    m_echelle = new QLCDNumber(this);
    m_echelle->display(1);
    m_echelle->setSegmentStyle(QLCDNumber::Flat);
    m_echelle->setFixedWidth(100);
    m_echelle->setFixedHeight(90);
    m_echelle->move(40, 30);

    m_echelle->setPalette(Qt::green);
    m_echelle->setAutoFillBackground(true);
    m_echelle->setStyleSheet("background-color: grey; color: rgb(0,200,40);");

    m_slider = new QSlider(Qt::Vertical, this);

    m_slider->setFixedSize(30, 600);
    m_slider->setMinimum(1);
    m_slider->setMaximum(100);
    m_slider ->move(80, 150);

    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_echelle, SLOT(display(int)));

    m_BoxIntegrateur = new QComboBox(this);
    QLabel* integrateur = new QLabel("Integrateur :", this);

    m_BoxIntegrateur->addItem("Euler-Cromer");
    m_BoxIntegrateur->addItem("Newmark");


    layIntegBis->addWidget(integrateur);
    layIntegBis->addWidget(m_BoxIntegrateur);
    layIntegBis->setSpacing(5);

    layIntegrateur->addLayout(layIntegBis);

    grillePlusBoutonPlusSlider->addLayout(layIntegrateur);


 //Setup Boutons Positions

    for(double j(0); j < 10; j++) {

        for(double i(0); i < 10; i++) {


            BoutonPosition* b = new BoutonPosition({i, 9-j, 0}); // On renverse l'axe des Y
            b->setFixedSize(80,80);
            b->setCursor(Qt::PointingHandCursor);

            if (m_boutonsPos.size() < (j + 1)) {m_boutonsPos.push_back({});}
            m_boutonsPos[j].push_back(b);

            QObject::connect(b, &QPushButton::clicked, b, &BoutonPosition::clickGestion);
            QObject::connect(b, &BoutonPosition::newIntegrable, this, &Grillage::addIntegrable);
            QObject::connect(b, &BoutonPosition::supprIntegrable, this, &Grillage::delIntegrable);

            //NDP : Dernière commande de la boucle
            laygrille->addWidget(b,j,i);
        }

    }

 grillePlusBoutonPlusSlider->addLayout(laygrille);



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

 grillePlusBoutonPlusSlider->addLayout(layBoutons);


  mainLay->addLayout(grillePlusBoutonPlusSlider);

    //Setup bouton GO


    m_go = new QPushButton("GO !",this);
    m_go->setFont(QFont("Cooper Black", 70, 30));
    m_go->setFixedSize(350, 155);
    m_go->setStyleSheet("background: cyan; color: white");

    m_go->move(1540, 815);
    mainLay->setSpacing(5);



    //Setup Oeil

    QPixmap pix;

    QLabel* superOeil = new QLabel(this);
    QHBoxLayout* oeilLay = new QHBoxLayout(superOeil);

    superOeil->setAlignment(Qt::AlignRight);
    superOeil->setFixedSize(578, 50);

    QLabel* oeil = new QLabel(superOeil);
    oeilLay->addWidget(oeil);

    oeilLay->setAlignment(Qt::AlignRight);
    superOeil->setLayout(oeilLay);

    oeil->setFixedSize(60,50);

    pix.load(":/icons/launcher/data/oeil.png");
    pix = pix.scaled(oeil->size(), Qt::KeepAspectRatio);
    oeil->setPixmap(pix);

    oeil->show();
    mainLay->addWidget(superOeil);

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



bool Grillage::isInOccupe(Vecteur const& v) {

    ///Méthode utilitaire vérifiant si une position est déjà attribuée à
    /// un corps du système en création

    for (auto const& elt : m_posOccupee){

        if (elt == v){return true;}
    }

    return false;
}







Vecteur Grillage::findNewPos(){

    //On itère sur les boutons

    for(auto& ligne:m_boutonsPos){
        for (auto& bouton:ligne){


            //Si le bouton est bleu ET sa position n'est pas occupée
            if(bouton->getCouleur() == BLEU && !(isInOccupe(bouton->getPos()))){

                //On retourne!
                return bouton->getPos();
            }

           }
        }



    QMessageBox::information(this, "probleme", "Erreur lors du placement. Objet placé en {0, 0, 0}");
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

    return false; // Juste pour calmer le compilateur
}


void Grillage::addIntegrable(){

    Vecteur pos(findNewPos());

    if(!checkAllCaracs()){

        for(auto& ligne : m_boutonsPos){

            for(auto& bouton : ligne){

                // SI PAS TOUTES LES CARACS : le bouton redevient gris
                if(bouton->getPos() == pos){

                    bouton->changeCouleur(GRIS);
                    }
            }
        }

        sendCaracErrorMess();

    }
    else {

        //On occupe la position
        m_posOccupee.push_back(pos);

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

            return;
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


INTEGRATEUR Grillage::getInteg() const {

    std::string integ(m_BoxIntegrateur->currentText().toStdString());

    if(integ == "Euler-Cromer"){
        return EC;
    }

    else if(integ =="Newmark"){
        return NEWMARK;
    }

    else{return EC;} //Securité -> on est bien.
}
