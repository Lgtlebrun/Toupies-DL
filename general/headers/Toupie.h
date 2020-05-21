#pragma once

#ifndef TOUPIE_H
#define TOUPIE_H


#include "ObjetPhysique.h"
#include "Matrice3.h"
#include <string>



class Toupie : public ObjetPhysique
{
public:

// =========

    Toupie(SupportADessin& sup, std::string const& nom, Vecteur const& angles, Vecteur const& anglesPoint, Vecteur const& position_Pointe, double const& IA1, double const& I3, double const& masse, double const& norme_AG);
                                // Prend un support à dessin où afficher la toupie, un string pour la nomme,
                                // 2 Vecteurs, le premier position et le second vitesse (avec theta psy phi comme
                                // convention). Il prend ensuite I_A1, I_3 les moments d'inertie, la masse Volumique,
                                // la masse puis la distance point de contact-sol

    virtual ~Toupie();          // dtor

// =========

    virtual void dessine();

    virtual Toupie* clone() const;                  // Renvoie un pointeur sur une copie polymorphique de la toupie

// =========

    void setParam(Vecteur const&);

    virtual Vecteur getAngles() const;
    virtual void setAngles(Vecteur const&);

    virtual Vecteur getAnglesp() const;
    virtual void setAnglesp(Vecteur const&);

    virtual Vecteur getPosition() const;                                // renvoie la position carthésienne du pt de contact
    virtual void setPosition(Vecteur const&);                           // set la position carthésienne

    virtual Vecteur getVitesse() const;                                 // revoie la vitesse du point de contact

    virtual Vecteur AG() const;

// =========  EQUATION D'EVOLUTION :

    virtual Vecteur equEvol(double const& temps) override;        // Equation d'évolution d'une toupie générale

// =========  AFFICHAGE :

    virtual void statsCorps(std::ostream& sortie) const;                // Affichage de toutes les statistiques de
                                                                        // la toupie

// =========  METHODES PERMETTANT DE MONTRER LES GRANDEURS PHYSIQUES :

    virtual double Energie() const;

    virtual double L_a() const;

    virtual double L_k() const;

    virtual double ProdMixte() const;

// ===================================================================================

protected:

// =========  ATTRIBUTS PHYSIQUES :

    double m_IA1;                           // moment d'inertie perpendiculaire à l'axe de rotation mesuré depuis le
                                            // point de contact avec le sol, A, à une distance m_d du sol
    double m_I3;                            // moment d'inertie selon l'axe central

    double m_masse;                         // la masse de la toupie

    double m_d;                             // distance du centre de masse au point de contact avec le sol

// =========  ATTRIBUTS D'AFFICHAGE :

    std::string m_type;                     // Nom du type de la toupie

// =========  METHODES PROTECTED :

    Vecteur modulo2Pi() const;                                                    // Remet le paramètre modulo Pi, afin d'éviter
                                                                        // la divergence des fonctions sin et cos



    virtual Matrice3 TenseurInertie() const ;

    Vecteur omega() const;

    Matrice3 S() const;

};


std::ostream& operator<<(std::ostream&, Toupie const&);             // surcharge de l'opérateur << pour afficher
// un cône simple



#endif // TOUPIE_H
