//
// Created by lgtle on 13/04/2020.
//
#include "../headers/fichierSearch.h"
#include <fstream>

FichierSearch::FichierSearch(std::string nom, QWidget* parent) : QDialog(parent), m_path(QCoreApplication::applicationDirPath().toStdString())
, m_nom(nom){

    /// CONSTRUCTEUR
    /// m_path : On suggère le chemin d'où l'application est lancée
    /// m_nom : nom du fichier texte qui sera généré

    setFixedSize(700, 120);
    setStyleSheet("background: none");

    QLabel* texte(new QLabel("Entrez un chemin de dossier valide :", this));
    texte->move(10, 10);


    // Label en cas de chemin invalide
    m_errMess = new QLabel("Chemin d'accès non valide", this);
    m_errMess->setStyleSheet("color:red");
    m_errMess->move(10, 80);
    m_errMess->hide();


    // Setup champ à remplir
    m_bar = new QLineEdit(QString::fromStdString(m_path), this);
    m_bar->setFixedSize(680, 30);
    m_bar->move(10, 40);

    // Setup bloc des boutons
    m_blocBoutons = new Bloc2Boutons(this);
    m_blocBoutons->move(500, 70);


    //Connexiooooooooon !

    QObject::connect(m_blocBoutons->getBOk(), &QPushButton::clicked, this, &FichierSearch::pathCheck);
    QObject::connect(m_blocBoutons->getBCancel(), &QPushButton::clicked, this, &FichierSearch::hide);

    // NB : la fenêtre étant modale, gide() redonnera accès à la fenêtre principale
}


void FichierSearch::pathCheck()
{

    /// Vérifie la validité du chemin renseigné.
    /// En cas de validité : le chemin est enregistré dans m_path, la fenetre se ferme, fichierPret est émis.
    /// En cas d'invalidité : on affiche un message d'erreur, la fenetre reste ouverte.

    m_path = m_bar->text().toStdString();                   // On récupère le chemin renseigné


    while(m_path.back() == ' ') {m_path.pop_back();}        // Formatage du texte
    if(m_path.back() != '/') {m_path += '/';}
    m_path += (m_nom + ".txt");


    // TEST DE VALIDITE
    std::ofstream flux(m_path);     // On ouvre un flux

    if(flux.fail()){                // Si il échoue, on oublie l'idée

        m_errMess->show();
        return;
    }

    hide();                         // Sinon, la fenetre se ferme et
    emit fichierPret();             // on émet le signal
}


Bloc2Boutons* FichierSearch::getBlocBoutons() const {return m_blocBoutons;}





