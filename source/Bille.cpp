#include "../headers/Bille.h"
#include "../headers/Integrable.h"


Bille::Bille(Vecteur const& pos, Vecteur const& vit)
        : Integrable(pos, vit)
{}


Vecteur Bille::equEvol(double const& temps) const {

    return {0,0,-9.81};

}