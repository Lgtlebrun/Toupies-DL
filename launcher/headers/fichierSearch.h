//
// Created by lgtle on 13/04/2020.
//

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <string>
#include <QPushButton>
#include <QCoreApplication>
#include <fstream>
#include "Bloc2Boutons.h"


#ifndef TOUPIES_DL_FICHIERSEARCH_H
#define TOUPIES_DL_FICHIERSEARCH_H


class FichierSearch : public QDialog {

    /// Fenetre modale de recherche d'un chemin (path) pour le
    /// format fichier.

Q_OBJECT

public:

    FichierSearch(QWidget* = nullptr);

    //Accesseurs
    Bloc2Boutons* getBlocBoutons() const;
    std::string getPath() const {return m_path;}

    //Vérification de la validité du path
    void pathCheck();


signals:

    //Indique au LauncherAccueil la validité du path
    void fichierPret();

protected:

    Bloc2Boutons* m_blocBoutons;    // Les boutons Ok et Cancel
    QLineEdit* m_bar;               // Widget où enter le path
    QLabel* m_errMess;              // Message d'erreur "chemin invalide"


    std::string m_path;             //Le path en question

};



#endif //TOUPIES_DL_FICHIERSEARCH_H
