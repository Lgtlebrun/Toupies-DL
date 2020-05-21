#ifndef TOUPIES_DL_OBJETPHYSIQUE_H
#define TOUPIES_DL_OBJETPHYSIQUE_H

#include "Integrable.h"

class ObjetPhysique : public Integrable {

public :

// =========

    ObjetPhysique(SupportADessin& sup, std::string const& nom, Vecteur const& param, Vecteur const& Paramp);
    /* Constructeur d'objet physique général, dont le but est de permettre d'appeler une méthode *
     * liée à une grandeur physique conservée dans les systèmes sans force non-conservative.     *
     * On a besoin d'un SupportADessin, où dessiner l'objet, puis de son nom, son vecteur de     *
     * paramètres ainsi que le vecteur de leurs dérivées                                         */

    virtual ~ObjetPhysique();       // dtor d'objet physique

// =========

    virtual ObjetPhysique* clone() const = 0;               // Elle est virtuelle pure car la classe l'est

    virtual Vecteur equEvol(double const& temps) = 0;       // Un objet physique n'a pas d'équation d'évolution

// =========

        // Méthodes virtuelles pures permettant le calcul de grandeurs physiques normalement conservées */

    virtual double Energie() const = 0;

    virtual double L_k() const = 0;

    virtual double L_a() const = 0;

    virtual double ProdMixte() const = 0;


// =========

    virtual Vecteur getPosition() const;          // renvoie la position carthésienne, peut ne pas exister en quel cas nous sortons le paramètre
    virtual void setPosition(Vecteur const& newPosition);                           // set la position carthésienne

    virtual Vecteur getVitesse() const;
    virtual void setVitesse(Vecteur const& newVitesse);


};



#endif //TOUPIES_DL_OBJETPHYSIQUE_H
