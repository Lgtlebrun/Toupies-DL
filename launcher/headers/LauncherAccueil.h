#include <QWidget>
#include <QApplication>
#include <QMovie>
#include <QLabel>
#include <QDir>
#include <QString>
#include <QInputDialog>
#include <string>
#include <iostream>
#include "bordMode.h"
#include "Grillage.h"
#include "../../general/headers/SupportADessin.h"
#include "../../general/headers/TextViewer.h"
#include "../../general/headers/Integrateur.h"
#include "../../general/headers/Systeme.h"
#include "../../Qt_GL/glwidget.h"




#ifndef TOUPIES_DL_LAUNCHERACCUEIL_H
#define TOUPIES_DL_LAUNCHERACCUEIL_H


class LauncherAccueil : public QWidget {


    Q_OBJECT

public:
    LauncherAccueil();
    virtual ~LauncherAccueil();

    void go();
    void goTexte();
    void goImage();
    void goFichier();
    void setInteg();

    void launchGrillage();


public slots:

    void suppPret();



protected:

    QMovie* m_toupieBleue;
    QMovie* m_toupieVisage;
    QLabel* m_titre;
    BordMode* m_bord;

    Grillage* m_grillage; // Le frérot

    SupportADessin* m_support;
    Integrateur* m_integ;

    QWidget* m_simulation;

};




#endif //TOUPIES_DL_LAUNCHERACCUEIL_H
