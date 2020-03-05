#include "Matrice3.h"

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

    m_c1 += autre.m_c1;
    m_c2 += autre.m_c2;
    m_c3 += autre.m_c3;

    return *this;
}


Matrice3& Matrice3::operator-=(Matrice3 const& autre){

    operator+=((-1)*autre);

    return *this;
}





Matrice3& Matrice3::operator*=(double const& lambda){

    /// Multiplication par sclaire à droite

    m_c1 *= lambda;
    m_c2 *= lambda;
    m_c3 *= lambda;

    return *this;
}






const Matrice3 operator*(double const& lambda, Matrice3 mat1){

    /// Multiplication par scalaire à gauche

    mat1 *= lambda      // On procède par copie : mat1 n'est pas modifiée hors de la fonction
    return mat1;
}
