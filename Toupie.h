#pragma once

#ifndef TOUPIE_H
#define TOUPIE_H

#include "Vecteur.h"

class Toupie
{
    public:

        Toupie();
        virtual ~Toupie();

        virtual Vecteur equEvol() const;


    protected:

        Vecteur m_P;                // P est le vecteur paramètres
        Vecteur m_Ppoint;           // Ppoint est le vecteur dérivée temporelle de P


};

#endif // TOUPIE_H
