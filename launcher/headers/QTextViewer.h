#pragma once

#ifndef TOUPIES_DL_QTEXTVIEWER_H
#define TOUPIES_DL_QTEXTVIEWER_H


#include <iostream>
#include "../general/headers/Systeme.h"
#include "../general/headers/ConeSimple.h"
#include "../general/headers/Clonable.h"
#include "../general/headers/ToupieChinoise.h"
#include "../general/headers/Tests/Oscillateur.h"
#include "../general/headers/Tests/Bille.h"
#include "../general/headers/Trace.h"
#include "TextEdit.h"




class QTextViewer : public SupportADessin, public Clonable
{

    /// Classe adaptant TextViewer au format GUI

public :

// =========

    QTextViewer(TextEdit&);                              // ctor prenant un ostream qui sera la sortie du texte

    virtual ~QTextViewer() {}                                // dtor

// =========

    virtual QTextViewer* clone() const;                      // Renvoie un pointeur sur une copie polymorphique du TextViewer
    TextEdit& getFlux() const {return m_flux;
                                  }
// =========  DESSINE :

    virtual void dessine(Systeme const&);                   // Méthodes dessinant les divers objets
    virtual void dessine(Bille const&) ;
    virtual void dessine(Oscillateur const&) ;
    virtual void dessine(ConeSimple const&) ;
    virtual void dessine(const ToupieChinoise &) ;
    virtual void dessine(const Toupie &);
    virtual void dessine(Trace const&){}



// =====================================================================================

protected:

// =========  ATTRIBUTS :

    TextEdit& m_flux;       // Le flot est ici un TextEdit pour l'affichage Texte


};



#endif //TOUPIES_DL_QTEXTVIEWER_H
