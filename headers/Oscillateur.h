#pragma once

#ifndef TOUPIES_DL_OSCILLATEUR_H
#define TOUPIES_DL_OSCILLATEUR_H

#include "Integrable.h"


class Oscillateur : public Integrable
{
public :

    Oscillateur(Vecteur const&, Vecteur const&);

    virtual Vecteur equEvol(double const& temps) const;

};


#endif //TOUPIES_DL_OSCILLATEUR_H
