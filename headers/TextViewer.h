#pragma once

#ifndef TOUPIES_DL_TEXTVIEWER_H
#define TOUPIES_DL_TEXTVIEWER_H


#include <iostream>
#include "Systeme.h"
#include "ConeSimple.h"
#include "Tests/Oscillateur.h"
#include "Tests/Bille.h"




class TextViewer : public SupportADessin
{
public :

    TextViewer(std::ostream&);
    virtual ~TextViewer() {}


    virtual TextViewer* clone() const;


    virtual void dessine(Systeme const&);
    virtual void dessine(Bille const&) ;
    virtual void dessine(Oscillateur const&) ;
    virtual void dessine(ConeSimple const&) ;


protected:

    std::ostream& m_flux;

};



#endif //TOUPIES_DL_TEXTVIEWER_H
