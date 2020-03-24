#include "../headers/Integrable.h"

Integrable::Integrable()
{
    //ctor
}

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

