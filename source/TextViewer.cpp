#include "../headers/TextViewer.h"
#include <iostream>


void TextViewer::dessine(Systeme const & S) {

    /// Affiche textuellement chaque paramètre et vitesse de chaque toupie

    unsigned int taille(S.getNbToupies());

    for (size_t k(0); k < taille; k++){

        std::cout << "Toupie " << k+1 << " :  ";
        dessine(*S.getToupie(k));
    }

}


void TextViewer::dessine(Toupie const& T){

    std::cout << "Parametre : " << T.getParam() << "  ;  Vitesse : " << T.getVitesse() << std::endl;

}


void TextViewer::dessine(const ConeSimple & C) {

    /// Affiche textuellement l'état de paramètre et de la vitesse

    dessine(C);


}

void TextViewer::dessine(const Oscillateur & O){

    dessine(O);

}

void TextViewer::dessine(const Bille & B){

    dessine(B);

}