#include "../../headers/Tests/Oscillateur.h"
#include <cmath>

Oscillateur::Oscillateur(SupportADessin& S, Vecteur const & param, Vecteur const & vit, Vecteur const& Centre_du_mvt, double const& r)
 /* L'amplitude du mouvement dépend du centre du mouvement, que nous décidons de passer en paramètre. Tous les vecteur *
  * sont de dimension 3. Le raisonnement pour setDistSecu() est le même que pour Bille.cpp */
        : Integrable(S, "Oscillateur harmonique", param, vit), m_centreMVT(Centre_du_mvt), m_rayon(r)
{}


Vecteur Oscillateur::equEvol(double const &temps) {
/* Cette expression permet un mouvement harmonique en 3D centrée en m_centreMVT */
    return -(m_P-m_centreMVT);

}


Oscillateur *Oscillateur::clone() const {
/* méthode de clonage */
    return new Oscillateur(*this);
}


void Oscillateur::dessine() {
/* Expliqué plus amplement dans Systeme::dessine() */
    m_support->dessine(*this);
}


std::ostream& operator<<(std::ostream& flux, Oscillateur const& OH){
/* Surcharge de l'oppérateur << */
    flux << "Type : " << OH.getType() << "  ; Parametre : " << OH.getParam() << "  ;  Vitesse : " << OH.getPpoint() << std::endl;
    return flux;
}


void Oscillateur::statsCorps(std::ostream &sortie) {

    sortie << "parametre                :  " << getParam() << std::endl;
    sortie << "vitesse                  :  " << getPpoint() << std::endl;

}


std::string Oscillateur::getType() const{
/* renvoie le type de l'oscillateur */
    return m_type;

}
// ================================================================================================

double Oscillateur::getRayon() const {

    return m_rayon;

}

Vecteur Oscillateur::getPosition() const {

    return m_centreMVT;

}

void Oscillateur::setPosition(Vecteur const & newV) {

    m_centreMVT = newV;

}
