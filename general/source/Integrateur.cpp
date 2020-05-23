#include "../headers/Integrateur.h"


    /* ctor de base, ne nécessitant qu'un temps initial pour commencer à résoudre l'équation différentielle */

IntegrateurNewmark::IntegrateurNewmark(double const& t0)
    : Integrateur(t0)
{}

IntegrateurEulerCromer::IntegrateurEulerCromer(double const& t0)
    : Integrateur(t0)
{}

IntegrateurRK4::IntegrateurRK4(double const& t0)
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

    integrable.setPpoint(integrable.getPpoint() + dt * integrable.equEvol());
    integrable.setParam( integrable.getParam() + dt * integrable.getPpoint() );

}


void IntegrateurNewmark::integre(Integrable& integrable, double const& dt) const {
/* Intègre numériquement selon la méthode de Newmark */

    Vecteur s ( integrable.equEvol() ) ;

    Vecteur P_nmoins1 ( integrable.getParam() ) ;

    Vecteur Ppoint_nmoins1 ( integrable.getPpoint() ) ;

    Vecteur distance;

    do {


        Vecteur q(integrable.getParam());

        Vecteur r(integrable.equEvol());

        integrable.setPpoint(Ppoint_nmoins1 + dt / 2.0 * (r + s)) ;

        integrable.setParam( P_nmoins1 + dt * Ppoint_nmoins1 + dt*dt/3.0 * (1.0/2 * r + s) ) ;

        distance = integrable.getParam() - q;

    } while ( distance.norme() >= EPSILON ) ;


}


void IntegrateurRK4::integre(Integrable& integrable, double const& dt) const {
/* Intègre numériquement selon la méthode Runge-Kutta 4 */


    Vecteur k1_(integrable.equEvol());
        // Si on le met avant tout, c'est car c'est un artifice de calcul

    Vecteur Pnmoins1(integrable.getParam());
    Vecteur Ppnmoins1(integrable.getPpoint());


    Vecteur k1(Ppnmoins1);



    Vecteur k2(Ppnmoins1+dt/2*k1_);
    integrable.setParam(Pnmoins1+dt/2*k1);
    integrable.setPpoint(Ppnmoins1+dt/2*k1_);
    Vecteur k2_(integrable.equEvol());


    Vecteur k3(Ppnmoins1+dt/2*k2_);
    integrable.setParam(Pnmoins1+dt/2*k2);
    integrable.setPpoint(Ppnmoins1+dt/2*k2_);
    Vecteur k3_(integrable.equEvol());


    Vecteur k4(Ppnmoins1+dt*k3_);
    integrable.setParam(Pnmoins1+dt*k3);
    integrable.setPpoint(Ppnmoins1+dt*k3_);
    Vecteur k4_(integrable.equEvol());


    integrable.setParam(Pnmoins1+dt/6*(k1+2*k2+2*k3+k4));
    integrable.setPpoint(Ppnmoins1+dt/6*(k1_+2*k2_+2*k3_+k4_));

}
