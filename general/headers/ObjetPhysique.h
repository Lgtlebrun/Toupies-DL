#ifndef TOUPIES_DL_OBJETPHYSIQUE_H
#define TOUPIES_DL_OBJETPHYSIQUE_H

#include "Integrable.h"

class ObjetPhysique : public Integrable {

public :

    ObjetPhysique(SupportADessin& sup, std::string const& nom, Vecteur const& param, Vecteur const& Paramp);

    virtual ~ObjetPhysique();

    virtual ObjetPhysique* clone() const = 0;

    virtual Vecteur equEvol(double const& temps) = 0;

    virtual double Energie() const = 0;

    virtual double L_k() const = 0;

    virtual double L_a() const = 0;

    virtual double ProdMixte() const = 0;


};



#endif //TOUPIES_DL_OBJETPHYSIQUE_H
