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

    virtual void dessine(Systeme const&, std::ostream&) ;

    virtual void dessine(Integrable const&, std::ostream&);

};



#endif //TOUPIES_DL_TEXTVIEWER_H
