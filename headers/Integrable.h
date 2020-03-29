#pragma once

#ifndef INTEGRABLE_H
#define INTEGRABLE_H

#include "Vecteur.h"
#include <iostream>

class Integrable
{
    public:

        Integrable(std::string const&, Vecteur const&, Vecteur const&);

        virtual ~Integrable();


        virtual Vecteur equEvol(double const& temps) const = 0;
        virtual Integrable* clone() const = 0;


        virtual std::string getType() const;
        virtual void statsCorps(std::ostream&) const;


        Vecteur getParam() const;
        void setParam(Vecteur const& newV);


        Vecteur getVitesse() const;
        void setVitesse(Vecteur const& newV);


    protected:


        Vecteur m_P;                // P est le vecteur paramètres
        Vecteur m_Ppoint;           // Ppoint est le vecteur dérivée temporelle de P


        std::string m_type = "Corps Solide";

};

#endif // INTEGRABLE_H
