#include "Tests/Bille.h"




Bille::Bille(double pos1, double pos2, double vit1, double vit2)
        : Integrable("Bille", Vecteur({pos1, pos2}), Vecteur({vit1, vit2}))
{}

Vecteur Bille::equEvol(double const& temps) const {

    return Vecteur({0,g.getCoord(2)});

}

Bille *Bille::clone() const {

    return new Bille(*this);
}

std::string Bille::getType() const{

    return m_type;

}

void Bille::dessine() {

    m_support.dessine(*this);
}





std::ostream& operator<<(std::ostream& flux, Bille const& B){

    flux << "Type : " << B.getType() << "  ; Parametre : " << B.getParam() << "  ;  Vitesse : " << B.getVitesse() << std::endl;
    return flux;
}