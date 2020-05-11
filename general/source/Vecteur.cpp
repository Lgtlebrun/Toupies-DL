#include "../headers/Vecteur.h"
#include <vector>
#include <iostream>
#include <cmath>







//=========================================  CONSTRUCTEURS  ================================================



Vecteur::Vecteur() : Vecteur({0,0,0}) {}                                    // Par défaut (vecteur nul 3D)

Vecteur::Vecteur(std::initializer_list<double> il) : m_coords(il) {}        // Format : Vecteur v1({x1, ... , xn})




//==========================================  METHODES PUBLIQUES  ==================================================


// Accesseurs


double Vecteur::getCoord(unsigned int nEmeCoord) const{

    /// Retourne la valeur d'une coordonnée

    return m_coords[nEmeCoord];

}


unsigned int Vecteur::getDim() const{

    /// Retourne la dimension du vecteur

    return m_coords.size();

}


// Setteur


void Vecteur::setCoord(unsigned int nEmeCoord, double nouvelleValeur){

    /// Permet de modifier la valeur d'une coordonnée


    m_coords[nEmeCoord] = nouvelleValeur;

}


// Autre


void Vecteur::augmente(double coordSupplementaire){

    /// Ajoute une dimension au Vecteur en augmentant le vector d'une case

    m_coords.push_back(coordSupplementaire);

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

    try{

        if (longueur == 0) {                    // Eviter la future division par 0

            std::string vecnul("ERREUR: Le vecteur nul n'a pas de direction");
            throw vecnul;

        }



    Vecteur sortie({});

    for (size_t k(0); k < m_coords.size(); ++k) {sortie.augmente(m_coords[k] / longueur);}

    return sortie;

    }

    // En cas d'exception...

    catch(std::string const& vecnul){

        std::cerr << vecnul << std::endl;
        return Vecteur({0, 0, 0});              // ... retourne le vecteur nul
    }

}


std::string Vecteur::to_str() const{

    std::string str("[");
    for(auto const& elt : m_coords){
        str += std::to_string(elt);
        str += " ";
    }

    // On efface l'espace en trop
    str.erase(str.size() - 1);

    str += "]";

    return str;
}


Vecteur Vecteur::rad_to_deg() const {

    Vecteur sortie;

    for (unsigned int k(0); k < m_coords.size(); ++k) {

        sortie.setCoord(k, m_coords[k]*180/M_PI);

    }

    return sortie;

}


Vecteur Vecteur::concatene(const Vecteur& v) const{

    Vecteur sortie(*this);

    for (size_t i(0) ; i< v.getDim(); ++i ) {

        sortie.augmente(v.getCoord(i));

    }

    return sortie;

}


//==============================================  METHODES PROTECTED  ==================================================



Vecteur Vecteur::mult(double scalaire) const{

    /// Multiplication par un scalaire

    Vecteur sortie({});

    for (size_t k(0); k < m_coords.size(); k++){

        sortie.augmente(scalaire*m_coords[k]);

    }

    return sortie;
}


Vecteur Vecteur::addition(Vecteur const& v2) const{

        /// Addition de v1 et v2 dans v3

    Vecteur sortie;

    double dim1(m_coords.size()), dim2(v2.m_coords.size());

    size_t i(0);

    for (i; i < std::min(dim1, dim2); i++){

            sortie.augmente(m_coords[i] + v2.m_coords[i]);      // Tant qu'il existe des coordonnées communes, on additionne

    }


    for (i; i < std::max(dim1, dim2); i++){                     // Si diff de taille, on ajoute des coordonnées

        if (i >= dim1) {sortie.augmente(v2.m_coords[i]);}

        else {sortie.augmente(m_coords[i]);}
    }

    sortie.rationnalise();               // Fixe les valeurs en dessous de PREC à 0


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

    if (m_coords.size() != 3 || vecteur2.m_coords.size() != 3){ // le produit vectoriel n'est défini que comme opération R^3 --> R^3

        std::string alerte("ERREUR: dimensions incompatibles avec le produit Vectoriel");

        throw alerte;

    } else { // opérations du produit vectoriel

        sortie.setCoord(0, m_coords[1]*vecteur2.m_coords[2] - m_coords[2]*vecteur2.m_coords[1]);
        sortie.setCoord(1, m_coords[2]*vecteur2.m_coords[0] - m_coords[0]*vecteur2.m_coords[2]);
        sortie.setCoord(2, m_coords[0]*vecteur2.m_coords[1] - m_coords[1]*vecteur2.m_coords[0]);

    }

    sortie.rationnalise();

    return sortie;
}


