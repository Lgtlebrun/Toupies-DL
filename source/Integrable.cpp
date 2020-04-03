#include "../headers/Integrable.h"


Integrable::Integrable(SupportADessin& sup, std::string const& type, Vecteur const& param, Vecteur const& vit)
    : Dessinable(sup), m_type(type), m_P(param), m_Ppoint(vit)
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

std::string Integrable::getType() const{

    return m_type;

}

Vecteur Integrable::getVitesse() const{

    return m_Ppoint;
}


void Integrable::setVitesse(Vecteur const& newV){

    m_Ppoint = newV;
}


void Integrable::statsCorps(std::ostream&) const{



}