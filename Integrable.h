#pragma once

#ifndef INTEGRABLE_H
#define INTEGRABLE_H

#include "Vecteur.h"

class Integrable
{
    public:

        Integrable();

        virtual ~Integrable();


        virtual Vecteur equEvol(double const& temps) const = 0;


        Vecteur getParam() const;
        void setParam(Vecteur const& newV);



        Vecteur getVitesse() const;
        void setVitesse(Vecteur const& newV);


    protected:


        Vecteur m_P;                // P est le vecteur paramètres
        Vecteur m_Ppoint;           // Ppoint est le vecteur dérivée temporelle de P

};

#endif // INTEGRABLE_H
