#include "../headers/boutonPosition.h"

BoutonPosition::BoutonPosition(QWidget* parent) : QPushButton("", parent), m_couleur(GRIS), m_pastille(0) {

    m_pastille = new QLabel(this);
    m_pastille->setAlignment(Qt::AlignCenter);
    changeCouleur(m_couleur);

    QVBoxLayout* lay = new QVBoxLayout;
    lay->addWidget(m_pastille);
    this->setLayout(lay);
}




void BoutonPosition::changeCouleur(Couleur c){

    /// Change la couleur du bouton

    m_couleur = c;

    QPixmap pix;
    QSize scale(m_pastille->size() + QSize(70,70));

    switch(c){

    case GRIS:
        pix.load(":/icons/launcher/data/pastilleGrise.png");
        pix = pix.scaled(scale, Qt::KeepAspectRatio);
        break;

    case ROUGE:
        pix.load(":/icons/launcher/data/boutonRouge.png");
        pix = pix.scaled(scale, Qt::KeepAspectRatio);
        break;

    case BLEU:
        pix.load(":/icons/launcher/data/boutonBleu.png");
        pix = pix.scaled(scale, Qt::KeepAspectRatio);
        break;

    }

    m_pastille->setPixmap(pix);
}
