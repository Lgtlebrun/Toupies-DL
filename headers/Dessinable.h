#pragma once

#ifndef TOUPIES_DL_DESSINABLE_H
#define TOUPIES_DL_DESSINABLE_H

#include "SupportADessin.h"



class Dessinable {

public:

    Dessinable(SupportADessin& support);


    void changeSupport(SupportADessin&);


    virtual void dessine() = 0;



protected:

    SupportADessin& m_support;
};

#endif //TOUPIES_DL_DESSINABLE_H