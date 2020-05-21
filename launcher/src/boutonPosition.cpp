#include "../headers/boutonPosition.h"

BoutonPosition::BoutonPosition(Vecteur const& pos, QWidget* parent) : QPushButton("", parent), m_couleur(GRIS),
    m_pastille(0), m_position(pos) {

    /// CONSTRUCTEUR

    // Setup pastille
    m_pastille = new QLabel(this);
    m_pastille->setAlignment(Qt::AlignCenter);

    // Setup layout
    QVBoxLayout* lay = new QVBoxLayout;
    lay->addWidget(m_pastille);
    this->setLayout(lay);

    changeCouleur(m_couleur);
}




void BoutonPosition::changeCouleur(Couleur c){

    /// Change la couleur du bouton

    m_couleur = c;

    QPixmap pix;
    QSize scale(m_pastille->size() + QSize(70,70));

    switch(c){

    case GRIS:
        pix.load(":/icons/pastilleGrise.png");
        pix = pix.scaled(scale, Qt::KeepAspectRatio);
        break;

    case BLEU:
        pix.load(":/icons/boutonBleu.png");
        pix = pix.scaled(scale, Qt::KeepAspectRatio);
        break;

    }

    m_pastille->setPixmap(pix);
}



void BoutonPosition::clickGestion(){

    /// Emet le signal approprié en fonction du staut (Position occupée/libérée)

    switch(m_couleur){

    case GRIS:
        changeCouleur(BLEU);
        emit newIntegrable();
        break;

    case BLEU:
        changeCouleur(GRIS);
        emit supprIntegrable();
        break;
    }
}
