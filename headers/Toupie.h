#pragma once

#ifndef TOUPIE_H
#define TOUPIE_H

#include "Vecteur.h"
#include "Integrable.h"


const Vecteur g({0,0,9.81}) ; // (x,y,z)


class Toupie : public Integrable
{
    public:

        Toupie(Vecteur const&, Vecteur const&, double const&, double const&, double const&, double const&);

        virtual Vecteur equEvol(double const& temps) const override;


    protected:

    double m_IA1;
    double m_I3;
    double m_masse;
    double m_d;

    virtual double calculeIA1() const;

    virtual double calculeI3() const;

};



#endif // TOUPIE_H
