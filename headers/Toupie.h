#pragma once

#ifndef TOUPIE_H
#define TOUPIE_H

#include "Vecteur.h"
#include "Integrable.h"


class Toupie : public Integrable
{
    public:

        Toupie();
        virtual ~Toupie();

        virtual Vecteur equEvol(double const& temps) const;



    protected:



};

#endif // TOUPIE_H
