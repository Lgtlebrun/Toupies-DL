#pragma once

#ifndef MATRICE3_H
#define MATRICE3_H

#include "Vecteur.h"


class Matrice3
{
    public:

        Matrice3();

        Matrice3(double l1c1, double l1c2, double l1c3,
                 double l2c1, double l2c2, double l2c3,
                 double l3c1, double l3c2, double l3c3);





        virtual ~Matrice3();



    protected:

        Vecteur m_c1;       // La matrice est ordonnées en Vecteurs-colonnes
        Vecteur m_c2;
        Vecteur m_c3;

};

#endif // MATRICE3_H
