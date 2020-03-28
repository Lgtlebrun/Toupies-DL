#include "../headers/TextViewer.h"
#include <iostream>
#include <fstream>

void TextViewer::dessine(Systeme const& S, std::ostream& flux) {

    /// Affiche textuellement chaque paramètre et vitesse de chaque toupie

    unsigned int taille(S.getNbToupies());

    for (size_t k(0); k < taille; k++){

        flux << "Toupie " << k+1 << " :  ";
        dessine(*S.getToupie(k), flux);
    }

}




void TextViewer::dessine(Integrable const& integrable, std::ostream& flux){

    flux << "Parametre : " << integrable.getParam() << "  ;  Vitesse : " << integrable.getVitesse() << std::endl;
}