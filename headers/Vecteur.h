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

        Vecteur();                                                          // Constructeur par d�faut

        Vecteur(std::initializer_list<double> il);                          // Constructeur � base d'une liste


        double getCoord(unsigned int nEmeCoord) const;                      // Accesseur � la n�me coordonn�e


        unsigned int getDim() const;                                        // Accesseur � la dimension du vecteur


        void setCoord(unsigned int nEmeCoord, double nouvelleValeur);       // Set pour une seule coordonn�e


        void augmente(double coordSupplementaire);                          // Ajoute une coordonn�e au vecteur


        double norme2() const;                                              // Calcule la norme au carr� d'un vecteur


        double norme() const;                                               // Calcule la norme d'un vecteur


        void rationnalise();                                                // M�thode arrondissant les petites coordonn�es � 0


    // ======================================= OPERATEURS INTERNES ===========================================


        bool operator==(Vecteur const& v2) const;                         // Comparaison


        bool operator!=(Vecteur const& v2) const;                         // Anti-comparaison


        double operator*(Vecteur const& v2);                        // Produit scalaire


        const Vecteur operator*(double const& lambda);              // Multiplication par scalaire � droite


        Vecteur& operator+=(Vecteur const& v2);                     // Addition � lui m�me d'un vecteur v2


        Vecteur& operator-=(Vecteur const& v2);                     // Soustraction � lui-m�me d'un vecteur v2


        Vecteur& operator*=(double const& lambda);                  // Multiplication � lui m�me d'un facteur lambda


        const Vecteur operator^(Vecteur const& v2);                 // Produit vectoriel


        const Vecteur operator~();                                  // Vecteur unitaire


    //=============================================================================================


    private:

    /* Attributs */

        std::vector <double> m_coords;                 // Stockage des coordonn�es en tableau dynamique




    /* M�thodes n�cessaires en interne */


        Vecteur mult(double scalaire) const;                                // Multiplie un vecteur par un scalaire (un r�el)

        Vecteur addition(Vecteur const& vecteur2) const;                    // Addition de deux vecteurs /!\ OBSOL�TE /!\

        Vecteur prodVectoriel(Vecteur const& vecteur2) const;               // Produit vectoriel classique somme toutes

        double prodScalaire(Vecteur const &vecteur2) const;                 // Produit scalaire entre deux vecteurs

        Vecteur unitaire() const;                                           // Retourne le vecteur unitaire (m�me dimension, m�me sens)


};


//=====================================  OPERATEURS EXTERNES  ============================================


        const Vecteur operator+(Vecteur v1, Vecteur const& v2);                     // Addition


        const Vecteur operator-(Vecteur v1, Vecteur const& v2);                     // Soustraction


        const Vecteur operator*(double const& lambda, Vecteur v1);           // Multiplication par scalaire � gauche


        std::ostream& operator<<(std::ostream& sortie, Vecteur const& v);           // Affichage du vecteur


        const Vecteur operator-(Vecteur const& v);                                  // Oppos�


//==========================================================================================================

#endif // DEF_VECTEUR
