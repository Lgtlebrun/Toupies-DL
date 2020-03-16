#include "Integrateur.h"
#include "Toupie.cpp"



void IntegrateurEulerCromer::integre(Toupie& toupie, double const& dt) const {

        /// Intègre numériquement selon la méthode d'Euler Cromer


    toupie.setVitesse( toupie.getVitesse() + dt * f(m_t, toupie.getParametre(), toupie.getVitesse()) );

    toupie.setParametre( toupie.getParametre() + dt * toupie.getVitesse() );


}
