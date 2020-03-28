#include "../headers/ConeSimple.h"
#include <cmath>


ConeSimple::ConeSimple(Vecteur const& param, Vecteur const& vit, double const& rayon, double const& hauteur, double const& masseVolumique)
        : Toupie(param, vit, calculeIA1(rayon, hauteur, masseVolumique), calculeI3(rayon, hauteur, masseVolumique),
                masse(rayon, hauteur, masseVolumique), 3.0/4.0*hauteur, masseVolumique), m_rayon(rayon), m_hauteur(hauteur)
{}


double ConeSimple::calculeIA1(double const& rayon, double const& hauteur, double const& masseVolumique) const {

    return M_PI*rayon*rayon*hauteur*masseVolumique/20*( rayon*rayon+3.0/5*hauteur*hauteur );

}


double ConeSimple::calculeI3(double const& rayon, double const& hauteur, double const& masseVolumique) const {

    return M_PI*rayon*rayon*hauteur*masseVolumique/10*( rayon*rayon);

}


double ConeSimple::masse(double const& rayon, double const& hauteur, double const& masseVolumique) const{

    return 1.0/3*M_PI*rayon*rayon*hauteur*masseVolumique;

}


std::string ConeSimple::typeToupie() const {

    return "Cone Simple" ;

}


void ConeSimple::statsToupie(std::ostream& sortie) const{

    sortie << "masse [kg]               :  " << m_masse << std::endl;
    sortie << "masse volumique [kg m-3] :  " << m_masseVolumique << std::endl;
    sortie << "distance [m]             :  " << m_d << std::endl;

    sortie << "rayon [m]                :  " << m_rayon << std::endl;
    sortie << "hauteur [m]              :  " << m_hauteur << std::endl;


}