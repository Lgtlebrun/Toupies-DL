#include "../headers/Bloc2Boutons.h"

Bloc2Boutons::Bloc2Boutons(QWidget* parent) : QWidget(parent){

    setFixedSize(210, 60);

    m_bOk = new QPushButton("Ok");
    m_bOk->setFixedSize(80, 30);

    m_bCancel = new QPushButton("Cancel");
    m_bCancel->setFixedSize(80, 30);

    QHBoxLayout* blocBouton(new QHBoxLayout(this));

    blocBouton->addWidget(m_bOk);
    blocBouton->addWidget(m_bCancel);

}

QPushButton* Bloc2Boutons::getBOk() {return m_bOk;}

QPushButton* Bloc2Boutons::getBCancel() {return m_bCancel;}


