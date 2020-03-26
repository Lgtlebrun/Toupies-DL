#pragma once

#ifndef TOUPIE_H
#define TOUPIE_H

#include "Vecteur.h"
#include "Integrable.h"


class Toupie : public Integrable
{
    public:

        Toupie(Vecteur const&, Vecteur const&);

        virtual Vecteur equEvol(double const& temps) const = 0;

        virtual void calculeI(double const&, double const&, double const&) =0 ;


    protected:


};



#endif // TOUPIE_H
