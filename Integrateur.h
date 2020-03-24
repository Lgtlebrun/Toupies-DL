#pragma once

#ifndef INTEGRATEUR_H
#define INTEGRATEUR_H

#include "Toupie.h"



class Integrateur{

    public :

        virtual void integre(Integrable& integrable, double const& dt) const =0;


    protected :

        double m_t;

};


class IntegrateurEulerCromer: public Integrateur
{

    public :

        virtual void integre(Integrable& integrable, double const& dt) const;


};


class IntegrateurNewmark: public Integrateur
{

    public :

        virtual void integre(Integrable& integrable, double const& dt, double const& epsilon) const;


};



class IntegrateurRK4: public Integrateur
{

    public :

        virtual void integre(Integrable& integrable, double const& dt) const;


};



#endif // INTEGRATEUR_H
