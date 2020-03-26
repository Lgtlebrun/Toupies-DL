#pragma once


#ifndef TOUPIES_DL_CONESIMPLE_H
#define TOUPIES_DL_CONESIMPLE_H


#include "Toupie.h"


class ConeSimple : public Toupie
{
public :

    ConeSimple(Vecteur const&, Vecteur const&, double const&, double const&, double const&);

protected :

    virtual double calculeIA1(double const&, double const&, double const&) const;

    virtual double calculeI3(double const&, double const&) const;


};



#endif //TOUPIES_DL_CONESIMPLE_H
