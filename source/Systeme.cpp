#include "../headers/Systeme.h"


Systeme::Systeme(SupportADessin *support, IntegrateurNewmark* I)
    : Dessinable(support), m_integrateur(I)
{}

Systeme::Systeme(SupportADessin *support, IntegrateurEulerCromer* I)
        : Dessinable(support), m_integrateur(I)
{}

Systeme::Systeme(SupportADessin *support, IntegrateurRK4* I)
        : Dessinable(support), m_integrateur(I)
{}

Systeme::~Systeme()
{
    for (auto& elt:m_toupies) {

        // Gestion de la collection de pointeurs
        delete elt;
    }
}


void Systeme::dessine() {

    m_support->dessine(*this);
}

Toupie * Systeme::getToupie(const int& k, bool& ilEnReste) const {

    if (k < m_toupies.size()) {

        if (k+1 == m_toupies.size()){

            ilEnReste = false;
            return m_toupies[k];

        }

        ilEnReste = true;
        return m_toupies[k];

    }

    ilEnReste = false;
    return m_toupies[0];

}


std::ostream& operator<<(std::ostream& sortie, Systeme& s){

    s.affiche(sortie);

    return sortie ;

}


void Systeme::affiche(std::ostream& sortie) {

    for (int k(0); k < m_toupies.size() ; ++k) {

        sortie << "==== Toupie " << k << " :" << std::endl;
        sortie << m_toupies[k]->typeToupie() << std::endl;

        sortie << "parametre                :  " << m_toupies[k]->getParam() << std::endl;
        sortie << "vitesse                  :  " << m_toupies[k]->getVitesse() << std::endl;

        m_toupies[k]->statsToupie(sortie);

        sortie << std::endl;


    }


}


void Systeme::evolue(double const& dt) {

    for (auto& elt: m_toupies){

        m_integrateur->integre(*elt , dt);
        m_integrateur->augmente_t(dt);

    }

}
