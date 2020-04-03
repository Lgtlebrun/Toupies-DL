#include "Tests/Oscillateur.h"

Oscillateur::Oscillateur(Vecteur const & param, Vecteur const & vit)
        : Integrable("Oscillateur harmonique", param, vit)
{}

Vecteur Oscillateur::equEvol(double const &temps) const {

    return -m_P;

}

Oscillateur *Oscillateur::clone() const {

    return new Oscillateur(*this);
}

std::string Oscillateur::getType() const{

    return m_type;

}

void Oscillateur::dessine() {

    m_support.dessine(*this);
}




std::ostream& operator<<(std::ostream& flux, Oscillateur const& OH){

    flux << "Type : " << OH.getType() << "  ; Parametre : " << OH.getParam() << "  ;  Vitesse : " << OH.getVitesse() << std::endl;
    return flux;
}