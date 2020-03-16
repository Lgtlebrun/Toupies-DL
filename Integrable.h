#pragma once

#ifndef INTEGRABLE_H
#define INTEGRABLE_H

#include "Vecteur.h"

class Integrable
{
    public:

        Integrable();

        virtual ~Integrable();


        virtual Vecteur equEvol(double const& temps) const = 0;

    protected:

};

#endif // INTEGRABLE_H
