#pragma once

#ifndef DEF_VECTEUR
#define DEF_VECTEUR


#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>


// VARIABLE GLOBALE

double const PREC(1e-14);



class Vecteur{


    public:

        Vecteur();                                                          // Constructeur par défaut

        Vecteur(std::initializer_list<double> il);                          // Constructeur à base d'une liste


        double getCoord(unsigned int nEmeCoord) const;                      // Accesseur à la nème coordonnée


        unsigned int getDim() const;                                        // Accesseur à la dimension du vecteur


        void setCoord(unsigned int nEmeCoord, double nouvelleValeur);       // Set pour une seule coordonnée


        void augmente(double coordSupplementaire);                          // Ajoute une coordonnée au vecteur


        double norme2() const;                                              // Calcule la norme au carré d'un vecteur


        double norme() const;                                               // Calcule la norme d'un vecteur


        Vecteur unitaire() const;                                           // Retourne le vecteur unitaire (même dimension, même sens)


        void rationnalise();                                                // Méthode arrondissant les petites coordonnées à 0


    // ======================================= OPERATEURS INTERNES ===========================================


        bool operator==(Vecteur const& v2) const;                         // Comparaison


        bool operator!=(Vecteur const& v2) const;                         // Anti-comparaison


        double operator*(Vecteur const& v2);                        // Produit scalaire


        const Vecteur operator*(double const& lambda);              // Multiplication par scalaire à droite


        Vecteur& operator+=(Vecteur const& v2);                     // Addition à lui même d'un vecteur v2


        Vecteur& operator-=(Vecteur const& v2);                     // Soustraction à lui-même d'un vecteur v2


        Vecteur& operator*=(double const& lambda);                  // Multiplication à lui même d'un facteur lambda


        const Vecteur operator^(Vecteur const& v2);                 // Produit vectoriel


    //=============================================================================================


    private:

    /* Attributs */

        std::vector <double> m_coords;                 // Stockage des coordonnées en tableau dynamique




    /* Méthodes nécessaires en interne */


        Vecteur mult(double scalaire) const;                                // Multiplie un vecteur par un scalaire (un réel)

        Vecteur addition(Vecteur const& vecteur2) const;                    // Addition de deux vecteurs /!\ OBSOLÈTE /!\

        Vecteur prodVectoriel(Vecteur const& vecteur2) const;               // Produit vectoriel classique somme toutes

        double prodScalaire(Vecteur const &vecteur2) const;                 // Produit scalaire entre deux vecteurs


};


//=====================================  OPERATEURS EXTERNES  ============================================


        const Vecteur operator+(Vecteur v1, Vecteur const& v2);                     // Addition


        const Vecteur operator-(Vecteur v1, Vecteur const& v2);                     // Soustraction


        const Vecteur operator*(double const& lambda, Vecteur v1);           // Multiplication par scalaire à gauche


        std::ostream& operator<<(std::ostream& sortie, Vecteur const& v);           // Affichage du vecteur


        const Vecteur operator-(Vecteur const& v);                                  // Opposé


//==========================================================================================================

#endif // DEF_VECTEUR
