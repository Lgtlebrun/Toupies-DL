#pragma once

#ifndef MATRICE3_H
#define MATRICE3_H

#include "Vecteur.h"





class Matrice3
{
    public:

        Matrice3();                                             // Cstor par défault (retourne I3)

        Matrice3(double l1c1, double l1c2, double l1c3,         // Constructeur custom
                 double l2c1, double l2c2, double l2c3,
                 double l3c1, double l3c2, double l3c3);




        void setCoord(size_t ligne, size_t colonne, double valeur);


        Matrice3& operator+=(Matrice3 const& autre);            // Addition matricielle

        Matrice3& operator-=(Matrice3 const& autre);            // Soustraction matricielle

        Matrice3& operator*=(double const& lambda);             // Multiplication par scalaire à droite


        bool operator==(Matrice3 const& autre) const;           // Comparaison

        bool operator!=(Matrice3 const& autre) const;           // Anti-comparaison





        virtual ~Matrice3();



        Vecteur getLigne(size_t indice) const;




        Matrice3 transp() const;                                // Transposée d'une matrice

        Matrice3 inv() const;                                   // Inverse d'une matrice

        double det() const;                                     // Déterminant d'une matrice



    protected:

        std::vector<Vecteur> m_coords;                            // La matrice est ordonnées en Vecteurs-lignes

};


//=====================================  OPERATEURS EXTERNES  ============================================




const Matrice3 operator*(double const& lambda, Matrice3 mat1);      // Multiplication par scalaire à gauche

const Matrice3 operator*(Matrice3 const& m1, Matrice3 const& m2);

const std::ostream& operator<<(std::ostream& flux, Matrice3 const& m1);





#endif // MATRICE3_H
