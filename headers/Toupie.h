#pragma once

#ifndef TOUPIE_H
#define TOUPIE_H

#include "Vecteur.h"
#include "Integrable.h"


class Toupie : public Integrable
{
    public:

        Toupie(Vecteur const&, Vecteur const&);

        virtual Vecteur equEvol(double const& temps) const = 0;

        virtual void calculeI(double const&, double const&, double const&) =0 ;


    protected:


};


class ConeSimple : public Toupie
{
    public :

        ConeSimple(Vecteur const& param, Vecteur const& vit, double const& rayon, double const& hauteur, double const& masse);

    protected :

        double m_I1;
        double m_I3;


};




// =====================  classes de test  ===========================


class OH : public Integrable
{
    public :

        OH(Vecteur const&, Vecteur const&);

        virtual Vecteur equEvol(double const& temps) const;

};


class Bille : public Integrable
{
    public :

        Bille(Vecteur const&, Vecteur const&);

        virtual Vecteur equEvol(double const& temps) const;

    protected :


};


#endif // TOUPIE_H
