#pragma once


#ifndef TOUPIES_DL_CONESIMPLE_H
#define TOUPIES_DL_CONESIMPLE_H


#include "Toupie.h"


class ConeSimple : public Toupie

{
public :

    ConeSimple(Vecteur const&, Vecteur const&, double const&, double const&, double const&);

    virtual ConeSimple* clone() const;

    virtual void statsToupie(std::ostream& sortie) const;



protected :

    virtual double calculeIA1(double const&, double const&, double const&) const;
    virtual double calculeI3(double const&, double const&, double const&) const;

    double masse(double const&, double const&, double const&) const;

    double m_rayon;
    double m_hauteur;


};



#endif //TOUPIES_DL_CONESIMPLE_H
