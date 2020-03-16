#include "Integrateur.h"
#include "Toupie.cpp"



void IntegrateurEulerCromer::integre(Toupie& toupie, double const& dt) const {

        /// Int�gre num�riquement selon la m�thode d'Euler Cromer


    toupie.setVitesse( toupie.getVitesse() + dt * f(m_t, toupie.getParametre(), toupie.getVitesse()) );

    toupie.setParametre( toupie.getParametre() + dt * toupie.getVitesse() );


}
