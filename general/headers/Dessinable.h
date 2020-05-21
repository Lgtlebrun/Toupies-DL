#pragma once

#ifndef TOUPIES_DL_DESSINABLE_H
#define TOUPIES_DL_DESSINABLE_H

#include <iostream>
#include "Clonable.h"
#include "SupportADessin.h"
#include "constantes.h"



class Dessinable : public Clonable{

public:

// =========

    Dessinable(SupportADessin& support);
    // ctor de Dessinable. prend un SupportADessin en argument car nous aimerions savoir où le dessiner

// =========

    virtual void dessine() = 0;
    // méthode virtuelle pure permettant de dessiner n'importe quel dessinable

// =========

    virtual void changeSupport(SupportADessin&);                    // méthode permettant de changer de SupportADessin


// ======================================================================================

protected:

// =========  ATTRIBUTS :

    SupportADessin* m_support;                              // l'endroit où l'objet dessinable sera dessiné

};

#endif //TOUPIES_DL_DESSINABLE_H