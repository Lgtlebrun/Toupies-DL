#include "../../headers/Tests/Oscillateur.h"
#include <cmath>

Oscillateur::Oscillateur(SupportADessin& S, Vecteur const & param, Vecteur const & vit, Vecteur const& Centre_du_mvt, double const& r)
 /* L'amplitude du mouvement dépend du centre du mouvement, que nous décidons de passer en paramètre. Tous les vecteur *
  * sont de dimension 3. Le raisonnement pour setDistSecu() est le même que pour Bille.cpp */
        : ObjetPhysique(S, "Oscillateur harmonique", param, vit), m_centreMVT(Centre_du_mvt), m_rayon(fabs(r))
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

    while (m_centreMVT.getDim()<3) {m_centreMVT.concatene({0.0});}

}

// ==========================================================================================

    /* De la magie noire qui permet une expression plus ou moins arbitraire pour les grangeurs *
     * physiques qui sont sensées être conservées                                              */

double Oscillateur::Energie() const {
/* En regardant l'expression dans equEvol, nous pouvons dire que c'est une force, dérivant d'un potentiel. *
 * Nous évaluons le potentiel et l'énergie cinétique                                                      */

    return 1.0/2*(getParam()*getParam())-getParam()*getPosition()+1.0/2*(getPpoint()*getPpoint());


}

double Oscillateur::L_k() const {

    return ((getParam()-getPosition()).prodVectoriel(getPpoint()).prodScalaire(Vecteur({0.0,0.0,1.0})));

}

double Oscillateur::L_a() const {

    Vecteur L((getParam()-getPosition()).prodVectoriel(getPpoint()));

    return L.norme();

}

double Oscillateur::ProdMixte() const {

     return 0.0;

}
