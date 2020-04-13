#include "../headers/Systeme.h"


Systeme::Systeme(SupportADessin& support, Integrateur& I)
    : Dessinable(support), m_integrateur(I)
{}

Systeme::Systeme(Systeme const& S) : Dessinable(S), m_integrateur(*(S.m_integrateur.clone())) {

    /// Constructeur de copie, pointeurs obligent

    for (auto const& elt : S.m_corps){

        m_corps.push_back(elt->clone());
    }


}


Systeme& Systeme::operator=(Systeme const& S) {

    /// Opérateur d'affectation, pointeurs obligent

    if (this != &S){

        m_support = S.m_support;

        for (auto& elt : m_corps){
           delete elt;
    }

        for (auto const& elt : S.m_corps){

            m_corps.push_back(elt->clone());
        }


        m_integrateur = *(S.m_integrateur.clone());


    }


    return *this;
}


Systeme::~Systeme()
{
    for (auto& elt:m_corps) {

        // Gestion de la collection de pointeurs
        delete elt;
    }

}



void Systeme::addIntegrable(Integrable& I) {

    m_corps.push_back(I.clone());

    // On modifie le support de l'objet pour la cohérence du système
    m_corps.back()->changeSupport(m_support);
}




void Systeme::dessine() {

    m_support.dessine(*this);
}



Integrable* Systeme::getCorps(size_t k) const {

    /// Renvoie un pointeur sur la toupie en indice. En cas d'indice trop grand, renvoie nullptr

    if (k >= m_corps.size()){
        return nullptr;
    }

    return m_corps[k];
}


double Systeme::getTemps() const
{
    return m_integrateur.getTemps();
}



std::ostream& operator<<(std::ostream& sortie, Systeme& s){

    s.affiche(sortie);

    return sortie ;

}





void Systeme::affiche(std::ostream& sortie) {

    for (int k(0); k < m_corps.size() ; ++k) {

        sortie << "==== Toupie " << k+1 << " :" << std::endl;
        sortie << m_corps[k]->getType() << std::endl;

        sortie << "parametre                :  " << m_corps[k]->getParam() << std::endl;
        sortie << "vitesse                  :  " << m_corps[k]->getVitesse() << std::endl;

        m_corps[k]->statsCorps(sortie);

        sortie << std::endl;


    }


}





void Systeme::evolue(double const& dt) {

    for (auto& elt: m_corps){

        m_integrateur.integre(*elt , dt);

    }

    m_integrateur.augmente_t(dt);

}

unsigned int Systeme::getNbCorps() const {

    return m_corps.size();
}

Systeme* Systeme::clone() const {

    return new Systeme(*this);
}




