#include "Matrice3.h"
#include <iostream>
#include <cmath>
#include <vector>
#include "Vecteur.cpp"




Matrice3::Matrice3(): m_coords({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}})

        /// Le constructeur par défaut renvoie la matrice identité
{
}

Matrice3::Matrice3( double l1c1, double l1c2, double l1c3,
                    double l2c1, double l2c2, double l2c3,
                    double l3c1, double l3c2, double l3c3) : m_coords({{l1c1, l1c2, l1c3}, {l2c1, l2c2, l2c3}, {l3c1, l3c2, l3c3}})

        /// Constructeur sur demande
{

}


Matrice3::~Matrice3()
{
    //dtor
}











Matrice3& Matrice3::operator+=(Matrice3 const& autre){

    /// Surcharge de l'addition interne


    for (size_t i(0); i < 3; i++){

        m_coords[i] += autre.m_coords[i];                   // Note : besoin d'un .rationnalise()? Pour l'instant il semble que non
    }

    return *this;
}





Matrice3& Matrice3::operator-=(Matrice3 const& autre){

    operator+=((-1)*autre);

    return *this;
}





Matrice3& Matrice3::operator*=(double const& lambda){

    /// Multiplication par sclaire à droite

    for (size_t i(0); i < 3; i++){

        m_coords[i] *= lambda;                   // Note : besoin d'un .rationnalise()?
    }

    return *this;
}



bool Matrice3::operator==(Matrice3 const& autre) const{

    /// Opérateur de comparaison


    for (size_t i(0); i < m_coords.size(); i++){

        if (m_coords[i] != autre.m_coords[i])  {return false;}

    }

    return true;
}





bool Matrice3::operator!=(Matrice3 const& autre) const{

    /// Opérateur de comparaison


    return !(operator==(autre));
}






Vecteur Matrice3::getLigne(size_t indice) const{

    if (m_coords.size() <= indice) {return Vecteur();}

    return m_coords[indice];

}








Matrice3 Matrice3::transp() const {

        /// Méthode qui transpose la matrice

    Matrice3 sortie ( m_coords[0].getCoord(0), m_coords[1].getCoord(0), m_coords[2].getCoord(0),
                      m_coords[0].getCoord(1), m_coords[1].getCoord(1), m_coords[2].getCoord(1),
                      m_coords[0].getCoord(2), m_coords[1].getCoord(2), m_coords[2].getCoord(2) );


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

        /// Retourne l'inverse d'une matrice

    double deter(det());


    if (abs(deter) < PREC && deter >= 0) { deter = PREC; }

    else if (abs(deter) < PREC && deter < 0) { deter = -PREC; }




    Matrice3 cofacteurs;

    int t(0);

    for(size_t k(0); k < 3; k++) {

        int MAX_k (std::max((k-1)%3, (k+1)%3));
        int MIN_k (std::min((k-1)%3, (k+1)%3));

        int MAX_t (std::max((t-1)%3, (t+1)%3));
        int MIN_t (std::min((t-1)%3, (t+1)%3));




        cofacteurs.m_coords[k].setCoord(t, pow(-1, k+t) * ( m_coords[MAX_k].getCoord(MAX_t) * m_coords[MIN_k].getCoord(MIN_t)
                                       - m_coords[MAX_k].getCoord(MIN_t) * m_coords[MIN_k].getCoord(MAX_t) )        );

            // Dans la ligne ci-dessus, nous pouvons ne pas écrire k+1 et t+1 car alors ce serait k+t+2 , ce qui ne
            // modifie pas la parité. De plus, empiriquement, en inversant une matrice par la méthode des cofacteurs,
            // la structure utilisée tient. Elle casserait pour des matrices 4x4



        if ( k == 2 and t < 2 ) {

            k = 0;

            ++t;

        }

    }


    return (1.0/deter) * cofacteurs;


}








const Matrice3 operator*(double const& lambda, Matrice3 mat1){

    /// Multiplication par scalaire à gauche

    mat1 *= lambda;      // On procède par copie : mat1 n'est pas modifiée hors de la fonction
    return mat1;
}


