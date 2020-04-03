#pragma once

#ifndef TOUPIES_DL_SYSTEME_H
#define TOUPIES_DL_SYSTEME_H


#include <vector>
#include "Dessinable.h"
#include <iostream>
#include "Integrateur.h"




class Systeme : public Dessinable {
public:

// =========

    Systeme(SupportADessin& support, Integrateur&);                 // ctor de la classe Systeme. Il faut un support à
                                                                    // dessin pour savoir où représenter les divers objets
                                                                    // De plus, il faut choisir une méthode d'intégration
                                                                    // numérique pour savoir comment faire évoluer le
                                                                    // Systeme

    Systeme(Systeme const&);                                        // ctor de copie

    virtual ~Systeme();                                             //  dtor de la classe Systeme

    Systeme& operator=(Systeme const& S);                           // surcharge de l'opérateur d'affectation

// =========

    virtual Systeme* clone() const;                                 // Renvoie un pointeur sur une copie polymorphique
                                                                    // du Systeme
// =========

    virtual void dessine() override;                                // Permet d'afficher le système

// =========  ACCESSEURS/SETTEURS INTEGRABLES :

    Integrable* getCorps(size_t k) const;                           // Permet d'accèder au kème intégrable. L'indice est
                                                                    // le même que pour un vector

    unsigned int getNbCorps() const;                                // Accesseur au nombre d'intégrables du système

    void addIntegrable(Integrable&);                                // Ajoute un intégrable au système

// =========   ACESSEUR INTEGRABLE :

    double getTemps() const;                                        // Accesseur au temps affiché par l'intégrateur

// =========  EVOLUTION DU SYSTEME :

    void evolue(double const&) ;                                    // Fait avancer chaque objet du système en concordance
                                                                    // avec leurs équations d'évolution. Puis cela fait
                                                                    // monter le temps de l'intégrateur de dt (qui est
                                                                    // paramètre de la méthode)

// =========  AFFICHAGE :

    void affiche(std::ostream& sortie);


// =====================================================================================

protected:

// =========  ATTRIBUTS :

    std::vector<Integrable*> m_corps;

    Integrateur& m_integrateur;


};

// =========  SURCHARGE D'OPERATEUR EXTERNE :

    std::ostream& operator<<(std::ostream& sortie, Systeme& s);



#endif //TOUPIES_DL_SYSTEME_H
