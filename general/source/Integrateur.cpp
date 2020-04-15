#include "../headers/Integrateur.h"


    /* ctor de base, ne nécessitant qu'un temps initial pour commencer à résoudre l'équation différentielle */

IntegrateurNewmark::IntegrateurNewmark(double const& t0)
    : Integrateur(t0)
{}

IntegrateurEulerCromer::IntegrateurEulerCromer(double const& t0)
    : Integrateur(t0)
{}

// =================================================================================================

IntegrateurEulerCromer* IntegrateurEulerCromer::clone() const {
/* Méthode de clonage de l'intégrateur Euler-Cromer */
    return new IntegrateurEulerCromer(*this);
}

IntegrateurNewmark* IntegrateurNewmark::clone() const{
/* Méthode de clonage de l'intégrateur de Newmark */
    return new IntegrateurNewmark(*this);
}

IntegrateurRK4* IntegrateurRK4::clone() const {
/* Méthode de clonage de l'intégrateur RK4 */
    return new IntegrateurRK4(*this);
}

// ================================================================================================

    /* Getteur et Setteur des intégrateurs */

 void Integrateur::augmente_t(double const& dt) {
/* On ne laisse pas le choix à l'utilisateur d'augmenter le temps n'importe comment car le but est de trouver une *
 * solution à une équation différentielle                                                                        */
    m_t += dt ;

}

double Integrateur::getTemps() const {

    return m_t;

}

// ===============================================================================================

void IntegrateurEulerCromer::integre(Integrable& integrable, double const& dt) const {
/* Intègre numériquement selon la méthode d'Euler Cromer */
    integrable.setVitesse( integrable.getVitesse() + dt * integrable.equEvol(m_t) );
    integrable.setParam( integrable.getParam() + dt * integrable.getVitesse() );

}
void IntegrateurNewmark::integre(Integrable& integrable, double const& dt) const {
/* Intègre numériquement selon la méthode de Newmark */
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
/* Intègre numériquement selon la méthode Runge-Kutta 4 */





            // A faire éventuellement plus tard




}
