#include "../headers/TypeBouton.h"

TypeBouton::TypeBouton(Type type, QWidget* parent) : QPushButton(parent), m_type(type),
m_barMVol(0), m_barRayon(0), m_barHauteur(0), m_pressed(false) {


    /// CONSTRUCTEUR

    setFixedSize(940, 200);
    QHBoxLayout* mainlay = new QHBoxLayout;
    mainlay->setAlignment(Qt::AlignLeft);

    QVBoxLayout* barresLay = new QVBoxLayout;

    QHBoxLayout* paramLay = new QHBoxLayout;
    QHBoxLayout* vitesseLay = new QHBoxLayout;
    QHBoxLayout* caracsLay = new QHBoxLayout;

    caracsLay->setAlignment(Qt::AlignRight);

    //Setup longueur des spinboxs

    int wSBox(130);

    // Setup des barres

    m_barRayon = new QDoubleSpinBox(this);
    m_barHauteur = new QDoubleSpinBox(this);
    m_barMVol = new QDoubleSpinBox(this);

    m_barRayon->setPrefix("Rayon :");
    m_barHauteur->setPrefix("Hauteur :");
    m_barMVol->setPrefix("MasseVol :");

    m_barRayon->setMinimum(0);
    m_barHauteur->setMinimum(0);
    m_barMVol->setMinimum(0);

    m_barRayon->setDecimals(2);
    m_barHauteur->setDecimals(2);
    m_barMVol->setDecimals(2);

    m_barRayon->setSingleStep(0.1);
    m_barHauteur->setSingleStep(0.1);
    m_barMVol->setSingleStep(0.1);

    m_barRayon->setValue(0);
    m_barHauteur->setValue(0);
    m_barMVol->setValue(0);

    m_barRayon->setAccelerated(true);
    m_barHauteur->setAccelerated(true);
    m_barMVol->setAccelerated(true);

    m_barRayon->setStyleSheet("background: white");
    m_barHauteur->setStyleSheet("background: white");
    m_barMVol->setStyleSheet("background: white");

    m_barRayon->setFixedWidth(wSBox);
    m_barHauteur->setFixedWidth(wSBox);
    m_barMVol->setFixedWidth(wSBox);

    //Setup de la photo
    m_photo = new QLabel(this);
    m_photo->setGeometry(5,5,245,245);
    QMovie* tof(0);

    //Setup du nom
    QLabel* nom(0);

    //Customization
    switch(m_type){

    case CONE:
        tof = new QMovie(":/icons/cone.gif");
        nom = new QLabel("Cone Simple", this);
        break;

    case CHINOISE:
        tof = new QMovie(":/icons/chinoise.gif");
        nom = new QLabel("Chinoise", this);
        break;

    case BILLE:
        tof = new QMovie(":/icons/bille.gif");
        nom = new QLabel("Bille", this);
        m_barHauteur->hide();
        m_barMVol->hide();
        break;

    case OSCILLATEUR:
        tof = new QMovie(":/icons/oscillateur.gif");
        nom = new QLabel("Oscillateur", this);
        m_barHauteur->hide();
        m_barMVol->hide();
        break;

    case Null:
        break;

    }


    tof->setScaledSize(QSize(245,245));
    m_photo->setMovie(tof);
    tof->start();

    nom->setFixedWidth(100);


    //Ajout de la photo
    mainlay->addWidget(m_photo);

    //Ajout du nom
    mainlay ->addWidget(nom);

    //Ajout des barres au layout
    caracsLay->addWidget(m_barRayon);
    caracsLay->addWidget(m_barHauteur);
    caracsLay->addWidget(m_barMVol);



    //Setup Params

    m_LabParam = new QLabel("Param en t=0 :", this);


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

    m_pX->setStyleSheet("background: white");
    m_pY->setStyleSheet("background: white");
    m_pZ->setStyleSheet("background: white");

    m_pX->setFixedWidth(wSBox);
    m_pY->setFixedWidth(wSBox);
    m_pZ->setFixedWidth(wSBox);

    paramLay->addWidget(m_LabParam);
    paramLay->addWidget(m_pX);
    paramLay->addWidget(m_pY);
    paramLay->addWidget(m_pZ);


    //Setup vitesse

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

    m_vX->setStyleSheet("background: white");
    m_vY->setStyleSheet("background: white");
    m_vZ->setStyleSheet("background: white");

    m_vX->setFixedWidth(wSBox);
    m_vY->setFixedWidth(wSBox);
    m_vZ->setFixedWidth(wSBox);

    vitesseLay->addWidget(vitesse);
    vitesseLay->addWidget(m_vX);
    vitesseLay->addWidget(m_vY);
    vitesseLay->addWidget(m_vZ);


    barresLay->addLayout(caracsLay);
    barresLay->addLayout(paramLay);
    barresLay->addLayout(vitesseLay);

    mainlay->addLayout(barresLay);

    setLayout(mainlay);


    //Setup spécifique


    switch(m_type){

    case BILLE:

        m_LabParam->hide();
        m_pX->hide();
        m_pY->hide();
        m_pZ->hide();
        break;

    case OSCILLATEUR:

        m_LabParam->setText("Pos° initiale:");
        m_pX->setPrefix("X :");
        m_pY->setPrefix("Y :");
        m_pZ->setPrefix("Z :");
        break;

    case CHINOISE:
    case CONE:

        m_pX->setPrefix("Theta :");
        m_pY->setPrefix("Psi :");
        m_pZ->setPrefix("Phi :");

        m_vX->setPrefix("Theta :");
        m_vY->setPrefix("Psi :");
        m_vZ->setPrefix("Phi :");
        break;

    default:
        return;

    }

}


void TypeBouton::changeStatut() {

    /// Réagit au click

    if(m_pressed) {
        m_pressed = false;
    }
    else {
        m_pressed = true;
    }

    emit statutChange();
}



void TypeBouton::changeSkin(){

    /// Change la couleur selon le statut

    if(m_pressed){
        setStyleSheet("background: cyan");
    }
    else{
        setStyleSheet("background: none");
    }

}




void TypeBouton::setPresse(bool presse) {

    /// Modifie m_pressed
    m_pressed = presse;
}
