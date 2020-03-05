#ifndef MATRICE3_H
#define MATRICE3_H

#include "Vecteur.h"


class Matrice3
{
    public:

        Matrice3();
        virtual ~Matrice3();

    protected:

        Vecteur m_c1;
        Vecteur m_c2;
        Vecteur m_c3;

};

#endif // MATRICE3_H
