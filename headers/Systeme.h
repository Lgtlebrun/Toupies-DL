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
    Systeme(Systeme const&);
    virtual ~Systeme();

    virtual void dessine() override;
    void affiche(std::ostream& sortie);



    Integrable* getCorps(size_t k) const;

    double getTemps() const;

    unsigned int getNbToupies() const;

    void evolue(double const&) ;

    void addIntegrable(Integrable*);

    Systeme& operator=(Systeme const& S);

protected:

    std::vector<Integrable*> m_corps;

    Integrateur* m_integrateur;


};


    std::ostream& operator<<(std::ostream& sortie, Systeme& s);



#endif //TOUPIES_DL_SYSTEME_H
