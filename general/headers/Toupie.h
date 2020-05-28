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
/* Nous prenons en argument du ctor un support à dessin (là où sera affichée la toupie), un type  *
* de toupie, qui est un nom générique que l'on voudrait lui donner. Le vecteur angles doit       *
* contenir (theta, psy, phi) comme coordonnées. anglespoint contient la dérivée temporelle de    *
* ces angles, dans le même ordre. posA est la position (x,y,z) de la pointe de la toupie. IA1 et *
* I3 sont les moments d'inertie (même notation que dans le complément mathématique). masse est   *
* la masse de la toupie et d la distance entre le point de contact et le centre de masse de la   *
* toupie.                                                                                       */

    virtual ~Toupie();          // dtor

// =========

    virtual void dessine();           // Permet l'affichage de la toupie dans son SupportADessin

    virtual Toupie* clone() const;  // Renvoie un pointeur sur une copie polymorphique de la toupie

// =========

    Vecteur getParam() const override;

        // Méthodes set héritées d'Integrable

    void setParam(Vecteur const& newParam);
    void setPpoint(Vecteur const& newPpoint);


        // Méthodes get et set spécifiques à une toupie

    virtual Vecteur getAngles() const;
    virtual void setAngles(Vecteur const& newAngles);

    virtual Vecteur getAnglesp() const;
    virtual void setAnglesp(Vecteur const& newAnglesp);

    virtual Vecteur getPosition() const;              // renvoie la position carthésienne du centre de masse
    virtual void setPosition(Vecteur const& newPosA); // set la position carthésienne du point de contact

    virtual Vecteur getVitesse() const;       // revoie la vitesse du centre de masse

    virtual Vecteur AG() const;               // renvoie le vecteur point de contact-centre de masse

// =========  EQUATION D'EVOLUTION :

    virtual Vecteur equEvol() override;        // Equation d'évolution d'une toupie générale

// =========  AFFICHAGE :

    virtual void statsCorps(std::ostream& sortie) const;     // Affichage de toutes les statistiques de la toupie

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

    Vecteur modulo2Pi() const;
    // Remet le paramètre modulo Pi, afin d'éviter la divergence des fonctions sin et cos

    virtual Matrice3 I_A() const ;
    // Calcule le tenseur d'intertie au point de contact avec le sol

    virtual Matrice3 I_G() const;
    // calcule le tenseur d'inertie au centre de masse

    Vecteur omega() const;
    // Caclule le vecteur omega défini dans le complément mathématique

    Matrice3 S() const;
    // Matrice de passage de RG à RO

};


std::ostream& operator<<(std::ostream&, Toupie const& Toupy);  // surcharge de l'opérateur << pour afficher un cône simple



#endif // TOUPIE_H
