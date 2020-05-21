#include "../headers/ToupieChinoise.h"
#include <cmath>


ToupieChinoise::ToupieChinoise(SupportADessin& sup, Vecteur const& angles, Vecteur const& anglesp, Vecteur const& posA, double const& rayon, double const& hauteur, double const& masseVolumique)
/* Nous pouvons calculer les moments d'inertie selon différents axes à base d'uniquement la masse volumique, le rayon *
 * et la hauteur du cône.                                                                                            */
    :Toupie(sup, "Toupie Chinoise", angles, anglesp, posA, 0.0, 0.0
     , 0.0,rayon-hauteur), m_masseVolumique(fabs(masseVolumique)), m_rayon(fabs(rayon)), m_hauteur(fabs(hauteur))
{
    if (2*m_rayon < m_hauteur) {

        m_hauteur = 0;

    }
    m_d = calcule_d();

    m_masse = masse(m_rayon, m_hauteur, m_masseVolumique);

    m_I3 = calculeI3(m_rayon, m_hauteur, m_masseVolumique);

    m_IA1 = calculeIA1(m_rayon, m_hauteur, m_masseVolumique);

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
/* Equations d'évolution tirées de §6.2 */


    Vecteur sortie({0.0,0.0,0.0,0.0,0.0,0.0});

    m_P = modulo2Pi();
    /* On remet le paramètre modulo 2PI pour éviter la divergence des fonctions trigonométriques */

    double I1(calculeI1());

    double alpha(3.0/4*m_hauteur*m_hauteur/(m_rayon*(m_rayon+m_hauteur)));

    double thetapp(sin(m_P.getCoord(0))/(I1+m_masse*m_rayon*m_rayon*(alpha-cos(m_P.getCoord(0))*(alpha-cos(m_P.getCoord(0)))+sin(m_P.getCoord(0)*sin(m_P.getCoord(0)))))
                    *(m_Ppoint.getCoord(1)*m_Ppoint.getCoord(1)*(-m_masse*m_rayon*m_rayon*(alpha-cos(m_P.getCoord(0)))*(1-alpha*cos(m_P.getCoord(0)))+I1*cos(m_P.getCoord(0)))
                    + f1()*m_Ppoint.getCoord(1)*(m_masse*m_rayon*m_rayon*(alpha*cos(m_P.getCoord(0))-1)-m_I3)-m_masse*m_rayon*m_rayon*m_Ppoint.getCoord(0)*m_Ppoint.getCoord(0)*alpha
                    - m_masse*m_rayon*alpha*g.norme()));

    sortie.setCoord(0, thetapp);


    sortie.setCoord(1, f2());


    double phipp(m_Ppoint.getCoord(0)*m_Ppoint.getCoord(1)*sin(m_P.getCoord(0))-cos(m_P.getCoord(0))*f2()-f1()*m_Ppoint.getCoord(0)*sin(m_P.getCoord(0))
                    *m_masse*m_rayon*m_rayon*(m_I3*(alpha-cos(m_P.getCoord(0)))+I1*cos(m_P.getCoord(0)))/f3());


    sortie.setCoord(2, phipp);

    sortie.setCoord(3, m_rayon*(m_Ppoint.getCoord(0)*sin(m_P.getCoord(1))
                    - m_Ppoint.getCoord(2)*cos(m_P.getCoord(1))*sin(m_P.getCoord(0)) ));

    sortie.setCoord(4, -m_rayon*(m_Ppoint.getCoord(0)*cos(m_P.getCoord(1))
                    + m_Ppoint.getCoord(2)*sin(m_P.getCoord(1))*sin(m_P.getCoord(0))));


    return sortie;

}


// ===================================================================================================

void ToupieChinoise::statsCorps(std::ostream& sortie) {
/* Affiche en détail les caractéristiques d'une ToupieChinoise */
    sortie << "parametre                :  " << getParam() << std::endl;
    sortie << "vitesse                  :  " << getPpoint() << std::endl;

    sortie << "masse [kg]               :  " << m_masse << std::endl;
    sortie << "masse volumique [kg m-3] :  " << m_masseVolumique << std::endl;
    sortie << "distance [m]             :  " << calcule_d() << std::endl;

    sortie << "rayon [m]                :  " << m_rayon << std::endl;
    sortie << "hauteur [m]              :  " << m_hauteur << std::endl;

    sortie << "position (x,y,z) [m]     :  " << getPosition() << std::endl;
    sortie << "Vitesse (x,y,z) [m s-1]  :  " << getVitesse() << std::endl;

}

std::ostream& operator<<(std::ostream& flux, ToupieChinoise const& C){
/* Affichage générique via la surchage de l'opérateur << */
    flux << "Type : " << C.getType() << "  ; Angles : " << C.getAngles() << "  ;  Derivées : " << C.getAnglesp()
        << "  ; Position : " << C.getPosition() << "  ; Energie : " << C.Energie() << "  ; L_a : " << C.L_a()
        << "  ; L_K : " << C.L_k() << "  ; det[omega, L, a ] : " << C.ProdMixte() << std::endl;

    return flux;
}

// ======================================================================================================

    /* Calcul de beaucoup de grandeurs physiques de la toupie, selon des formules trouvées dans le *
     * complément mathématique                                                                     */


