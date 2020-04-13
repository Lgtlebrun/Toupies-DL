#include <QWidget>
#include <QMovie>
#include <QLabel>
#include <QDir>
#include <QString>
#include "bordMode.h"
#include "../../general/headers/SupportADessin.h"
#include "../../general/headers/TextViewer.h"



//
// Created by lgtle on 12/04/2020.
//

#ifndef TOUPIES_DL_LAUNCHERACCUEIL_H
#define TOUPIES_DL_LAUNCHERACCUEIL_H


class LauncherAccueil : public QWidget {


public:
    LauncherAccueil();



protected:

    QMovie* m_toupieBleue;
    QMovie* m_toupieVisage;
    QLabel* m_titre;
    BordMode* m_bord;

    SupportADessin* m_support;


};




#endif //TOUPIES_DL_LAUNCHERACCUEIL_H
