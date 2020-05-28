#include "../../headers/Tests/Bille.h"
#include <cmath>



Bille::Bille(SupportADessin& S, Vecteur const& pos, Vecteur const& vit, double const& r)
/* ctor de la classe Bille, la position est justement le paramètre variable, donc ils sont confondus. De plus,  *
 * le launcher s'assure que r > 0. De plus, la distance de sécurité est dans les accolades pour permettre de ne *
 * pas prendre d'argument à la méthode, puisque setDistSecu() n'est dépendante que de l'objet et on ne veut pas *
 * qu'un utilisateur mal-intentionné fasse n'importe quoi. */
        : ObjetPhysique(S, "Bille", pos, vit), m_rayon(fabs(r))
{}


Bille *Bille::clone() const {
/* Méthode de clonage */
    return new Bille(*this);
}

// ============================================================================================

Vecteur Bille::equEvol() {
/* F = mg = ma => a(t)=equEvol(t)=g */

    return g;

}

// ============================================================================================

void Bille::dessine() {
/* Voir Systeme::dessine() pour des explications approfondies */
    m_support->dessine(*this);
}


std::ostream& operator<<(std::ostream& flux, Bille const& B){
/* surchage de l'opérteur << */
    flux << "Type : " << B.getType() << "  ; Parametre : " << B.getParam() << "  ;  Vitesse : " << B.getPpoint() << std::endl;
    return flux;
}

void Bille::statsCorps(std::ostream &sortie) {

    sortie << "parametre                :  " << getParam() << std::endl;
    sortie << "vitesse                  :  " << getPpoint() << std::endl;

}

// ===========================================================================================

std::string Bille::getType() const{

    return m_type;

}


double Bille::getRayon() const {

    return m_rayon;

}

double Bille::Energie() const {

    double masse(3.0/4*M_PI*pow(m_rayon, 3)*2.5);  // masse volumique du verre

    return 1.0/2*masse*(getVitesse()*getVitesse())-masse*(g.prodScalaire(getPosition()));

}

double Bille::L_k() const {

    double masse(3.0/4*M_PI*pow(m_rayon, 3)*2.5);

    return masse*((getPosition()^getVitesse()).prodScalaire({0.0,0.0,1.0}));

}

double Bille::L_a() const {

    return L_k();

}

double Bille::ProdMixte() const {

    return 0.0;

}
