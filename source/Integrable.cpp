#include "../headers/Integrable.h"
#include "../headers/Vecteur.h"


Integrable::Integrable(Vecteur const& param, Vecteur const& vit)
    : m_P(param), m_Ppoint(vit)
{}

Integrable::~Integrable()
{
    //dtor
}



Vecteur Integrable::getParam() const{

    return m_P;
}

void Integrable::setParam(Vecteur const& newV){


    m_P = newV;
}




Vecteur Integrable::getVitesse() const{

    return m_Ppoint;
}


void Integrable::setVitesse(Vecteur const& newV){

    m_Ppoint = newV;
}

