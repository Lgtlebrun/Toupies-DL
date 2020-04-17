#include "../../headers/Tests/Bille.h"
#include <cmath>



Bille::Bille(SupportADessin& S, Vecteur const& pos, Vecteur const& vit, double const& r)
/* ctor de la classe Bille, la position est justement le paramètre variable, donc ils sont confondus. De plus,  *
 * le launcher s'assure que r > 0. De plus, la distance de sécurité est dans les accolades pour permettre de ne *
 * pas prendre d'argument à la méthode, puisque setDistSecu() n'est dépendante que de l'objet et on ne veut pas *
 * qu'un utilisateur mal-intentionné fasse n'importe quoi. */
        : Integrable(S, "Bille", pos, vit, pos, 0.0), m_rayon(r)
{
    setDistSecu();
}


Bille *Bille::clone() const {
/* Méthode de clonage */
    return new Bille(*this);
}

// ============================================================================================

Vecteur Bille::equEvol(double const& temps) {
/* F = mg = ma => a(t)=equEvol(t)=g */

    if (getParam().getCoord(2)< getRayon() and getVitesse().getCoord(2) < 0 ) {

        /* Rebondissement */
        setVitesse({getVitesse().getCoord(0)
                   , getVitesse().getCoord(1)
                   , - 0.6 * getVitesse().getCoord(2)});

        setPosition({getPosition().getCoord(0)
                    , getPosition().getCoord(1)
                    , getRayon()});


    }
    if (getParam().getCoord(2)<=getRayon() and fabs(getVitesse().getCoord(2)) < PREC ) {

        setVitesse({getVitesse().getCoord(0)
                           , getVitesse().getCoord(1)
                           , getRayon() });

        return {0.0,0.0,0.0};
    }

    return g;

}

// ============================================================================================

void Bille::dessine() {
/* Voir Systeme::dessine() pour des explications approfondies */
    m_support->dessine(*this);
}


std::ostream& operator<<(std::ostream& flux, Bille const& B){
/* surchage de l'opérteur << */
    flux << "Type : " << B.getType() << "  ; Parametre : " << B.getParam() << "  ;  Vitesse : " << B.getVitesse() << std::endl;
    return flux;
}

// ===========================================================================================

std::string Bille::getType() const{

    return m_type;

}


double Bille::getRayon() const {

    return m_rayon;

}


void Bille::setDistSecu() {
/* Nous faisons le choix arbitraire de dire que la bille ne doit pas rencontre d'autre objet avant l'altitude de 0m *
 * et ceci s'exprime mathématiquement comme si-dessous, avec l'ajout de la distance du rayon, puisque sinon, nous   *
 * pourrions imaginer faire une énorme bille qui, bien que statique, toucherait tous les intégrables alentours, ce  *
 * qui serait évidemment embêtant pour la visualisation*/
    double v0x(sqrt(m_Ppoint.getCoord(0)*m_Ppoint.getCoord(0)+m_Ppoint.getCoord(1)*m_Ppoint.getCoord(1)));

    double v0z(fabs(m_Ppoint.getCoord(2)));

    m_distSecu = v0x * (v0z + sqrt (v0z*v0z + 2 * g.norme() * m_P.getCoord(2)))/g.norme();

    m_distSecu += m_rayon;

}


Vecteur Bille::getPosition() const {
/*pour une bille, la position et le paramètre sont identiques, donc puisque seul le paramèrte change, on le retourne lui */
    return getParam();

}

void Bille::setPosition(const Vecteur & V) {

    setParam(V);

}
