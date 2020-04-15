#include "../headers/TypeBouton.h"

TypeBouton::TypeBouton(Type type, QWidget* parent) : QPushButton(parent), m_type(type),
m_barMVol(0), m_barRayon(0), m_barHauteur(0), m_pressed(false) {

    setFixedSize(900, 200);
    QHBoxLayout* lay = new QHBoxLayout;
    lay->setAlignment(Qt::AlignLeft);

    // Setup des barres

    m_barRayon = new QDoubleSpinBox(this);
    m_barHauteur = new QDoubleSpinBox(this);
    m_barMVol = new QDoubleSpinBox(this);

    m_barRayon->setPrefix("Rayon :");
    m_barHauteur->setPrefix("Hauteur :");
    m_barMVol->setPrefix("MVolumique :");

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




    //Setup de la photo
    m_photo = new QLabel(this);
    m_photo->setGeometry(5,5,245,245);
    QMovie* tof(0);

    //Setup du nom
    QLabel* nom(0);

    //Customization
    switch(m_type){

    case CONE:
        tof = new QMovie(":/icons/launcher/data/cone.gif");
        nom = new QLabel("Cone Simple", this);
        break;

    case CHINOISE:
        tof = new QMovie(":/icons/launcher/data/chinoise.gif");
        nom = new QLabel("Chinoise", this);
        break;

    case BILLE:
        tof = new QMovie(":/icons/launcher/data/bille.gif");
        nom = new QLabel("Bille", this);
        m_barHauteur->hide();
        m_barMVol->hide();
        break;

    case OSCILLATEUR:
        tof = new QMovie(":/icons/launcher/data/oscillateur.gif");
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
    lay->addWidget(m_photo);

    //Ajout du nom
    lay ->addWidget(nom);

    //Ajout des barres au layout
    lay->addWidget(m_barRayon);
    lay->addWidget(m_barHauteur);
    lay->addWidget(m_barMVol);

    setLayout(lay);
}


void TypeBouton::changeStatut() {

    if(m_pressed) {
        m_pressed = false;
    }
    else {
        m_pressed = true;
    }

    emit statutChange();
}



void TypeBouton::changeSkin(){

    if(m_pressed){
        setStyleSheet("background: cyan");
    }
    else{
        setStyleSheet("background: none");
    }

}




void TypeBouton::setPresse(bool presse) {

    m_pressed = presse;
}
