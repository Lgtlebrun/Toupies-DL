//
// Created by lgtle on 13/04/2020.
//
#include "../headers/fichierSearch.h"
#include <fstream>

FichierSearch::FichierSearch(QWidget* parent) : QDialog(parent), m_path(QCoreApplication::applicationDirPath().toStdString()){

    setFixedSize(700, 120);
    setStyleSheet("background: none");

    QLabel* texte(new QLabel("Entrez un chemin de dossier valide :", this));
    texte->move(10, 10);

    m_errMess = new QLabel("Chemin d'accès non valide", this);
    m_errMess->setStyleSheet("color:red");
    m_errMess->move(10, 80);
    m_errMess->hide();


    m_bar = new QLineEdit(QString::fromStdString(m_path), this);
    m_bar->setFixedSize(680, 30);
    m_bar->move(10, 40);

    m_blocBoutons = new Bloc2Boutons(this);
    m_blocBoutons->move(500, 70);


    //Connexiooooooooon !

    QObject::connect(m_blocBoutons->getBOk(), &QPushButton::clicked, this, &FichierSearch::pathCheck);
    QObject::connect(m_blocBoutons->getBCancel(), &QPushButton::clicked, this, &FichierSearch::hide);

}


void FichierSearch::pathCheck()
{

    m_path = m_bar->text().toStdString();


    while(m_path.back() == ' ') {m_path.pop_back();}
    if(m_path.back() != '/') {m_path += '/';}
    m_path += "UltimateSimulation.txt";

    std::ofstream flux(m_path);

    if(flux.fail()){

        m_errMess->show();
        return;
    }

    hide();
    emit fichierPret();
}


Bloc2Boutons* FichierSearch::getBlocBoutons() const {return m_blocBoutons;}





