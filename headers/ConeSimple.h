#pragma once


#ifndef TOUPIES_DL_CONESIMPLE_H
#define TOUPIES_DL_CONESIMPLE_H


#include "Toupie.h"


class ConeSimple : public Toupie

{
public :

    ConeSimple(SupportADessin&, Vecteur const&, Vecteur const&, double const&, double const&, double const&);
    virtual ~ConeSimple();

    virtual ConeSimple* clone() const;
    virtual void dessine() override;

    double getRayon() const;
    double getHauteur() const;

    virtual void statsCorps(std::ostream& sortie) const;



protected :

    virtual double calculeIA1(double const&, double const&, double const&) const;
    virtual double calculeI3(double const&, double const&, double const&) const;

    double masse(double const&, double const&, double const&) const;

    double m_rayon;
    double m_hauteur;


};


std::ostream& operator<<(std::ostream&, ConeSimple const&);



#endif //TOUPIES_DL_CONESIMPLE_H
