#pragma once

#ifndef TOUPIES_DL_SYSTEME_H
#define TOUPIES_DL_SYSTEME_H


#include "SupportADessin.h"
#include <vector>
#include "Dessinable.h"
#include <iostream>
#include "Integrateur.h"

class Systeme : public Dessinable {

public:

    Systeme(SupportADessin *support, Integrateur*);

    /// Nous n'avons pas envie que quelqu'un, un jour utilise un intégrateur de base
    /// puisqu'il ne fait pas de sens, étant une classe abstraite

    virtual ~Systeme();

    virtual void dessine() override;

    void affiche(std::ostream& sortie);

    Toupie * getToupie(size_t k) const;

    unsigned int getNbToupies() const;

    void evolue(double const&) ;

protected:

    std::vector<Toupie*> m_toupies;

    Integrateur* m_integrateur;


};


    std::ostream& operator<<(std::ostream& sortie, Systeme& s);



#endif //TOUPIES_DL_SYSTEME_H
