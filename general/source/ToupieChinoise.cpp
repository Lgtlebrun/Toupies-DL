#include "../headers/ToupieChinoise.h"
#include "../headers/Matrice3.h"
#include <cmath>


ToupieChinoise::ToupieChinoise(SupportADessin& sup, Vecteur const& param, Vecteur const& vit, Vecteur const& pos, double const& rayon, double const& hauteur, double const& masseVolumique)
    :Toupie(sup, "Cone simple", param, vit, pos, {0.0,0.0,0.0}, calculeIA1(rayon, hauteur, masseVolumique), calculeI3(rayon, hauteur, masseVolumique)
            , masseVolumique, masse(rayon, hauteur, masseVolumique), rayon-hauteur, 0.0), m_rayon(rayon), m_hauteur(hauteur)
{
    if (2*rayon < hauteur) {

        m_hauteur = 0;

    }
    m_d = calcule_d();
    setDistSecu();
}

ToupieChinoise::~ToupieChinoise() {

}

ToupieChinoise* ToupieChinoise::clone() const {

    return new ToupieChinoise(*this);
}

void ToupieChinoise::dessine() {
/* Explication détaillée dans Systeme::dessine() */
    m_support->dessine(*this);
}


Vecteur ToupieChinoise::equEvol(const double &temps) {

    Vecteur sortie;

    double I1(calculeI1());

    double alpha(3.0/4*m_hauteur*m_hauteur/(m_rayon*(m_rayon+m_hauteur)));

    double thetapp(m_Ppoint.getCoord(1)*(-m_masse*m_rayon*m_rayon*(alpha-cos(m_P.getCoord(0)))*(1-alpha*cos(m_P.getCoord(0)))+I1*cos(m_P.getCoord(0))));
    thetapp += f1()*m_Ppoint.getCoord(1)*(m_masse*m_rayon*m_rayon*(alpha*cos(m_P.getCoord(0))-1)-m_I3)-m_masse*m_rayon*m_rayon*m_Ppoint.getCoord(0)*m_Ppoint.getCoord(0)-alpha
            - m_masse*m_rayon*alpha*g.norme();
    thetapp *= sin(m_P.getCoord(0))/(m_I3+m_masse*m_rayon*m_rayon*(pow((alpha-cos(m_P.getCoord(0))),2)+pow(sin(m_P.getCoord(0)),2)));

    sortie.setCoord(0, thetapp);


    sortie.setCoord(1, f2());


    double phipp(m_Ppoint.getCoord(0)*m_Ppoint.getCoord(1)*sin(m_P.getCoord(0))-cos(m_P.getCoord(0))*f2()-f1()*m_Ppoint.getCoord(0)*sin(m_P.getCoord(0))
                    *m_masse*m_rayon*m_rayon*(m_I3*(alpha-cos(m_P.getCoord(0)))+I1*cos(m_P.getCoord(0)))/f3());


    sortie.setCoord(2, phipp);


    return sortie;

}


// ===================================================================================================

void ToupieChinoise::statsCorps(std::ostream& sortie) const {

    sortie << "masse [kg]               :  " << m_masse << std::endl;
    sortie << "masse volumique [kg m-3] :  " << m_masseVolumique << std::endl;
    double d(calcule_d());
    sortie << "distance [m]             :  " << d << std::endl;

    sortie << "rayon [m]                :  " << m_rayon << std::endl;
    sortie << "hauteur [m]              :  " << m_hauteur << std::endl;

    Vecteur pos({m_P.getCoord(3), m_P.getCoord(4), 0.0});

    sortie << "position (x,y,z) [m]     :  " << pos << std::endl;

}

std::ostream& operator<<(std::ostream& flux, ToupieChinoise const& C){
/* Affichage générique via la surchage de l'opérateur << */
    flux << "Type : " << C.getType() << "  ; Parametre : " << C.getParam() << "  ;  Vitesse : " << C.getPpoint()
         << "  ; Rayon : " << C.getRayon() << "  ; Hauteur : " << C.getHauteur() << std::endl;

    return flux;
}

void ToupieChinoise::setDistSecu() {

    m_distSecu = m_rayon;

}

// ======================================================================================================

double ToupieChinoise::calcule_d() const {

    Matrice3 passage(S());

    Vecteur e_z({0.0,0.0,1.0});
    Vecteur e_theta({0.0,1.0,0.0});

    Vecteur v (m_rayon*passage.inv()*e_z - 3.0/4.0*m_hauteur*m_hauteur/(m_rayon+m_hauteur)*e_theta);

    return v.norme();

}


double ToupieChinoise::calculeI3(const double & rayon, const double & hauteur, const double & masseVolumique) const {

    return M_PI/30*masseVolumique*pow(2*rayon-hauteur, 3)*(2*rayon*rayon+3*hauteur*rayon+3*rayon*rayon);

}


double ToupieChinoise::calculeIA1(const double & rayon, const double & hauteur, const double & masseVolumique) const {

    double d(calcule_d());

    double integ_z(M_PI/15*masseVolumique*pow(2*rayon-hauteur, 2)*(pow(rayon,3)+hauteur*pow(rayon, 2)-3*pow(hauteur,2)*rayon+3*pow(hauteur,3)));

    return 1.0/2*-m_I3+integ_z-m_masse*9.0/16.0*hauteur*hauteur/pow(rayon+hauteur, 2)+m_masse*d*d;

}

double ToupieChinoise::calculeI1() {

    m_d = calcule_d();

    calculeIA1(m_rayon, m_hauteur, m_masseVolumique);

    return m_IA1-m_masse*m_d*m_d;

}


double ToupieChinoise::masse(const double&  rayon, const double&  hauteur, const double & masseVolumique) const {

    return M_PI*masseVolumique*(4.0/3*pow(rayon, 3)-hauteur*hauteur*(rayon-1.0/3*hauteur));

}


double ToupieChinoise::getRayon() const {

    return m_rayon;

}

double ToupieChinoise::getHauteur() const {

    return m_hauteur;

}
// ==========================================================================

double ToupieChinoise::f1() {

    return m_Ppoint.getCoord(2) + m_Ppoint.getCoord(1)*cos(m_P.getCoord(0));

}

double ToupieChinoise::f2() {

    if (sin(m_P.getCoord(0)) < PREC) { return 0.0; }
    if (f3() < PREC) { return 0.0; }
    return m_Ppoint.getCoord(0)/sin(m_P.getCoord(0))*f1()*(m_I3*(m_I3+m_masse*m_rayon
    *m_rayon*(1-3.0/4*m_hauteur*m_hauteur/m_rayon/(m_rayon+m_hauteur))))/f3()-2*
    m_Ppoint.getCoord(0)*m_Ppoint.getCoord(1)*tan(M_PI/2-m_P.getCoord(0));

}

double ToupieChinoise::f3() {

    double I1(calculeI1());

    return m_I3*I1+m_masse*m_rayon*m_rayon*I1*pow(sin(m_P.getCoord(0)), 2)
    + m_masse*m_rayon*m_rayon*m_I3*pow(3.0/4*m_hauteur*m_hauteur/m_rayon/(m_rayon+m_hauteur), 2);


}











