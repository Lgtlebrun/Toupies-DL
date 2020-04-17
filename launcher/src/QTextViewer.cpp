#include "../headers/QTextViewer.h"
#include <iostream>


QTextViewer::QTextViewer(TextEdit& flux) : m_flux(flux){}
/* On construit un QTextViewer à partir de l'endroit où l'on désire que la sortie soit visible */

// ================================================================================================

QTextViewer *QTextViewer::clone() const {
/* Méthode de clonage de la classe QTextViewer */
    return new QTextViewer(*this);
}

// ===============================================================================================

void QTextViewer::dessine(Systeme const& S) {
/* Affiche textuellement chaque paramètre et vitesse de chaque toupie */

    unsigned int taille(S.getNbCorps());



    m_flux << QString("t=") + QString::fromStdString(std::to_string(S.getTemps())) + QString(" : ") << QString::fromStdString("\n");

    for (size_t k(0); k < taille; k++){

        m_flux << "Objet " + QString::fromStdString(std::to_string(k+1)) + " :  ";
        S.getCorps(k)->dessine();                       // appel à la méthode dessine de chaque intégrable,

                                      // qui va a son tour appeler les trois méthodes ci-dessous
    }
         m_flux << "\n";
}


void QTextViewer::dessine(Bille const& B) {

    m_flux << QString::fromStdString(B.getParam().to_str());
}
void QTextViewer::dessine(Oscillateur const& OH) {

    m_flux << QString::fromStdString(OH.getParam().to_str());
}
void QTextViewer::dessine(ConeSimple const& C) {

    m_flux << QString::fromStdString(C.getParam().to_str());
}
