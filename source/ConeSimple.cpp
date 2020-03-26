#include "../headers/ConeSimple.h"


ConeSimple::ConeSimple(Vecteur const& param, Vecteur const& vit, double const& rayon, double const& hauteur, double const& masse)
        : Toupie(param, vit, calculeIA1(rayon, hauteur, masse), calculeI3(rayon, masse), masse, 3.0/4.0*hauteur)
{}

double ConeSimple::calculeIA1(double const& rayon, double const& hauteur, double const& masse) const {

    return 3*masse/20*( rayon*rayon+3.0/5*hauteur*hauteur );

}

double ConeSimple::calculeI3(double const& rayon, double const& masse) const {

    return 3*masse/10*( rayon*rayon);

}