#ifndef SCGLWIDGET_H
#define SCGLWIDGET_H

#include "../../Qt_GL/glwidget.h"
#include <fstream>


class ScGLWidget : public GLWidget {

    /// Classe héritant de GLWidget permettant des fonctionnalités scientifiques:
    /// Trace et sauvegarde de données


// ========================== METHODES ==============================

public:

    //  Cstor
    ScGLWidget(Systeme& S, std::string nomInteg, Vecteur const& POV = Vecteur({4.5,-10.0,0.0}), bool trace = false,
               QWidget* parent = nullptr);


    //  Surcharge de paintGL : on permet l'affichage de la trace
    virtual void paintGL()                       override;

    //  METHODES
    void saveData();                                                // Sauvegarde des données


// ========================= ATTRIBUTS ===============================

private:

    bool m_trace;                   // Booléen décidant de l'affichage de la trace

    std::string m_nomInteg;         // Nom de l'intégrateur utilisé

    //FLOTS
    std::ofstream fluxE;            //  Vers le fichier Energie
    std::ofstream fluxLa;           //  "" Moment cinétique La
    std::ofstream fluxLk;           //  "" Lk
    std::ofstream fluxPMixte;       //  "" Produit Mixte

};

#endif // SCGLWIDGET_H
