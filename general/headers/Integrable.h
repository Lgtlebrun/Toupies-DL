#pragma once

#ifndef INTEGRABLE_H
#define INTEGRABLE_H


#include "Vecteur.h"
#include "Dessinable.h"
#include "constantes.h"
#include <iostream>


class Integrable : public Dessinable
{
public:

// =========

    Integrable(SupportADessin&, std::string const&, Vecteur const&, Vecteur const&);
                                                                        // Prend un support à dessin où dessiner
                                                                        // l'intégrable, un string; le type d'objet
                                                                        // qu'est l'intégrable et deux vecteurs :
                                                                        // position et vitesse initiale

    virtual ~Integrable();                                              // dtor de l'intégrable

// =========

    virtual Vecteur equEvol(double const& temps) = 0;             // l'equation d'évolution de l'intégrable
                                                                        // dépend du type d'intégrable, d'où la
                                                                        // virtualité pure
    virtual Integrable* clone() const = 0;                              // Renvoie un pointeur sur une copie
                                                                        // polymorphique de l'intégrable

// =========  AFFICHAGE :

    virtual std::string getType() const;                                // Permet de saisir le nom de l'intégrable
    virtual void statsCorps(std::ostream&) const;                       // Permet d'afficher les statistiques
                                                                        // de l'intégrable

    virtual double distanceSecurite() const =0;                         // méthode qui permet d'estimer la distance minimale
                                                                        // nécessaire pour dessiner deux intégrables et qu'ils
                                                                        // ne soient pas l'un dans l'autre

// =========  ACCESSEURS ET SETTEURS :

    Vecteur getParam() const;                                           // Renvoit le vecteur paramètre de l'intégrable
    void setParam(Vecteur const& newV);                                 // Set le vecteur paramètre de l'intégrable


    Vecteur getVitesse() const;                                         // Renvoit le vecteur vitesse de l'intégrable
    void setVitesse(Vecteur const& newV);                               // Set le vecteur vitesse de l'intégrable


// ======================================================================================

protected:

// =========  ATTRIBUTS MATHEMATIQUES :

    Vecteur m_P;                // P est le vecteur paramètres
    Vecteur m_Ppoint;           // Ppoint est le vecteur dérivée temporelle de P

// =========  ATTRIBUT "COSMETIQUE" :

    std::string m_type = "Corps Solide";                // le type de l'intégrable. Il est de base supposé étant
                                                        // un simple solide

};

#endif // INTEGRABLE_H
