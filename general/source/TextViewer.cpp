#include "../headers/TextViewer.h"
#include <iostream>


TextViewer::TextViewer(std::ostream& flux) : m_flux(flux){}
/* On construit un TextViewer à partir de l'endroit où l'on désire que la sortie soit visible */

// ================================================================================================

TextViewer *TextViewer::clone() const {
/* Méthode de clonage de la classe TextViewer */
    return new TextViewer(*this);
}

// ===============================================================================================

void TextViewer::dessine(Systeme const& S) {
/* Affiche textuellement chaque paramètre et vitesse de chaque toupie */

    unsigned int taille(S.getNbCorps());

    m_flux << "t=" << S.getTemps() << " : " << std::endl;

    for (size_t k(0); k < taille; k++){

        m_flux << "Objet " << k+1 << " :  ";
        S.getCorps(k)->dessine();                       // appel à la méthode dessine de chaque intégrable,
        m_flux << std::endl;                            // qui va a son tour appeler les trois méthodes ci-dessous
    }

}


void TextViewer::dessine(Bille const& B) {

    m_flux << B;
}
void TextViewer::dessine(Oscillateur const& OH) {

    m_flux << OH;
}
void TextViewer::dessine(ConeSimple const& C) {

    m_flux << C;
}
void TextViewer::dessine(ToupieChinoise const& T) {

    m_flux << T;
}
