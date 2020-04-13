#include "../headers/ConeSimple.h"
#include <cmath>


ConeSimple::ConeSimple(SupportADessin& sup, Vecteur const& param, Vecteur const& vit, double const& rayon, double const& hauteur, double const& masseVolumique, double const& pos1, double const& pos2)
        : Toupie(sup, "Cone simple", param, vit, calculeIA1(rayon, hauteur, masseVolumique), calculeI3(rayon, hauteur, masseVolumique),
                 masseVolumique, masse(rayon, hauteur, masseVolumique), 3.0/4.0*hauteur, pos1, pos2), m_rayon(rayon), m_hauteur(hauteur)
{}


ConeSimple::~ConeSimple() {

}


double ConeSimple::calculeIA1(double const& rayon, double const& hauteur, double const& masseVolumique) const {

    return masse(rayon, hauteur, masseVolumique)*(3.0/20*rayon*rayon+3.0/5*hauteur*hauteur);

}


double ConeSimple::calculeI3(double const& rayon, double const& hauteur, double const& masseVolumique) const {

    return 3*masse(rayon, hauteur, masseVolumique)/10*rayon*rayon;

}


double ConeSimple::masse(double const& rayon, double const& hauteur, double const& masseVolumique) const{

    return 1.0/3*M_PI*rayon*rayon*hauteur*masseVolumique;

}




void ConeSimple::statsCorps(std::ostream& sortie) const{

    sortie << "masse [kg]               :  " << m_masse << std::endl;
    sortie << "masse volumique [kg m-3] :  " << m_masseVolumique << std::endl;
    sortie << "distance [m]             :  " << m_d << std::endl;

    sortie << "rayon [m]                :  " << m_rayon << std::endl;
    sortie << "hauteur [m]              :  " << m_hauteur << std::endl;


}

ConeSimple *ConeSimple::clone() const {

    return new ConeSimple(*this);
}


void ConeSimple::dessine() {

    m_support.dessine(*this);
}

double ConeSimple::getRayon() const {

    return m_rayon;
}

double ConeSimple::getHauteur() const {

    return m_hauteur;
}


std::ostream& operator<<(std::ostream& flux, ConeSimple const& C){

    flux << "Type : " << C.getType() << "  ; Parametre : " << C.getParam() << "  ;  Vitesse : " << C.getVitesse()
            << "  ; Rayon : " << C.getRayon() << "  ; Hauteur : " << C.getHauteur() << std::endl;

    return flux;
}


double ConeSimple::distanceSecurite() const {

    return sqrt(m_hauteur*m_hauteur + m_rayon*m_rayon);

}