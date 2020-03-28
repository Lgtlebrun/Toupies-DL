#pragma once

#ifndef INTEGRATEUR_H
#define INTEGRATEUR_H

#include "Toupie.h"
#include "constantes.h"




class Integrateur{

    public :

        Integrateur(double const& t0)
            : m_t(t0)
        {}

        virtual void integre(Integrable& integrable, double const& dt) const =0;

        virtual void augmente_t(double const& dt);

        virtual double getTemps() const ;


    protected :

        double m_t;

};


class IntegrateurEulerCromer: public Integrateur
{

    public :

        IntegrateurEulerCromer(double const& t0);

        void integre(Integrable& integrable, double const& dt) const;


};


class IntegrateurNewmark: public Integrateur
{

    public :

        IntegrateurNewmark (double const& t0);

        virtual void integre(Integrable& integrable, double const& dt) const;


};



class IntegrateurRK4: public Integrateur
{

    public :

        virtual void integre(Integrable& integrable, double const& dt) const;


};



#endif // INTEGRATEUR_H
