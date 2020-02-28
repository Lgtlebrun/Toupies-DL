#include "Vecteur.h"
#include <vector>
#include <iostream>
#include <cmath>




double const PREC(1e-10);



void Vecteur::augmente(double coordSupplementaire){

    /// Ajoute une dimension au Vecteur en augmentant le vector d'une case

    m_coords.push_back(coordSupplementaire);

}



void Vecteur::setCoord(unsigned int nEmeCoord, double nouvelleValeur){

    /// Permet de modifier la valeur d'une coordonnée


    m_coords[nEmeCoord] = nouvelleValeur;

}



void Vecteur::affiche() const{

    /// Affichage de type "[x1, x2, ... , xN]"


    unsigned int taille(m_coords.size());

    std::cout << "[";

    if(taille != 0) {

        std::cout << m_coords[0];

        for (size_t i(1); i < taille; i++){

            std::cout << ", " << m_coords[i];

        }

    }

    std::cout << "]" << std::endl;
}



bool Vecteur::compare(Vecteur const& vecteur2) const{

    /// Comparaison des deux vecteurs : nombre de dimensions, coordonnées

     if(m_coords.size() != vecteur2.m_coords.size())  {return false;}       // Comparaison des dimensions

     for (size_t i(0); i < m_coords.size(); i++){

        if (m_coords[i] - vecteur2.m_coords[i] > PREC) {return false;}      // Comparaison des coordonnées

     }

     return true;
}



Vecteur Vecteur::addition(Vecteur const& vecteur2) const{

    /// Permet l'addition de deux vecteurs. Priorise la plus grande dimension.


    Vecteur sortie;

    double dim1(m_coords.size()), dim2(vecteur2.m_coords.size());

    size_t i(0);

    for (i; i < std::min(dim1, dim2); i++){

            sortie.augmente(m_coords[i] + vecteur2.m_coords[i]);

    }


    for (i; i < std::max(dim1, dim2); i++){

        if (i < dim1) {sortie.augmente(m_coords[i]);}

        else {sortie.augmente(vecteur2.m_coords[i]);}

    }


    return sortie;
}



Vecteur Vecteur::mult(double scalaire) const{ // on multiplie chaque coordonnée par le scalaire

    Vecteur sortie;

    for (size_t k(0); k < m_coords.size(); k++){

        sortie.augmente(scalaire*m_coords[k]);

    }

    return sortie;
}



Vecteur Vecteur::soustr(Vecteur const& vecteur2) const{

    /// Soustraction du vecteur 2

        Vecteur sortie(addition(vecteur2.mult(-1)));

        return sortie;
}



Vecteur Vecteur::oppose() const{

    /// Retourne le vecteur opposé

    Vecteur sortie(mult(-1));

    return sortie;
}



double Vecteur::prodScalaire(Vecteur const& vecteur2) const{

    /// Retourne le produit scalaire de deux vecteurs

    double sortie(0);
    unsigned int dim1(m_coords.size()), dim2(vecteur2.m_coords.size());

    for(size_t i(0); i < std::min(dim1,dim2); i++){

        sortie += m_coords[i] * vecteur2.m_coords[i];
    }


    return sortie;
}



Vecteur Vecteur::prodVectoriel(Vecteur const& vecteur2) const{

    /// Retourne le produit vectoriel de deux vecteurs

    /*  /!\ Méthode prévue pour des vecteurs à 3 dimensions seulement /!\  */

    Vecteur sortie;

    if (m_coords.size() != 3 || vecteur2.m_coords.size() != 3){ // le produit vectoriel n'est défini que comme
                                            // opération R^3 --> R^3
        throw "taille incompatible";

    } else { // opérations du produit vectoriel

        sortie.augmente(m_coords[2]*vecteur2.m_coords[3] - m_coords[3]*vecteur2.m_coords[2]);
        sortie.augmente(m_coords[3]*vecteur2.m_coords[1] - m_coords[1]*vecteur2.m_coords[3]);
        sortie.augmente(m_coords[1]*vecteur2.m_coords[2] - m_coords[2]*vecteur2.m_coords[1]);

    }


    return sortie;
}



double Vecteur::norme2() const{

    /// Calcule le carré de la norme

    double sortie(0);

    for (size_t k(0); k < m_coords.size(); ++k) {sortie += m_coords[k]*m_coords[k];}

    return sortie;
}



double Vecteur::norme() const{ // Pythagore à n dimensions

    /// Calcule la norme

    return sqrt(norme2());

}




Vecteur Vecteur::unitaire() const{

    /// Renvoie le vecteur unitaire (même direction, même sens)

    double longueur(norme());

    if (longueur == 0) { // Eviter la future division par 0

        throw "Le vecteur nul n'a pas de direction";

    }


    Vecteur sortie;

    for (size_t k(0); k < m_coords.size(); ++k) {sortie.augmente(m_coords[k] / longueur);}

    return sortie;
}
