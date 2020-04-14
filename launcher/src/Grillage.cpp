#include "../headers/Grillage.h"

Grillage::Grillage(QWidget* parent) :  QWidget(parent), m_grille(0) {

 setFixedSize(1700, 900); // Un GRAND grillage

 m_grille = new QWidget(this);

 QGridLayout* laygril = new QGridLayout;
 laygril->setSpacing(0);


 //NDP : c'est ici qu'on connectera les boutons
    for(int i(0); i < 10; i++) {

        for(int j(0); j < 10; j++) {


            BoutonPosition* b = new BoutonPosition;
            b->setFixedSize(80,80);

            laygril->addWidget(b,i,j);
        }

    }

 m_grille->setLayout(laygril);
}





Grillage::~Grillage(){

    for (auto& elt:m_sys){
        delete elt;
    }
}
