#include "../headers/Toupie.h"
#include <math.h>
#include <iostream>


Toupie::Toupie (SupportADessin& sup, std::string const& type, Vecteur const& param, Vecteur const& vit, double const& IA1, double const& I3, double const& masseVolumique, double const & masse, double const& d)
    : Integrable(sup, type, param, vit), m_IA1(IA1), m_I3(I3), m_masse(masse), m_d(d), m_masseVolumique(masseVolumique)
{}

Toupie::~Toupie() {}


Vecteur Toupie::equEvol(double const& temps) {

    /// Avec l'équation d'évolution en page 12 du complément mathématique, assumant donc distance centre de masse -
    /// point de contact = cste


    Vecteur sortie;                // convention : (théta, psy, phi)
                                  // init. au vecteur nul

    moduloPi();

    if ( fabs(m_IA1) < PREC ) {

        return sortie;              // pas d'accélération de la rotation s'il n'y a rien à faire tourner !

    }
    if (fabs(sin(m_P.getCoord(0))) < PREC ) {

        return sortie;              // si la toupie a un angle à la verticale nul, alors, vu qu'il n'y a aucun frottement,
                                    // la somme des force est nule, entraînant une accélération nulle

    }

    sortie.setCoord(0, 1.0/m_IA1*(m_masse*g.norme()*m_d*sin(m_P.getCoord(0))+m_Ppoint.getCoord(1)*sin(m_P.getCoord(0))
    * ((m_IA1-m_I3)*m_Ppoint.getCoord(1)*cos(m_P.getCoord(0))-m_I3*m_Ppoint.getCoord(2) )) ) ;

    sortie.setCoord(1, m_Ppoint.getCoord(0)/(m_IA1*sin(m_P.getCoord(0))) * ((m_I3-2*m_IA1)*m_Ppoint.getCoord(1)*cos(m_P.getCoord(0))
    + m_I3*m_Ppoint.getCoord(2) ) ) ;

    sortie.setCoord(2, m_Ppoint.getCoord(0)/(m_IA1*sin(m_P.getCoord(0))) * ( (m_IA1- (m_I3-m_IA1)*cos(m_P.getCoord(0))*cos(m_P.getCoord(0)) )
    *m_Ppoint.getCoord(1) - m_I3*m_Ppoint.getCoord(2)*cos(m_P.getCoord(0))) ) ;


    return sortie;

}


void Toupie::statsCorps(std::ostream& sortie) const{

    sortie << "masse [kg]               :  " << m_masse << std::endl;
    sortie << "masse volumique [kg m-3] :  " << m_masseVolumique << std::endl;
    sortie << "distance [m]             :  " << m_d << std::endl;

}


void Toupie::moduloPi(){

    for (unsigned int k(0); k < m_P.getDim() ; ++k) {

        if (m_P.getCoord(k)>=0) {

            m_P.setCoord(k, m_P.getCoord(k)-floor(m_P.getCoord(k)/(2*M_PI))*2*M_PI);

        } else {

            m_P.setCoord(k, m_P.getCoord(k)+ceil(m_P.getCoord(k)/(2*M_PI))*2*M_PI);

        }

        std::cout << "+";

    }


}

