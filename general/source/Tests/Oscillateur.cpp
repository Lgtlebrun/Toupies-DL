#include "../../headers/Tests/Oscillateur.h"
#include <cmath>

Oscillateur::Oscillateur(SupportADessin& S, Vecteur const & param, Vecteur const & vit, Vecteur const& Centre_du_mvt, double const& r)
 /* L'amplitude du mouvement dépend du centre du mouvement, que nous décidons de passer en paramètre. Tous les vecteur *
  * sont de dimension 3. Le raisonnement pour setDistSecu() est le même que pour Bille.cpp */
        : Integrable(S, "Oscillateur harmonique", param, vit, param, 0.0), m_centreMVT(Centre_du_mvt), m_rayon(r)
{
    setDistSecu();
}


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
    flux << "Type : " << OH.getType() << "  ; Parametre : " << OH.getParam() << "  ;  Vitesse : " << OH.getVitesse() << std::endl;
    return flux;
}


std::string Oscillateur::getType() const{
/* renvoie le type de l'oscillateur */
    return m_type;

}
// ================================================================================================

double Oscillateur::getRayon() const {

    return m_rayon;

}


void Oscillateur::setDistSecu() {
/* Fixe automatiquement la distance de sécurité selon les caractéristiques de l'oscillateur à un instant donné.    *
 * C'est une estimation selon le cas unidimentionnel où la solution est du style (x=r+r0) si r''=-r est l'equation *
 * alors la soluion est x(t)=A*cos(t)+B*sin(t). Or l'équation différentielle est indépendante du temps, donc       *
 * nous pouvons facilement dire que pour tout temps, t=0, alors on a x(t)=x0*cos(t)+v0*sin(t). Nous cherchons      *
 * alors le maximum de l'amplitude de la trajectoire, d'où viennent les expressions ci-dessous. Nous ajoutons le   *
 * rayon à la toute fin pour empêcher un chevauchement                                                            */

    if ((m_P-m_centreMVT).norme() <= PREC and m_Ppoint.norme() <= PREC) {
            // l'objet ne possède ni vitesse ni de distance à la position d'équilibre, il est donc au repos
            // il n'y a donc aucune distance de sécurité nécessaire
        m_distSecu = 0.0;

    }

    if ((m_P-m_centreMVT).norme() > PREC) {

        m_distSecu = (m_P-m_centreMVT).norme() * cos(atan(m_Ppoint.norme()/(m_P-m_centreMVT).norme())) + m_Ppoint.norme() * sin(atan(m_Ppoint.norme()/(m_P-m_centreMVT).norme()));


    }

    if (m_Ppoint.norme() > PREC ) {

        m_distSecu = (m_P-m_centreMVT).norme() * cos(M_PI/2 - atan((m_P-m_centreMVT).norme()/m_Ppoint.norme())) + m_Ppoint.norme() * sin(M_PI/2 - atan((m_P-m_centreMVT).norme()/m_Ppoint.norme()));

    }

    m_distSecu += m_rayon;

}


Vecteur Oscillateur::getPosition() const {
/* Pour un oscillateur, la position est identique au paramètre */
    return getParam();

}

void Oscillateur::setPosition(Vecteur const& V) {

    setParam(V);

}