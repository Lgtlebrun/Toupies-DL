#include "../headers/Integrable.h"


Integrable::Integrable( SupportADessin& sup, std::string const& type, Vecteur const& param, Vecteur const& parampoint)
/* ctor de l'intégrable. Il lui faut un paramètre != position dans le cas général car paramètre représente un vector *
 * des coordonnées généralisées (pour une toupie, param = (théta, psy, phi) alors que pos = (x,y,z)). Il faut un     *
 * SupportADessin pour savoir où le représenter. En plus de cela, la distance de sécurité est là pour s'assurer que  *
 * deux intégrables ne se superposent pas en représentation visuelle                                                */
    : Dessinable(sup), m_P(param), m_Ppoint(parampoint), m_type(type)
{}

Integrable::~Integrable()
{
    //dtor
}

void Integrable::statsCorps(std::ostream& flux) const {
/* Méthode d'affichage permettant d'afficher tout ce qui pourrait être voulu par un programmeur */
    flux << m_type << ":    Paramètre : " << m_P << ", Dérivée : " << m_Ppoint << std::endl;

}

// ======================================================================================================

    /* Divers getteurs et setteurs de toutes les grandeurs que possède un Integrable */

Vecteur Integrable::getParam() const{

    return m_P;
}
void Integrable::setParam(Vecteur const& newV){

    m_P = newV;
}


Vecteur Integrable::getParametre() const {

    Vecteur v;
    v.setCoord(0, m_P.getCoord(0));
    v.setCoord(1, m_P.getCoord(1));
    v.setCoord(2, m_P.getCoord(2));

    return v;
}



Vecteur Integrable::getPpoint() const{

    return m_Ppoint;
}
void Integrable::setPpoint(Vecteur const& newV){

    m_Ppoint = newV;
}


std::string Integrable::getType() const{
/* Pas de set car le type est définit à la création de l'objet. Un cheval ne se transforme pas spontanément en lapin, *
 * peu importe à quel point nous le désirons ! */

    return m_type;

}


