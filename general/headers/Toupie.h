#pragma once

#ifndef TOUPIE_H
#define TOUPIE_H


#include "Integrable.h"
#include <string>



class Toupie : public Integrable
{
public:

// =========

    Toupie(SupportADessin&, std::string const&, Vecteur const&, Vecteur const&, Vecteur const&, double const&, double const&, double const&, double const&, double const&, double const&);
                                // Prend un support à dessin où afficher la toupie, un string pour la nomme,
                                // 2 Vecteurs, le premier position et le second vitesse (avec theta psy phi comme
                                // convention). Il prend ensuite I_A1, I_3 les moments d'inertie, la masse Volumique,
                                // la masse puis la distance point de contact-sol

    virtual ~Toupie();          // dtor

// =========

    virtual Toupie* clone() const = 0;                  // Renvoie un pointeur sur une copie polymorphique de la toupie

// ========

    Vecteur getPosition() const;                        // Renvoie la position du point de contact avec le sol

// =========  EQUATION D'EVOLUTION :

    virtual Vecteur equEvol(double const& temps) override;        // Equation d'évolution d'une toupie générale

// =========  AFFICHAGE :

    virtual void statsCorps(std::ostream& sortie) const;                // Affichage de toutes les statistiques de
                                                                        // la toupie

    virtual void setDistSecu();

// ===================================================================================

protected:

// =========  ATTRIBUTS PHYSIQUES :

    double m_IA1;                           // moment d'inertie perpendiculaire à l'axe de rotation mesuré depuis le
                                            // point de contact avec le sol, A, à une distance m_d du sol
    double m_I3;                            // moment d'inertie selon l'axe central

    double m_masse;                         // la masse de la toupie

    double m_masseVolumique;                // la masse volumique de la toupie

    double m_d;                             // distance du centre de masse au point de contact avec le sol

// =========  ATTRIBUTS D'AFFICHAGE :

    std::string m_type;                     // Nom du type de la toupie

// =========  METHODES PROTECTED :

    void modulo2Pi();                                                    // Remet le paramètre modulo Pi, afin d'éviter
                                                                        // la divergence des fonctions sin et cos

};



#endif // TOUPIE_H
