//
// Created by lgtle on 13/04/2020.
//
#include "../headers/fichierSearch.h"

FichierSearch::FichierSearch() : m_path("data/"){

    setFixedSize(600, 120);


    QLabel* texte(new QLabel("Entrez un chemin de dossier valide :", this));
    texte->move(10, 10);


    m_bar = new QTextEdit(m_path, this);
    m_bar->setFixedSize(580, 30);
    m_bar->move(10, 40);

    m_blocBoutons = new Bloc2Boutons(this);
    m_blocBoutons->move(400, 70);




}
