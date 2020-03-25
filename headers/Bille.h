#pragma once

#ifndef TOUPIES_DL_BILLE_H
#define TOUPIES_DL_BILLE_H

#include "Integrable.h"


class Bille : public Integrable
{
public :

    Bille(Vecteur const&, Vecteur const&);

    virtual Vecteur equEvol(double const& temps) const;

protected :


};

#endif //TOUPIES_DL_BILLE_H
