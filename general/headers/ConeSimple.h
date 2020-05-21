#pragma once


#ifndef TOUPIES_DL_CONESIMPLE_H
#define TOUPIES_DL_CONESIMPLE_H


#include "Toupie.h"


class ConeSimple : public Toupie

{
public :

// =========

    ConeSimple(SupportADessin& sup, Vecteur const& Angles, Vecteur const& AnglesPoint, Vecteur const& posA, double const& rayon, double const& hauteur, double const& masseVolumique);
                                                        // Construit un cône simple à partir de là où nous voulons le
                                                        // représenter, de sa position puis sa vitesse initiale puis de
                                                        // son rayon, sa hauteur puis sa masse volumique

    virtual ~ConeSimple();                              // dtor d'un cône simple

// =========

    virtual ConeSimple* clone() const;                  // Renvoie un pointeur sur une copie polymorphique du cône

    virtual void dessine() override;                    // méthode permettant un affichage personnalisé de la
                                                        // classe ConeSimple

    virtual Vecteur equEvol(const double &temps) override;

// =========  ACCESSEURS :

    double getRayon() const;                            // renvoit le rayon du cône
    double getHauteur() const;                          // renvoit la hauteur du cône

// =========  AFFICHAGE :

    virtual void statsCorps(std::ostream& sortie) const;            // affiche dans un ostream les statistiques du cône

// =====================================================================================


    virtual double calculeIA1(double const&, double const&, double const&) const;

// Calcule le moment d'inertie I_A1
    virtual double calculeI3(double const&, double const&, double const&) const;

    double masse(double const&, double const&, double const&) const;

protected :

// =========  CALCUL DE GRANDEURS PHYSIQUES :

    // Calcule le moment d'inertie I_3

    // Calcule la masse de la toupie

// =========  ATTRIBUTS :

    double m_rayon;                                     // le rayon du cône
    double m_hauteur;                                   // sa hauteur
    double m_masseVolumique;                            // la masse volumique de la toupie

};


std::ostream& operator<<(std::ostream&, ConeSimple const&);             // surcharge de l'opérateur << pour afficher
                                                                        // un cône simple



#endif //TOUPIES_DL_CONESIMPLE_H
