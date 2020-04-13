#pragma once

#ifndef TOUPIES_DL_SUPPORTADESSIN_H
#define TOUPIES_DL_SUPPORTADESSIN_H



class Systeme;
class Bille;
class Oscillateur;
class ConeSimple;

class Integrable;

class SupportADessin {
public:

// =========

    virtual ~SupportADessin() {}                                // dtor de SupportADessin
                                                                // on supposera ici que les supports ne sont ni copiés ni déplacés

                                                                // du support à dessin
// =========  DESSINE(...) :

    virtual void dessine(Systeme const&) = 0;                   // méthodes permettant de dessiner diverses classes
    virtual void dessine(Bille const&) = 0;
    virtual void dessine(Oscillateur const&) = 0;
    virtual void dessine(ConeSimple const&) = 0;

    // ... autres choses que vous voudriez dessiner...



};






#endif //TOUPIES_DL_SUPPORTADESSIN_H
