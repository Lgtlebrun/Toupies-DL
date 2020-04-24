#ifndef TOUPIECHINOISE_H
#define TOUPIECHINOISE_H

#include "Toupie.h"

class ToupieChinoise : public Toupie
{
public:
// =========

    ToupieChinoise(SupportADessin&, Vecteur const&, Vecteur const&, Vecteur const&, double const&, double const&, double const&);
                                                            // Construit une toupie chinoise à partir de là où nous voulons le
                                                            // représenter, de sa position puis sa vitesse initiale puis de
                                                            // son rayon, la hauteur de la coupure, puis sa masse volumique

    virtual ~ToupieChinoise();                              // dtor d'une toupie chinoise

// =========

    virtual ToupieChinoise* clone() const;                  // Renvoie un pointeur sur une copie polymorphique de la toupie chinoise

    virtual void dessine() override;                        // méthode permettant un affichage personnalisé de la
                                                            // classe ToupieyChinoise

    virtual Vecteur equEvol(const double &temps) override;

// =========  ACCESSEURS :

    double getRayon() const;                                // renvoit le rayon de la toupie
    double getHauteur() const;                              // renvoit la hauteur de coupure de la toupie

// =========  AFFICHAGE :

    virtual void statsCorps(std::ostream& sortie) const;          // affiche dans un ostream les statistiques de la toupie

    virtual void setDistSecu();                             // Calcule la distance de sécurité nécessaire à un affichage
                                                            // de qualité

// =====================================================================================


protected :

// =========  CALCUL DE GRANDEURS PHYSIQUES :

    virtual double calculeI1();

    virtual double calculeIA1(double const&, double const&, double const&) const;
                                                            // Calcule le moment d'inertie I_A1
    virtual double calculeI3(double const&, double const&, double const&) const;
                                                            // Calcule le moment d'inertie I_3

    double masse(double const&, double const&, double const&) const;
                                                            // Calcule la masse de la toupie

    double calcule_d() const;                               // Calcule la norme de AG

// ========= FONCTIONS INTERMEDIAIRES :

    double f1();                                         // Méthodes associées au calcul de equEvol()
    double f2();
    double f3();

// =========  ATTRIBUTS :

    double m_rayon;                                     // le rayon de la sphère tronquée
    double m_hauteur;                                   // sa hauteur de coupure

    // A noter: m_IA1 n'a pas le sens de IA1 pour cette toupie, puisque cela allogerait les calculs

};


std::ostream& operator<<(std::ostream&, ToupieChinoise const&);             // surcharge de l'opérateur << pour afficher
                                                                            // une toupie chinoise




#endif // TOUPIECHINOISE_H
