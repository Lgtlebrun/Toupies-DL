#include "Integrateur.h"
#include "Toupie.cpp"



void IntegrateurEulerCromer::integre(Integrable& integrable, double const& dt) const {

        /// Int�gre num�riquement selon la m�thode d'Euler Cromer


    toupie.setVitesse( toupie.getVitesse() + dt * toupie.equEvol(m_t) );

    toupie.setParam( toupie.getParam() + dt * toupie.getVitesse() );


}



void IntegrateurNewmark::integre(Integrable& integrable, double const& dt, double const& epsilon) const {

        /// Integre num�riquement selon la m�thode de Newmark


    Vecteur s ( integrable.equEvol(m_t) ) ;

    Vecteur P_nmoins1 ( integrable.getParam() ) ;

    Vecteur Ppoint_nmoins1 ( integrable.getVitesse() ) ;


    do {


        Vecteur q ( integrable.getParam() ) ;

        Vecteur r ( integrable.equEvol(m_t + dt) ) ;


        integrable.setVitesse( Ppoint_nmoins1 + dt/2 * (r + s) ) ;

        integrable.setParam( P_nmoins1 + dt * Ppoint_nmoins1 + dt*dt/3 * (1/2 * r + s) ) ;



        Vecteur dist ( integrable.getParam() - q ) ;


    } while ( dist.norme() >= epsilon ) ;


}


void IntegrateurRK4::integre(Integrable& integrable, double const& dt) const {


        /// Integre num�riquement selon la m�thode Runge-Kutta 4





            // A faire �ventuellement plus tard




}
