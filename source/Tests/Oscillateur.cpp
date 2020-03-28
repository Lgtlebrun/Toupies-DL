#include "Tests/Oscillateur.h"

Oscillateur::Oscillateur(Vecteur const & param, Vecteur const & vit)
        : Integrable(param, vit)
{}

Vecteur Oscillateur::equEvol(double const &temps) const {

    return -m_P;

}