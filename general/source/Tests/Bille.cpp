#include "../../headers/Tests/Bille.h"
#include <cmath>



Bille::Bille(SupportADessin& S, Vecteur const& pos, Vecteur const& vit, double const& r)
        : Integrable( S, "Bille", pos, vit, pos, 0.0), m_rayon(r)
{
    setDistSecu();
}

Vecteur Bille::equEvol(double const& temps) {

    return g;

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


void Bille::setDistSecu() {

    double v0x(sqrt(m_Ppoint.getCoord(0)*m_Ppoint.getCoord(0)+m_Ppoint.getCoord(1)*m_Ppoint.getCoord(1)));

    double v0z(fabs(m_Ppoint.getCoord(2)));

    m_distSecu = v0x * (v0z + sqrt (v0z*v0z + 2 * g.norme() * m_P.getCoord(2)))/g.norme();

    m_distSecu += m_rayon;

}

double Bille::getRayon() const {

    return m_rayon;

}

Vecteur Bille::getPosition() const {

    // pour une bille, la position et le paramètre sont identiques, donc puisque seul le paramèrte change, on le retourne lui

    return m_P;

}

void Bille::setPosition(const Vecteur & V) {

    setParam(V);

}