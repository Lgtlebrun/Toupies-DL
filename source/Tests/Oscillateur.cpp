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
