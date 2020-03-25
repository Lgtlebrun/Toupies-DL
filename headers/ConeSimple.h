#pragma once


#ifndef TOUPIES_DL_CONESIMPLE_H
#define TOUPIES_DL_CONESIMPLE_H


#include "Toupie.h"


class ConeSimple : public Toupie
{
public :

    ConeSimple(Vecteur const& param, Vecteur const& vit, double const& rayon, double const& hauteur, double const& masse);

protected :

    double m_I1;
    double m_I3;


};



#endif //TOUPIES_DL_CONESIMPLE_H
