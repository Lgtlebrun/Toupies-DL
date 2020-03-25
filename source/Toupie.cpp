#include "../headers/Toupie.h"
#include "../headers/Vecteur.h"
#include "../headers/Integrable.h"


Toupie::Toupie (Vecteur const& param, Vecteur const& vit)
    : Integrable(param, vit)
{}



ConeSimple::ConeSimple(Vecteur const& param, Vecteur const& vit, double const& rayon, double const& hauteur, double const& masse)
    : Toupie(param, vit), m_I1 (3*masse/20*( rayon*rayon+1/4*hauteur*hauteur ) ), m_I3(3*masse/10*rayon*rayon)
{}





// ============  classes pour les tests  ================================


OH::OH(Vecteur const& param, Vecteur const& vit)
    : Integrable(param, vit)
{}


Bille::Bille(Vecteur const& pos, Vecteur const& vit)
    : Integrable(pos, vit)
{}


Vecteur Bille::equEvol(double const& temps) const {

    return {0,0,-9.81};

}

