#include "../headers/TextViewer.h"
#include <iostream>
#include <fstream>


TextViewer::TextViewer(std::ostream& flux) : m_flux(flux){}





void TextViewer::dessine(Systeme const& S) {

    /// Affiche textuellement chaque paramètre et vitesse de chaque toupie

    unsigned int taille(S.getNbCorps());

    m_flux << "t=" << S.getTemps() << " : " << std::endl;

    for (size_t k(0); k < taille; k++){

        m_flux << "Objet " << k+1 << " :  ";
        S.getCorps(k)->dessine();
        m_flux << std::endl;
    }

}




void TextViewer::dessine(Integrable const& integrable){

    m_flux << "Type : " << integrable.getType() << "  ; Parametre : " << integrable.getParam() << "  ;  Vitesse : " << integrable.getVitesse();
}


TextViewer *TextViewer::clone() const {

    return new TextViewer(*this);
}

void TextViewer::dessine(Bille const & B) {

    Integrable::dessine(B);
    m_flux << std::endl;

}

void TextViewer::dessine(Oscillateur const & OH) {

    Integrable::dessine(OH);
    m_flux << std::endl;
}

void TextViewer::dessine(ConeSimple const & C) {

    Integrable::dessine(C);
    m_flux << "  ; Rayon : " << C.getRayon() << "  ; Hauteur : " << C.getHauteur() << std::endl;
}


