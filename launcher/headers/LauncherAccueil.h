#include <QWidget>
#include <QMovie>
#include <QLabel>
#include <QDir>
#include <QString>
#include <string>
#include <iostream>
#include "bordMode.h"
#include "Grillage.h"
#include "../../general/headers/SupportADessin.h"
#include "../../general/headers/TextViewer.h"



//
// Created by lgtle on 12/04/2020.
//

#ifndef TOUPIES_DL_LAUNCHERACCUEIL_H
#define TOUPIES_DL_LAUNCHERACCUEIL_H


class LauncherAccueil : public QWidget {


    Q_OBJECT

public:
    LauncherAccueil();


public slots:

    void suppInit();



protected:

    QMovie* m_toupieBleue;
    QMovie* m_toupieVisage;
    QLabel* m_titre;
    BordMode* m_bord;

    Grillage* m_grillage; // Le frérot

    SupportADessin* m_support;


};




#endif //TOUPIES_DL_LAUNCHERACCUEIL_H