void Vecteur::rationnalise() {

    /// Méthode permettant d'atteindre zéro
    /// dans les opérations entre double

    for (auto& elt : m_coords){

        if ( fabs(elt) <= PREC) {elt = 0;}

    }

}



//=====================================  OPERATEURS SURCHARGES  ============================================


Vecteur& Vecteur::operator+=(Vecteur const& v2){

        /// Surcharge de l'opérateur +=. Addition de v2 à v1, modifie ce dernier

    size_t dim1(m_coords.size()), dim2(v2.m_coords.size());

    size_t i(0);

    for (i; i < std::min(dim1, dim2); i++) {m_coords[i]=m_coords[i] + v2.m_coords[i];}



    for (i; i < std::max(dim1, dim2); i++){

        if (i >= dim1) {m_coords.push_back(v2.m_coords[i]);}


    }

    return *this;

}


Vecteur& Vecteur::operator-=(Vecteur const& v2){

        /// Surchage de l'opérateur -= .

    operator+=(-v2);

    return *this;

}


Vecteur& Vecteur::operator*=(double const& lambda){

        /// Surcharge de l'opérateur *= pour la multiplication par scalaire


    for (size_t k(0); k < m_coords.size(); ++k) {m_coords[k] *= lambda ;}


    return *this;


}


const Vecteur operator-(Vecteur const& v){

        /// Surcharge du négatif. Sort l'opposé

    return -1*v;

}


bool Vecteur::operator==(Vecteur const& v2) const{

    /// Surcharge de l'opérateur de comparaison exacte

    if(m_coords.size() != v2.m_coords.size())  {return false;}       // Comparaison des dimensions

     for (size_t i(0); i < m_coords.size(); i++){

        if (fabs(m_coords[i] - v2.m_coords[i]) > PREC) {return false;}      // Comparaison des coordonnées

     }

     return true;
}


bool Vecteur::operator!=(Vecteur const& v2) const{

    /// Surcharge de l'opérateur d'anti-comparaison

    return !(operator==(v2));
}


const Vecteur operator+(Vecteur v1, Vecteur const& v2){

    /// Surcharge de l'opérateur de l'addition

    v1 += v2;               // On procède par copie : v1 n'est pas modifié après l'appel

    return v1;


}


const Vecteur operator-(Vecteur v1, Vecteur const& v2){

    /// Surcharge de l'opérateur de la soustraction


    v1 -= v2;

    return v1;

}


double Vecteur::operator*(Vecteur const& v2){

    /// Surcharge de l'opérateur du produit scalaire

    return prodScalaire(v2);

}


const Vecteur operator*(double const& lambda, Vecteur v1){

    /// Surcharge de l'opérateur de multiplication par scalaire à gauche


    return (v1*lambda);

}


const Vecteur Vecteur::operator*(double const& lambda){

        /// multplication par scalaire à droite

    return mult(lambda);


}


const Vecteur Vecteur::operator^(Vecteur const& v2){

    /// Surcharge de l'opérateur "^" pour le produit vectoriel

    /* En cas de dimensions incompatibles, on renvoie le vecteur nul
                        (voir bloc catch)                         */

    try{

       return prodVectoriel(v2);
    }

    catch(std::string const& alerte){

        std::cerr << alerte << std::endl;

        return Vecteur({0,0,0});                // Vecteur nul
    }


}


std::ostream& operator<<(std::ostream& sortie, Vecteur const& v){

        /// Surcharge de l'opérateur <<

    sortie << v.to_str();

    return sortie;
}


 const Vecteur Vecteur::operator~(){

        /// Surcharge de l'opérateur unaire permettant de sortir le vecteur unitaire

    return unitaire();

}
