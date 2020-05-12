#include "../headers/ObjetPhysique.h"

ObjetPhysique::ObjetPhysique(SupportADessin &sup, const std::string &nom, const Vecteur &param, const Vecteur &Paramp)
    : Integrable(sup, nom, param, Paramp)
{}

ObjetPhysique::~ObjetPhysique() {}