double ToupieChinoise::calcule_d() const {
/* Calcul de la distance séparant de centre de masse du point de contact avec le sol */

    Vecteur e_z({0.0,0.0,1.0});
    Vecteur e_theta({0.0,0.0,1.0});

    Vecteur v (m_rayon*S()*e_z - 3.0/4.0*m_hauteur*m_hauteur/(m_rayon+m_hauteur)*e_theta);

    return v.norme();

}


double ToupieChinoise::calculeI3(const double & rayon, const double & hauteur, const double & masseVolumique) const {

    double r(fabs(rayon));
    double h(fabs(hauteur));
    double rho(fabs(masseVolumique));

    return M_PI/30*rho*pow(2*r-h, 3)*(2*r*r+3*h*r+3*h*h);

}


double ToupieChinoise::calculeIA1(const double & rayon, const double & hauteur, const double & masseVolumique) const {

    double d(calcule_d());

    double r(fabs(rayon));
    double h(fabs(hauteur));
    double rho(fabs(masseVolumique));

    double integ_z(M_PI/15*rho*pow(2*r-h, 2)*(pow(r,3)+h*pow(r, 2)-3*pow(h,2)*r+3*pow(h,3)));

    double alpha(3.0/4*h*h/(r*(r*h)));

    return 1.0/2*m_I3+integ_z-m_masse*r*r*alpha*alpha+m_masse*d*d;

}

double ToupieChinoise::calculeI1() const {

    double d(calcule_d());

    double IA1(calculeIA1(m_rayon, m_hauteur, m_masseVolumique));

    return IA1-m_masse*d*d;

}

Matrice3 ToupieChinoise::TenseurInertie() const {

    double I1(calculeI1());

    Vecteur PG(AG());

    Matrice3 I(I1, 0.0, 0.0
            , 0.0, I1, 0.0
            , 0.0, 0.0, m_I3);

    Matrice3 Delta( PG*PG, 0.0, 0.0
                   , 0.0, PG*PG, 0.0
                   , 0.0, 0.0, PG*PG);

    Matrice3 PG_M( PG.getCoord(0), 0.0, 0.0
                  , PG.getCoord(1), 0.0, 0.0
                  , PG.getCoord(2), 0.0, 0.0);

    Delta -= PG_M*PG_M.transp();

    I += m_masse*Delta;

    return I;

}


double ToupieChinoise::masse(const double&  rayon, const double&  hauteur, const double & masseVolumique) const {

    double r(fabs(rayon));
    double h(fabs(hauteur));
    double rho(fabs(masseVolumique));

    return M_PI*rho*(4.0/3*pow(r, 3)-h*h*(r-1.0/3*h));

}

    // accesseur de rayon et hauteur

double ToupieChinoise::getRayon() const {

    return m_rayon;

}

double ToupieChinoise::getHauteur() const {

    return m_hauteur;

}
// ==========================================================================


    /* Méthodes qui servent au calcul de equEvol */

double ToupieChinoise::f1() {

    return m_Ppoint.getCoord(2) + m_Ppoint.getCoord(1)*cos(m_P.getCoord(0));

}

double ToupieChinoise::f2() {

    double alpha (3.0/4.0*m_hauteur*m_hauteur/(m_rayon*(m_rayon+m_hauteur)));

    if (fabs(sin(m_P.getCoord(0))) < PREC) { return 0.0; }
    if (fabs(f3()) < PREC) { return 0.0; }

    return m_Ppoint.getCoord(0)/sin(m_P.getCoord(0))*f1()*(m_I3*(m_I3+m_masse*m_rayon
    *m_rayon*(1-alpha*cos(m_P.getCoord(0)))))/f3()
    -2*m_Ppoint.getCoord(1)*m_Ppoint.getCoord(0)*cos(m_P.getCoord(0))/sin(m_P.getCoord(0));

}

double ToupieChinoise::f3() {

    double I1(calculeI1());

    return m_I3*I1+m_masse*m_rayon*m_rayon*I1*sin(m_P.getCoord(0))*sin(m_P.getCoord(0))
    + m_masse*m_rayon*m_rayon*m_I3*pow(3.0/4*m_hauteur*m_hauteur/(m_rayon*(m_rayon+m_hauteur))-cos(m_P.getCoord(0)), 2);


}

// =================================================================================================

Vecteur ToupieChinoise::getPosition() const {
/* Retourne le point de contact entre le sol et la toupie */
    Vecteur posA ({m_Ppoint.getCoord(3), m_Ppoint.getCoord(4), 0.0});

    Vecteur posG(posA+AG());

    return posG;


}

void ToupieChinoise::setPosition(const Vecteur & newV) {
/* Fixe le centre géométrique de la toupie */
    if (newV.getDim() >= 2) {

        m_Ppoint.setCoord(3, newV.getCoord(0));
        m_Ppoint.setCoord(4, newV.getCoord(1));
        m_Ppoint.setCoord(5, m_rayon);

    }

}

Vecteur ToupieChinoise::getVitesse() {
/* Renoit la vitesse de translation de la toupie, qui dépend de la rotation de celle-ci */

    Vecteur vitesse(equEvol(0.0));

    return {vitesse.getCoord(3) , vitesse.getCoord(4), 0.0};

}

Vecteur ToupieChinoise::AG() const {

    double alpha(3.0/4*m_hauteur*m_hauteur/(m_rayon*(m_rayon+m_hauteur)));

    return Vecteur({0.0, 0.0, m_rayon})+S().transp()*Vecteur({0.0, 0.0, -m_rayon*alpha});

}

