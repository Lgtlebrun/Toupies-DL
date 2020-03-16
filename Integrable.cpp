#include "Integrable.h"

Integrable::Integrable()
{
    //ctor
}

Integrable::~Integrable()
{
    //dtor
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

