//
// Created by lgtle on 13/04/2020.
//
#include "../headers/fichierSearch.h"
#include <fstream>

FichierSearch::FichierSearch() : m_path(QCoreApplication::applicationDirPath()){

    setFixedSize(600, 120);


    QLabel* texte(new QLabel("Entrez un chemin de dossier valide :", this));
    texte->move(10, 10);

    m_errMess = new QLabel("Chemin d'accès non valide", this);
    m_errMess->setStyleSheet("color:red");
    m_errMess->move(10, 80);
    m_errMess->hide();


    m_bar = new QTextEdit(m_path, this);
    m_bar->setFixedSize(580, 30);
    m_bar->move(10, 40);

    m_blocBoutons = new Bloc2Boutons(this);
    m_blocBoutons->move(400, 70);


    //Connexiooooooooon !

    QObject::connect(m_blocBoutons->getBOk(), &QPushButton::clicked, this, &FichierSearch::pathCheck);
    QObject::connect(m_blocBoutons->getBCancel(), &QPushButton::clicked, this, &FichierSearch::hide);

}


void FichierSearch::pathCheck()
{

    m_path = m_bar->toPlainText();

    std::string path(m_path.toStdString());
    while(path.back() == ' ') {path.pop_back();}
    if(path.back() != '/') {path += '/';}
    path += "UltimateSimulation.txt";

    std::ofstream flux(path);

    if(flux.fail()){

        m_errMess->show();
        return;
    }

    hide();
    emit fichierPret();
}


Bloc2Boutons* FichierSearch::getBlocBoutons() const {return m_blocBoutons;}




