#include "../../headers/Tests/Oscillateur.h"
#include <cmath>

Oscillateur::Oscillateur(SupportADessin& S, Vecteur const & param, Vecteur const & vit, Vecteur const& Centre_du_mvt, double const& r)
        : Integrable(S, "Oscillateur harmonique", param, vit, 0.0), m_centreMVT(Centre_du_mvt), m_rayon(r)
{
    setDistSecu();
}

Vecteur Oscillateur::equEvol(double const &temps) {

    return -(m_P-m_centreMVT);

}

Oscillateur *Oscillateur::clone() const {

    return new Oscillateur(*this);
}

std::string Oscillateur::getType() const{

    return m_type;

}

void Oscillateur::dessine() {

    m_support.dessine(*this);
}




std::ostream& operator<<(std::ostream& flux, Oscillateur const& OH){

    flux << "Type : " << OH.getType() << "  ; Parametre : " << OH.getParam() << "  ;  Vitesse : " << OH.getVitesse() << std::endl;
    return flux;
}


void Oscillateur::setDistSecu() {

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