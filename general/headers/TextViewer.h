#pragma once

#ifndef TOUPIES_DL_TEXTVIEWER_H
#define TOUPIES_DL_TEXTVIEWER_H


#include <iostream>
#include "Systeme.h"
#include "ConeSimple.h"
#include "Clonable.h"
#include "Tests/Oscillateur.h"
#include "Tests/Bille.h"
#include "ToupieChinoise.h"
#include "Toupie.h"



class TextViewer : public SupportADessin, public Clonable
{
public :

// =========

    TextViewer(std::ostream&);                              // ctor prenant un ostream qui sera la sortie du texte

    virtual ~TextViewer() {}                                // dtor

// =========

    virtual TextViewer* clone() const;                      // Renvoie un pointeur sur une copie polymorphique du TextViewer

// =========  DESSINE :

    virtual void dessine(Systeme const&);                   // Méthodes dessinant les divers objets
    virtual void dessine(Bille const&) ;
    virtual void dessine(Oscillateur const&) ;
    virtual void dessine(ConeSimple const&) ;
    virtual void dessine(ToupieChinoise const&) ;
    virtual void dessine(Toupie const&);

// =====================================================================================

protected:

// =========  ATTRIBUTS :

    std::ostream& m_flux;

};



#endif //TOUPIES_DL_TEXTVIEWER_H
