#include "../headers/Systeme.h"


Systeme::Systeme(SupportADessin *support, Integrateur* I)
    : Dessinable(support), m_integrateur(I)
{}

Systeme::Systeme(Systeme const& S) : Dessinable(S) {

    /// Constructeur de copie, pointeurs obligent

    for (auto const& elt : S.m_toupies){

        m_toupies.push_back(elt->clone());
    }

    m_integrateur = S.m_integrateur->clone();

}



Systeme& Systeme::operator=(Systeme const& S) {

    /// Opérateur d'affectation, pointeurs obligent

    if (this != &S){

        Dessinable::operator=(S);

        for (auto& elt : m_toupies){
           delete elt;
    }

        for (auto const& elt : S.m_toupies){

            m_toupies.push_back(elt->clone());
        }

        delete m_integrateur;
        m_integrateur = S.m_integrateur->clone();


    }


    return *this;
}


Systeme::~Systeme()
{
    for (auto& elt:m_toupies) {

        // Gestion de la collection de pointeurs
        delete elt;
    }

    delete m_integrateur;
}




void Systeme::dessine() {

    m_support->dessine(*this);
}



Toupie * Systeme::getToupie(size_t k) const {

    /// Renvoie un pointeur sur la toupie en indice. En cas d'indice trop grand, renvoie nullptr

    if (k >= m_toupies.size()){
        return nullptr;
    }

    return m_toupies[k];
}


double Systeme::getTemps() const
{
    return m_integrateur->getTemps();
}


std::ostream& operator<<(std::ostream& sortie, Systeme& s){

    s.affiche(sortie);

    return sortie ;

}





void Systeme::affiche(std::ostream& sortie) {

    for (int k(0); k < m_toupies.size() ; ++k) {

        sortie << "==== Toupie " << k << " :" << std::endl;
        sortie << m_toupies[k]->getType() << std::endl;

        sortie << "parametre                :  " << m_toupies[k]->getParam() << std::endl;
        sortie << "vitesse                  :  " << m_toupies[k]->getVitesse() << std::endl;

        m_toupies[k]->statsToupie(sortie);

        sortie << std::endl;


    }


}





void Systeme::evolue(double const& dt) {

    for (auto& elt: m_toupies){

        m_integrateur->integre(*elt , dt);

    }

    m_integrateur->augmente_t(dt);

}

unsigned int Systeme::getNbToupies() const {

    return m_toupies.size();
}


