#pragma once

#ifndef TOUPIES_DL_SYSTEME_H
#define TOUPIES_DL_SYSTEME_H


#include "SupportADessin.h"
#include <vector>
#include "Dessinable.h"

class Systeme : public Dessinable {

public:

    Systeme(SupportADessin *support);

    virtual ~Systeme();

    virtual void dessine() override;

protected:

    std::vector<Toupie*> m_toupies;


};





#endif //TOUPIES_DL_SYSTEME_H
