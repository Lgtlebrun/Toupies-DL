#include "Toupie.h"
#include "Vecteur.cpp"

Toupie::Toupie()
{
    //ctor
}

Toupie::~Toupie()
{
    //dtor
}


Vecteur Toupie::equEvol(double const& temps) const{


    return -m_P;
}




Vecteur Toupie::getParam() const{

    return m_P;
}

void Toupie::setParam(Vecteur const& newV){


    m_P = newV;
}




Vecteur Toupie::getVitesse() const{

    return m_Ppoint;
}


void Toupie::setVitesse(Vecteur const& newV){

    m_Ppoint = newV;
}






