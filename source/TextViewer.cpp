#include "../headers/TextViewer.h"
#include <iostream>
#include <fstream>


TextViewer::TextViewer(std::ostream& flux) : m_flux(flux){}





void TextViewer::dessine(Systeme const& S) {

    /// Affiche textuellement chaque paramètre et vitesse de chaque toupie

    unsigned int taille(S.getNbCorps());

    m_flux << "t=" << S.getTemps() << " : " << std::endl;

    for (size_t k(0); k < taille; k++){

        m_flux << "Toupie " << k+1 << " :  ";
        dessine(*S.getCorps(k));
        m_flux << std::endl;
    }

}




void TextViewer::dessine(Integrable const& integrable){

    m_flux << "Parametre : " << integrable.getParam() << "  ;  Vitesse : " << integrable.getVitesse() << std::endl;
}


TextViewer *TextViewer::clone() const {

    return new TextViewer(*this);
}


