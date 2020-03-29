#pragma once

#ifndef TOUPIES_DL_BILLE_H
#define TOUPIES_DL_BILLE_H

#include "Integrable.h"
#include "../constantes.h"


class Bille : public Integrable
{
public :

    Bille(double, double, double, double);
    virtual Bille* clone() const;

    virtual Vecteur equEvol(double const& temps) const;

};

#endif //TOUPIES_DL_BILLE_H
