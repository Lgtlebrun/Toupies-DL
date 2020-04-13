//
// Created by lgtle on 13/04/2020.
//

#include <QWidget>
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


class FichierSearch : public QWidget {

Q_OBJECT

public:

    FichierSearch();

    //Accesseurs
    Bloc2Boutons* getBlocBoutons() const;
    std::string getPath() const {return m_path.toStdString();}

    //Vérification de la validité du path
    void pathCheck();

    //Gestion des évènements clavier (touche entrée)


signals:
    void fichierPret();

protected:

    Bloc2Boutons* m_blocBoutons;
    QTextEdit* m_bar;
    QLabel* m_errMess;
    QString m_path;

};



#endif //TOUPIES_DL_FICHIERSEARCH_H
