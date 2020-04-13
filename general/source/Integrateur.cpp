#include "../headers/Integrateur.h"



IntegrateurNewmark::IntegrateurNewmark(double const& t0)
    : Integrateur(t0)
{}

IntegrateurEulerCromer::IntegrateurEulerCromer(double const& t0)
    : Integrateur(t0)
{}





 void Integrateur::augmente_t(double const& dt) {

    m_t += dt ;

}

double Integrateur::getTemps() const {

    return m_t;

}


void IntegrateurEulerCromer::integre(Integrable& integrable, double const& dt) const {

        /// Int�gre num�riquement selon la m�thode d'Euler Cromer


    integrable.setVitesse( integrable.getVitesse() + dt * integrable.equEvol(m_t) );

    integrable.setParam( integrable.getParam() + dt * integrable.getVitesse() );


}



IntegrateurEulerCromer* IntegrateurEulerCromer::clone() const {

    return new IntegrateurEulerCromer(*this);
}


IntegrateurNewmark* IntegrateurNewmark::clone() const{

    return new IntegrateurNewmark(*this);
}


void IntegrateurNewmark::integre(Integrable& integrable, double const& dt) const {

        /// Integre num�riquement selon la m�thode de Newmark


    Vecteur s ( integrable.equEvol(m_t) ) ;

    Vecteur P_nmoins1 ( integrable.getParam() ) ;

    Vecteur Ppoint_nmoins1 ( integrable.getVitesse() ) ;


    Vecteur distance({0,0,0});

    do {


        Vecteur q ( integrable.getParam() ) ;

        Vecteur r ( integrable.equEvol(m_t + dt) ) ;


        integrable.setVitesse( Ppoint_nmoins1 + dt/2 * (r + s) ) ;

        integrable.setParam( P_nmoins1 + dt * Ppoint_nmoins1 + dt*dt/3 * (1/2 * r + s) ) ;



        Vecteur distance = integrable.getParam() - q  ;


    } while ( distance.norme() >= EPSILON ) ;


}


void IntegrateurRK4::integre(Integrable& integrable, double const& dt) const {


        /// Integre num�riquement selon la m�thode Runge-Kutta 4





            // A faire �ventuellement plus tard




}

IntegrateurRK4* IntegrateurRK4::clone() const {

    return new IntegrateurRK4(*this);
}



