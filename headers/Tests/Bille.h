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
    virtual void dessine() override;

    virtual Vecteur equEvol(double const& temps) const;

    virtual std::string getType() const;

protected :

};

#endif //TOUPIES_DL_BILLE_H
