//
// Created by lgtle on 13/04/2020.
//

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QString>
#include <string>
#include <QPushButton>
#include <QCoreApplication>
#include <fstream>
#include "Bloc2Boutons.h"


#ifndef TOUPIES_DL_FICHIERSEARCH_H
#define TOUPIES_DL_FICHIERSEARCH_H


class FichierSearch : public QDialog {

Q_OBJECT

public:

    FichierSearch(QWidget* = nullptr);

    //Accesseurs
    Bloc2Boutons* getBlocBoutons() const;
    std::string getPath() const {return m_path;}

    //Vérification de la validité du path
    void pathCheck();

    //Gestion des évènements clavier (touche entrée)

signals:
    void fichierPret();

protected:

    Bloc2Boutons* m_blocBoutons;
    QTextEdit* m_bar;
    QLabel* m_errMess;
    std::string m_path;

};



#endif //TOUPIES_DL_FICHIERSEARCH_H
