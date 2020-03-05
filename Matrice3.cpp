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
