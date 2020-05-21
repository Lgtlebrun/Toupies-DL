#include "../headers/ObjetPhysique.h"

ObjetPhysique::ObjetPhysique(SupportADessin &sup, const std::string &nom, const Vecteur &param, const Vecteur &Paramp)
    : Integrable(sup, nom, param, Paramp)
{}

ObjetPhysique::~ObjetPhysique() {}

Vecteur ObjetPhysique::getPosition() const {

    return m_P;

}
void ObjetPhysique::setPosition(Vecteur const& newP) {

    m_P = newP;

}

Vecteur ObjetPhysique::getVitesse() const {

    return m_Ppoint;

}
void ObjetPhysique::setVitesse(const Vecteur & newV) {

    m_Ppoint = newV;

}