#pragma once

#ifndef TOUPIE_H
#define TOUPIE_H

#include "Vecteur.h"
#include "Integrable.h"
#include "string"
#include "constantes.h"




class Toupie : public Integrable
{
    public:

        Toupie(std::string const&, Vecteur const&, Vecteur const&, double const&, double const&, double const&, double const&, double const&);

        virtual Vecteur equEvol(double const& temps) const override;

        virtual void statsCorps(std::ostream& sortie) const;

        virtual Toupie* clone() const = 0;


    protected:

    double m_IA1;
    double m_I3;
    double m_masse;
    double m_masseVolumique;
    double m_d;

    std::string m_type = "Toupie";

};



#endif // TOUPIE_H
