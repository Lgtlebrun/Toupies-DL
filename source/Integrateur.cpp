#include "Integrateur.h"
#include "Toupie.cpp"



void IntegrateurEulerCromer::integre(Integrable& integrable, double const& dt) const {

        /// Intègre numériquement selon la méthode d'Euler Cromer


    toupie.setVitesse( toupie.getVitesse() + dt * toupie.equEvol(m_t) );

    toupie.setParam( toupie.getParam() + dt * toupie.getVitesse() );


}



void IntegrateurNewmark::integre(Integrable& integrable, double const& dt, double const& epsilon) const {

        /// Integre numériquement selon la méthode de Newmark


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


        /// Integre numériquement selon la méthode Runge-Kutta 4





            // A faire éventuellement plus tard




}
