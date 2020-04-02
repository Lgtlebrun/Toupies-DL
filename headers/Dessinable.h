#pragma once

#ifndef TOUPIES_DL_DESSINABLE_H
#define TOUPIES_DL_DESSINABLE_H

#include <iostream>
#include "Clonable.h"
#include "SupportADessin.h"
#include "constantes.h"

class TextViewer;

class Dessinable : public Clonable{

public:

    Dessinable();
    Dessinable(SupportADessin& support);


    void changeSupport(SupportADessin&);


    virtual void dessine() = 0;



protected:

    SupportADessin& m_support;
};

#endif //TOUPIES_DL_DESSINABLE_H