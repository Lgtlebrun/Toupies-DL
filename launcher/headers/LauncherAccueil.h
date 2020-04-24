#include <QWidget>
#include <QApplication>
#include <QMovie>
#include <QLabel>
#include <QDir>
#include <QString>
#include <QInputDialog>
#include <QTextStream>
#include <QFontDatabase>
#include <string>
#include <iostream>
#include "bordMode.h"
#include "Grillage.h"
#include "../../general/headers/SupportADessin.h"
#include "../../general/headers/TextViewer.h"
#include "../../general/headers/Integrateur.h"
#include "../../general/headers/Systeme.h"
#include "../../Qt_GL/glwidget.h"
#include "QTextViewer.h"
#include "TextEdit.h"


#ifndef TOUPIES_DL_LAUNCHERACCUEIL_H
#define TOUPIES_DL_LAUNCHERACCUEIL_H

class LauncherAccueil : public QWidget {


    ///Classe principale de l'interface graphique utilisateur.

    Q_OBJECT

public:
    LauncherAccueil();
    virtual ~LauncherAccueil();


    // Lancement des simulations
    void go();
    void goTexte();
    void goImage();
    void goFichier();

    // Gestion du choix de l'intégrateur
    void setInteg();


    // Lancement du "Grillage", panneau de contrôle
    void launchGrillage();


public slots:

    // Gestion du signal suivant le choix du support (Texte, image, ficher)
    void suppPret();

    // Redémarrage à la fin d'une simulation
    void restart();



protected:

    // Gifs
    QMovie* m_toupieBleue;
    QMovie* m_toupieVisage;

    QLabel* m_titre;

    // Widget enfant, utilitaire
    BordMode* m_bord;

    Grillage* m_grillage; // Le frérot

    SupportADessin* m_support;
    Integrateur* m_integ;

    QWidget* m_simulation;

};




#endif //TOUPIES_DL_LAUNCHERACCUEIL_H
