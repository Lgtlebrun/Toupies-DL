#include "Vecteur.h"
#include <vector>
#include <iostream>
#include <cmath>




double const PREC(1e-10);

Vecteur::Vecteur(){}

Vecteur::Vecteur(std::initializer_list<double> il) : m_coords(il) {}         /// Constructeur à base d'une liste de double


void Vecteur::augmente(double coordSupplementaire){

    /// Ajoute une dimension au Vecteur en augmentant le vector d'une case

    m_coords.push_back(coordSupplementaire);

}



void Vecteur::setCoord(unsigned int nEmeCoord, double nouvelleValeur){

    /// Permet de modifier la valeur d'une coordonnée


    m_coords[nEmeCoord] = nouvelleValeur;

}


double Vecteur::getCoord(unsigned int nEmeCoord) const{

    /// Envoie la valeur d'une coordonnée

    return m_coords[nEmeCoord];


}



Vecteur Vecteur::mult(double scalaire) const{

    /// Multiplication par un scalaire

    Vecteur sortie;

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

            sortie.augmente(m_coords[i] + v2.m_coords[i]);

    }


    for (i; i < std::max(dim1, dim2); i++){

        if (i >= dim1) {sortie.augmente(v2.m_coords[i]);}

        else {sortie.augmente(m_coords[i]);}
    }

    sortie.rationnalise();                          // Fixe les valeurs en dessous de PREC à 0


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

        std::string alerte("ERREUR: dimensions incompatibles avec le produit scalaire");

        throw alerte;

    } else { // opérations du produit vectoriel

        sortie.augmente(m_coords[2]*vecteur2.m_coords[3] - m_coords[3]*vecteur2.m_coords[2]);
        sortie.augmente(m_coords[3]*vecteur2.m_coords[1] - m_coords[1]*vecteur2.m_coords[3]);
        sortie.augmente(m_coords[1]*vecteur2.m_coords[2] - m_coords[2]*vecteur2.m_coords[1]);

        sortie.rationnalise();
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

        std::string alerte("ERREUR: Le vecteur nul n'a pas de direction");
        throw alerte;

    }


    Vecteur sortie;

    for (size_t k(0); k < m_coords.size(); ++k) {sortie.augmente(m_coords[k] / longueur);}

    return sortie;
}



unsigned int Vecteur::getDim() const{return m_coords.size();}       /// Accesseur à la dimension du vecteur



void Vecteur::rationnalise() {

    /// Méthode permettant d'atteindre zéro
    /// dans les opérations entre double

    for (auto& elt : m_coords){

        if (elt <= PREC) {elt = 0;}

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


Vecteur& Vecteur::operator-=(Vecteur const& v2){            // je sais qu'en tous cas comme ça, malgré la ressemblance
                                                            // à +=, ça marche...

        /// Surchage de l'opérateur -= .On soustrait v2 de v1 en modifiant v1

    double dim1(m_coords.size()), dim2(v2.m_coords.size());

    size_t i(0);

    for (i; i < std::min(dim1, dim2); i++){m_coords[i] -= v2.m_coords[i];}


    for (i; i < std::max(dim1, dim2); i++){

        if (i >= dim1) {m_coords.push_back((-1)*v2.m_coords[i]);}

    }


    return *this;

}


Vecteur& Vecteur::operator*=(double const& lambda){

        /// Surcharge de l'opérateur *= pour la multiplication par scalaire


    for (size_t k(0); k<m_coords.size(); ++k) { this->m_coords[k]*=lambda ;}


    return *this;


}



const Vecteur operator-(Vecteur const& v){

        /// Surcharge du négatif. Sort l'opposé

    return -1*v;

}


bool Vecteur::operator==(Vecteur const& v2){

    /// Surcharge de l'opérateur de comparaison exacte

    if(m_coords.size() != v2.m_coords.size())  {return false;}       // Comparaison des dimensions

     for (size_t i(0); i < m_coords.size(); i++){

        if (m_coords[i] - v2.m_coords[i] > PREC) {return false;}      // Comparaison des coordonnées

     }

     return true;
}


bool Vecteur::operator!=(Vecteur const& v2){

    /// Surcharge de l'opérateur d'anti-comparaison

    return !(operator==(v2));
}



const Vecteur operator+(Vecteur const& v1, Vecteur const& v2){

    /// Surcharge de l'opérateur de l'addition

    Vecteur sortie(v1);

    sortie += v2;

    return sortie;


}



const Vecteur operator-(Vecteur const& v1, Vecteur const& v2){

    /// Surcharge de l'opérateur de la soustraction


    Vecteur sortie(v1);

    sortie -= v2;

    return sortie;

}



double Vecteur::operator*(Vecteur const& v2){

    /// Surcharge de l'opérateur du produit scalaire

    return prodScalaire(v2);

}


const Vecteur operator*(double const& lambda, Vecteur v1){

    /// Surcharge de l'opérateur de multiplication par scalaire à gauche


    return v1*lambda;

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

    catch(std::string const& message){

        std::cerr << message << std::endl;

        return Vecteur({0,0,0});                // Vecteur nul
    }


}


std::ostream& operator<<(std::ostream& sortie, Vecteur const& v){

        /// Surcharge de l'opérateur <<

    unsigned int taille(v.getDim());

    sortie << "[";

    if(taille != 0) {

        sortie << v.getCoord(0);

        for (size_t i(1); i < taille; i++){

            sortie << ", " << v.getCoord(i);

        }

    }

    sortie << "]";

}



//==============================================  TESTS  ==============================================





// Test de la classe (flemme de faire le makefile de testVecteur.cpp)

int main(){

    Vecteur v1, resultat;
    Vecteur v2({2,4,5}), v3({8,2,3});
    Vecteur v4({2,1});


    resultat = v2 ^ v3;

    std::cout << resultat << std::endl;

    resultat = v4 ^ v2;

    std::cout << resultat << std::endl;

    if (v2 == v3) {std::cout << "top" << std::endl;}
    else {std::cout << "pas top" << std::endl;}

    std::cout << v4 << std::endl;

    v4 = 3*v4;
    std::cout<< v4 << std::endl;

    std::cout << "Test scalaire à droite : ";
    v4 = v4*3;
    std::cout << v4 << std::endl;

    std::cout << v2.unitaire() << std::endl;

    v3*=2.0;

    std::cout << v3 << std::endl;

    std::cout << -v4 << std::endl;

    std::cout << "addition de: ";

    std::cout << v4 << " " << v2 << std::endl;

    std::cout << (v4+v2) << std::endl;

    std::cout << "soustraction: ";
    std::cout << (v4-v2) <<std::endl;

return 0;
}

