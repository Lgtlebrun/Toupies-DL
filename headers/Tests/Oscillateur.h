#pragma once

#ifndef TOUPIES_DL_OSCILLATEUR_H
#define TOUPIES_DL_OSCILLATEUR_H

#include "Integrable.h"


class Oscillateur : public Integrable
{
public :

    Oscillateur(Vecteur const&, Vecteur const&);

    virtual Oscillateur* clone() const;
    virtual void dessine() override;

    virtual Vecteur equEvol(double const& temps) const;

    virtual std::string getType() const;

protected:

};


#endif //TOUPIES_DL_OSCILLATEUR_H
