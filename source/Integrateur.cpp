#include "../headers/Integrateur.h"
#include "../headers/Toupie.h"
#include "Toupie.cpp"
#include "Integrable.cpp"
#include "Vecteur.cpp"
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


    IntegrateurNewmark N1(0.0);
    IntegrateurEulerCromer EC1(0.0);

    double dt(0.1);

    Bille bille1({0,0,0}, {10,0,10});
    Bille bille2({0,0,0}, {10,0,10});


    std::cout << "Test Euleur-Cromer bille: " << std::endl;

     do {

        std::cout << "######################" << std::endl;
        std::cout << EC1.getTemps() << std::endl;
        std::cout << bille1.getParam() << "      parametre" << std::endl;
        std::cout << bille1.getVitesse() << "     vitesse" << std::endl;
        EC1.integre(bille1, dt);
        EC1.augmente_t(dt);

    } while ( EC1.getTemps() <= 2 );


    std::cout << "########################" << std::endl;

    std::cout << "Test Newmark bille: " << std::endl;

     do {

        std::cout << "######################" << std::endl;
        std::cout << N1.getTemps() << std::endl;
        std::cout << bille2.getParam() << "      parametre" << std::endl;
        std::cout << bille2.getVitesse() << "     vitesse" << std::endl;
        N1.integre(bille2, dt);
        N1.augmente_t(dt);

    } while ( N1.getTemps() <= 2 );



    IntegrateurNewmark N2(0.0);
    IntegrateurEulerCromer EC2(0.0);

    OH oh1({1,0,0}, {0,1,0});
    OH oh2({1,0,0}, {0,1,0});


    std::cout << "Test Euleur-Cromer OH : " << std::endl;

     do {

        std::cout << "######################" << std::endl;
        std::cout << EC2.getTemps() << std::endl;
        std::cout << bille1.getParam() << "      parametre" << std::endl;
        std::cout << bille1.getVitesse() << "     vitesse" << std::endl;
        EC2.integre(bille1, dt);
        EC2.augmente_t(dt);

    } while ( EC2.getTemps() <= 2 );


    std::cout << "########################" << std::endl;

    std::cout << "Test Newmark bille: " << std::endl;

     do {

        std::cout << "######################" << std::endl;
        std::cout << N2.getTemps() << std::endl;
        std::cout << bille2.getParam() << "      parametre" << std::endl;
        std::cout << bille2.getVitesse() << "     vitesse" << std::endl;
        N2.integre(bille2, dt);
        N2.augmente_t(dt);

    } while ( N2.getTemps() <= 2 );


    std::cout << "######## FIN DES TESTS #########" << std::endl;


    return 0;

}
