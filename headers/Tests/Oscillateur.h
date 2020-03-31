#pragma once

#ifndef TOUPIES_DL_OSCILLATEUR_H
#define TOUPIES_DL_OSCILLATEUR_H

#include "Integrable.h"


class Oscillateur : public Integrable
{
public :

    Oscillateur(Vecteur const&, Vecteur const&);

    virtual Oscillateur* clone() const;
    virtual Vecteur equEvol(double const& temps) const;

    virtual std::string getType() const;

protected:

    std::string m_type = "Oscillateur";

};


#endif //TOUPIES_DL_OSCILLATEUR_H
