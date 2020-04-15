#pragma once

#ifndef INTEGRATEUR_H
#define INTEGRATEUR_H

#include "Clonable.h"
#include "constantes.h"
#include "Integrable.h"

class Integrable;


class Integrateur : public Clonable{
public :

// =========

    Integrateur(double const& t0)                                   // ctor de l'intégrateur, caractérisé seulement
        : m_t(t0)                                                   // par le temps. En fait, il est approximateur
    {}                                                              // de l'équation différentielle E(t,x(t),x'(t))
                                                                    // = x''(t). Donc on le pose à t=t0 et il nous
                                                                    // dit comment faire évoluer les paramètres

    virtual ~Integrateur() {}                                       // dtor d'intégrateur

// =========  VIRTUELLES PURES :

    virtual Integrateur* clone() const = 0;                         // Renvoie un pointeur sur une copie
    // polymorphique de l'intégrateur

    virtual void integre(Integrable& integrable, double const& dt) const =0;
    // Renvoit le vecteur dérivée seconde en le
    // calculant depuis l'équation d'évolution
    // associée à l'intégrable. Approximation avec
    // pas de temps dt. Virtuel pur car un intégrateur
    // ne fait pas sens en lui-même car il est
    // caractérisé par sa méthode d'approximation

// =========  ACCESSEURS ET "SETTEURS" :

    virtual void augmente_t(double const& dt);                      // Permet d'augmenter le temps de l'intégrateur

    virtual double getTemps() const ;                               // Permet de savoir la coordonnée temporelle


// =========================================================================================

protected :

// =========  ATTRIBUTS :

    double m_t;                                                     // le temps


};





class IntegrateurEulerCromer: public Integrateur
{
public :

// =========

    IntegrateurEulerCromer(double const& t0);                       // ctor d'Euler-Cromer

    virtual ~IntegrateurEulerCromer() {}                                       // dtor d'Euleur-Cromer

// =========

    virtual IntegrateurEulerCromer* clone() const;                  // Renvoie un pointeur sur une copie
                                                                    // polymorphique de l'intégrateur Euler-Cromer

// =========  INTEGRE :

    void integre(Integrable& integrable, double const& dt) const;   // Intègre nunmériquement avec un pas de temps dt
                                                                    // et via la méthode d'Euler-Cromer

};






class IntegrateurNewmark: public Integrateur
{
public :

// =========

    IntegrateurNewmark (double const& t0);                          // ctor de Newmark

    virtual ~IntegrateurNewmark() {}                                // dtor de Newmark

// =========

    virtual IntegrateurNewmark* clone() const;                      // Renvoie un pointeur sur une copie
                                                                    // polymorphique de l'intégrateur de Newmark
// =========  INTEGRE :

    virtual void integre(Integrable& integrable, double const& dt) const;
                                                                    // Intègre numériquement avec un pas de temps
                                                                    // dt et via la méthode de Newmark

};






class IntegrateurRK4: public Integrateur
{
public :

    IntegrateurRK4(double const& t0);

    virtual ~IntegrateurRK4() {}

    virtual IntegrateurRK4* clone() const;
    virtual void integre(Integrable& integrable, double const& dt) const;
};



#endif // INTEGRATEUR_H
