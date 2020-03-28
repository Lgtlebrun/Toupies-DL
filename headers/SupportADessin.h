//
// Created by lgtle on 26/03/2020.
//
#pragma once

#ifndef TOUPIES_DL_SUPPORTADESSIN_H
#define TOUPIES_DL_SUPPORTADESSIN_H

#include "ConeSimple.h"
#include "Tests/Bille.h"
#include "Tests/Oscillateur.h"


class Systeme;
class SupportADessin {


public:

    virtual ~SupportADessin() {}
    // on supposera ici que les supports ne sont ni copiés ni déplacés

    virtual void dessine(ConeSimple const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    virtual void dessine(Toupie const&) = 0;
    virtual void dessine(Oscillateur const&) = 0;
    virtual void dessine(Bille const&) = 0;
    // ... autres choses que vous voudriez dessiner...



};






#endif //TOUPIES_DL_SUPPORTADESSIN_H
