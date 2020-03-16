#pragma once

#ifndef TOUPIE_H
#define TOUPIE_H

#include "Vecteur.h"

class Toupie : public Integrable
{
    public:

        Toupie();
        virtual ~Toupie();

        virtual Vecteur equEvol(double const& temps) const;


        Vecteur getParam() const;
        void setParam(Vecteur const& newV);



        Vecteur getVitesse() const;
        void setVitesse(Vecteur const& newV);


    protected:

        Vecteur m_P;                // P est le vecteur paramètres
        Vecteur m_Ppoint;           // Ppoint est le vecteur dérivée temporelle de P


};

#endif // TOUPIE_H
