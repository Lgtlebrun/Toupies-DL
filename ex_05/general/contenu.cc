#include "contenu.h"

// ======================================================================
void Contenu::evolue(double dt)
{
  constexpr double omega(100.0);
  angle += omega * dt;
}

Contenu* Contenu::clone() const{

    return new Contenu(*this);
}


std::ostream& operator<<(std::ostream& flux, Contenu const& c){

    flux << c.getAngle();
    return flux;
}
