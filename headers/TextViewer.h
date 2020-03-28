#pragma once

#ifndef TOUPIES_DL_TEXTVIEWER_H
#define TOUPIES_DL_TEXTVIEWER_H

#include "SupportADessin.h"
#include "Systeme.h"
#include "ConeSimple.h"
#include "Tests/Oscillateur.h"
#include "Tests/Bille.h"


class TextViewer : public SupportADessin
{
public :

    virtual ~TextViewer() {}

    virtual void dessine(Systeme const&) ;

    virtual void dessine(Toupie const&) ;

    virtual void dessine(ConeSimple const&) ;
    virtual void dessine(Oscillateur const&) ;
    virtual void dessine(Bille const&) ;


};



#endif //TOUPIES_DL_TEXTVIEWER_H
