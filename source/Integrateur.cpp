#include "../headers/Integrateur.h"
#include "../headers/Integrable.h"
#include "Toupie.cpp"
#include "Integrable.cpp"
#include <iostream>

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

        /// Intègre numériquement selon la méthode d'Euler Cromer


    integrable.setVitesse( integrable.getVitesse() + dt * integrable.equEvol(m_t) );

    integrable.setParam( integrable.getParam() + dt * integrable.getVitesse() );


}



void IntegrateurNewmark::integre(Integrable& integrable, double const& dt) const {

        /// Integre numériquement selon la méthode de Newmark


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


        /// Integre numériquement selon la méthode Runge-Kutta 4





            // A faire éventuellement plus tard




}



int main(){


    IntegrateurNewmark N(0.0);
    IntegrateurEulerCromer EC(0.0);

    double dt(0.1);

    Toupie toupie1;
    Toupie toupie2;


    std::cout << "Test Euleur-Cromer : " << std::endl;

     do {

        std::cout << "######################" << std::endl;
        std::cout << EC.getTemps() << std::endl;
        std::cout << toupie1.getParam() << "      parametre" << std::endl;
        std::cout << toupie1.getVitesse() << "     vitesse" << std::endl;
        EC.integre(toupie1, dt);
        EC.augmente_t(dt);

    } while ( EC.getTemps() <= 2 );


    std::cout << "########################" << std::endl;

    std::cout << "Test Newmark : " << std::endl;

     do {

        std::cout << "######################" << std::endl;
        std::cout << N.getTemps() << std::endl;
        std::cout << toupie2.getParam() << "      parametre" << std::endl;
        std::cout << toupie2.getVitesse() << "     vitesse" << std::endl;
        N.integre(toupie2, dt);
        N.augmente_t(dt);

    } while ( N.getTemps() <= 2 );


    return 0;

}
