#include "Matrice3.h"
#include <iostream>
#include <cmath>
#include <vector>



Matrice3::Matrice3(): m_c1({1, 0, 0}), m_c2({0, 1, 0}, m_c3({0, 0, 1}))

        /// Le constructeur par défaut renvoie la matrice identité
{
}

Matrice3::Matrice3( double l1c1, double l1c2, double l1c3,
                    double l2c1, double l2c2, double l2c3,
                    double l3c1, double l3c2, double l3c3) : m_c1({l1c1, l2c1, l3c1}), m_c2({l1c2, l2c2, l3c2}), m_c3(l1c3, l2c3, l3c3)

        /// Constructeur sur demande
{

}


Matrice3::~Matrice3()
{
    //dtor
}











Matrice3& Matrice3::operator+=(Matrice3 const& autre){

    /// Surcharge de l'addition interne

    m_coords[0] += autre.m_coords[0];
    m_coords[1] += autre.m_coords[1];
    m_coords[2] += autre.m_coords[2];

    return *this;
}


Matrice3& Matrice3::operator-=(Matrice3 const& autre){

    operator+=((-1)*autre);

    return *this;
}





Matrice3& Matrice3::operator*=(double const& lambda){

    /// Multiplication par sclaire à droite

    m_coods[0] *= lambda;
    m_coords[1] *= lambda;
    m_coords[2] *= lambda;

    return *this;
}






const Matrice3 operator*(double const& lambda, Matrice3 mat1){

    /// Multiplication par scalaire à gauche

    mat1 *= lambda      // On procède par copie : mat1 n'est pas modifiée hors de la fonction
    return mat1;
}



Matrice3 Matrice3::transp() const {

        /// Méthode qui transpose la matrice

    Matrice3 sortie ( m_coords[0].getCoord(0), m_coords[1].getCoords(0), m_coords[2].getCoord(0),
                      m_coords[0].getCoord(1), m_coords[1].getCoords(1), m_coords[2].getCoord(1),
                      m_coords[0].getCoord(2), m_coords[1].getCoords(2), m_coords[2].getCoord(2) );


    return sortie;


}



double Matrice3::det() const {

        /// renvoie le déterminant de la matrice

    double sortie(0.0);

    for (int k(0); k < 3 ; ++k) { sortie += m_coords[0].getCoord((0+k)%3)*m_coords[1].getCoord((1+k)%3)*m_coords[2].getCoord((2+k)%3); }

    for (int k(0); k < 3 ; ++k) { sortie -= m_coords[0].getCoord((1+k)%3)*m_coords[1].getCoord((0+k)%3)*m_coords[2].getCoord((2+k)%3); }


    return sortie;

}



Matrice3 Matrice3::inv() const {

        /// Calcule l'inverse d'une matrice

    double deter(det());


    if (abs(deter) < PREC and deter >= 0) { deter = PREC; }

    else if (abs(deter) < PREC and deter < 0) { deter = -PREC; }




    Matrice3 Cofacteurs;

    int t(0);

    int k(0);

    while ( k < 3 ) {

        int MAX_k (std::max((k-1)%3, (k+1)%3));
        int MIN_k (std::min((k-1)%3, (k+1)%3));

        int MAX_t (std::max((t-1)%3, (t+1)%3));
        int MIN_t (std::min((t-1)%3, (t+1)%3));




        Cofacteurs[k].setCoord(t, pow(-1, k+t) * ( M[MAX_k].getCoord(MAX_t)*M[MIN_k].getCoord(MIN_t)
                                       - M[MAX_k].getCoord(MIN_t)*M[MIN_k].getCoord(MAX_t) )        );
            // Dans la ligne ci-dessus, nous pouvons ne pas écrire k+1 et t+1 car alors ce serait k+t+2 , ce qui ne
            // modifie pas la parité. De plus, empiriquement, en inversant une matrice par la méthode des cofacteurs,
            // la structure utilisée tient. Elle casserait pour des matrices 4x4



        if ( k == 2 and t < 2 ) {

            k = 0;

            ++t;

        }

    }


    return 1/deter*Cofacteurs;


}








