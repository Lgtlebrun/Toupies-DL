#include "../headers/ConeSimple.h"


ConeSimple::ConeSimple(Vecteur const& param, Vecteur const& vit, double const& rayon, double const& hauteur, double const& masse)
        : Toupie(param, vit), m_I1 (3*masse/20*( rayon*rayon+1/4*hauteur*hauteur ) ), m_I3(3*masse/10*rayon*rayon)
{}