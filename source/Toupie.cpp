#include "../headers/Toupie.h"
#include <cmath>


Toupie::Toupie (std::string const& type, Vecteur const& param, Vecteur const& vit, double const& IA1, double const& I3, double const& masseVolumique, double const & masse, double const& d)
    : Integrable(type, param, vit), m_IA1(IA1), m_I3(I3), m_masse(masse), m_d(d), m_masseVolumique(masseVolumique)
{}

Toupie::~Toupie() {}


Vecteur Toupie::equEvol(double const& temps) const {

    /// Avec l'équation d'évolution en page 12 du complément mathématique, assumant donc distance centre de masse -
    /// point de contact = cste


    Vecteur sortie ;                // convention : (théta, psy, phi)
                                    // init. au vecteur nul


    if (abs(m_IA1) <= 1e-9 ) {

        return sortie;              // pas d'accélération de la rotation s'il n'y a rien à faire tourner !

    } else if (abs(sin(m_P.getCoord(0))) <= 1e-9 ) {

        return sortie;              // voir formule

    }

    sortie.setCoord(0, 1.0/m_IA1*(m_masse*g.norme()*m_d*sin(m_P.getCoord(0))+m_Ppoint.getCoord(1)*sin(m_P.getCoord(0))
    * ((m_IA1-m_I3)*m_Ppoint.getCoord(1)*cos(m_P.getCoord(0))-m_I3*m_Ppoint.getCoord(2) )) ) ;

    sortie.setCoord(1, m_Ppoint.getCoord(0)/(m_IA1*sin(m_P.getCoord(0))) * ((m_I3-2*m_IA1)*m_Ppoint.getCoord(1)*cos(m_P.getCoord(0))
    + m_I3*m_Ppoint.getCoord(2) ) ) ;

    sortie.setCoord(2, m_Ppoint.getCoord(0)/(m_IA1*sin(m_P.getCoord(0))) * ( m_IA1- (m_I3-m_IA1)*cos(m_P.getCoord(0))
    - m_I3*m_Ppoint.getCoord(2)*cos(m_P.getCoord(0))) ) ;



    return sortie;

}


void Toupie::statsCorps(std::ostream& sortie) const{

    sortie << "masse [kg]               :  " << m_masse << std::endl;
    sortie << "masse volumique [kg m-3] :  " << m_masseVolumique << std::endl;
    sortie << "distance [m]             :  " << m_d << std::endl;

}




