#include "../headers/ConeSimple.h"
#include <cmath>


ConeSimple::ConeSimple(SupportADessin& sup, Vecteur const& Angles, Vecteur const& AnglesPoint, Vecteur const& posA, double const& rayon, double const& hauteur, double const& masseVolumique)
/* Nous pouvons calculer les moments d'inertie selon différents axes à base d'uniquement la masse volumique, le rayon *
 * et la hauteur du cône.                                                                                            */
        : Toupie(sup, "Cone simple", Angles, AnglesPoint, posA, calculeIA1(rayon, hauteur, masseVolumique), calculeI3(rayon, hauteur, masseVolumique)
                , masse(rayon, hauteur, masseVolumique), 3.0/4.0*hauteur), m_rayon(fabs(rayon)), m_hauteur(fabs(hauteur)), m_masseVolumique(fabs(masseVolumique))
{}


ConeSimple::~ConeSimple() {

}


ConeSimple *ConeSimple::clone() const {
/* Méthode de clonage de ConeSimple */
    return new ConeSimple(*this);
}


void ConeSimple::dessine() {
/* Explication détaillée dans Systeme::dessine() */
    m_support->dessine(*this);
}


Vecteur ConeSimple::equEvol() {
/* Avec l'équation d'évolution en page 12 du complément mathématique, assumant donc distance centre de masse - *
 * point de contact = cste.                                                                                    */

    Vecteur sortie;                 // convention : (théta, psy, phi)
                                    // initialisation au vecteur nul

    m_P = modulo2Pi();
    /* On remet le paramètre modulo 2PI pour éviter la divergence des fonctions trigonométriques */

    if ( fabs(m_IA1) < PREC ) {

        return sortie;              // pas d'accélération de la rotation s'il n'y a rien à faire tourner !

    }
    if (fabs(sin(m_P.getCoord(0))) < PREC ) {

        return sortie;              /* si la toupie a un angle à la verticale nul, alors, vu qu'il n'y a aucun frottement,  *
                                     * la somme des force est nulle, entraînant une accélération nulle                       */

    }

    sortie.setCoord(0, 1.0/m_IA1*(m_masse*g.norme()*m_d*sin(m_P.getCoord(0))+m_Ppoint.getCoord(1)*sin(m_P.getCoord(0))
                                                                             * ((m_IA1-m_I3)*m_Ppoint.getCoord(1)*cos(m_P.getCoord(0))-m_I3*m_Ppoint.getCoord(2) )) ) ;

    sortie.setCoord(1, m_Ppoint.getCoord(0)/(m_IA1*sin(m_P.getCoord(0))) * ((m_I3-2*m_IA1)*m_Ppoint.getCoord(1)*cos(m_P.getCoord(0))
                                                                            + m_I3*m_Ppoint.getCoord(2) ) ) ;

    sortie.setCoord(2, m_Ppoint.getCoord(0)/(m_IA1*sin(m_P.getCoord(0))) * ( (m_IA1- (m_I3-m_IA1)*cos(m_P.getCoord(0))*cos(m_P.getCoord(0)) )
                                                                             *m_Ppoint.getCoord(1) - m_I3*m_Ppoint.getCoord(2)*cos(m_P.getCoord(0))) ) ;


    return sortie;


}


// ===================================================================================================

void ConeSimple::statsCorps(std::ostream& sortie) const{
/* Affiche en détail les caractéristiques du ConeSimple */
    sortie << "Angles                   :  " << getAngles() << std::endl;
    sortie << "Vitesse Angulaire        :  " << getAnglesp() << std::endl;

    sortie << "masse [kg]               :  " << m_masse << std::endl;
    sortie << "masse volumique [kg m-3] :  " << m_masseVolumique << std::endl;
    sortie << "distance [m]             :  " << m_d << std::endl;

    sortie << "rayon [m]                :  " << m_rayon << std::endl;
    sortie << "hauteur [m]              :  " << m_hauteur << std::endl;

    sortie << "position (x,y,z) [m]     :  " << getPosition() << std::endl;


}


std::ostream& operator<<(std::ostream& flux, ConeSimple const& C){
/* Affichage générique via la surchage de l'opérateur << */
    flux << "Type : " << C.getType() << "  ; Angles : " << C.getAngles() << "  ;  Dérivées : " << C.getAnglesp()
         << "  ;  Position : " << C.getPosition() << "  ; Energie : " << C.Energie() << "  ; L_a : " << C.L_a() << "  ; L_K : " << C.L_k() <<
         "  ; det[omega, L, a] : " << C.ProdMixte() << std::endl;

    return flux;
}

// ==================================================================================================

    /* Calcul de pleins de grandeurs physiques par des formules données dans le complément mathématico-physique *
     * Nous ne permettons pas de set de ces grandeurs puisqu'intrinsèques à l'objet dont les propriétés comme   *
     * la forme et la masse sont supposées constantes par l'aproximation du solide indéformable                 */

double ConeSimple::calculeIA1(double const& rayon, double const& hauteur, double const& masseVolumique) const {

    double r(fabs(rayon));
    double h(fabs(hauteur));
    double rho(fabs(masseVolumique));


    return masse(r, h, rho)*(3.0/20*r*r+3.0/5*h*h);

}

double ConeSimple::calculeI3(double const& rayon, double const& hauteur, double const& masseVolumique) const {

    double r(fabs(rayon));
    double h(fabs(hauteur));
    double rho(fabs(masseVolumique));

    return 3.0*masse(r, h, rho)/10*r*r;

}

double ConeSimple::masse(double const& rayon, double const& hauteur, double const& masseVolumique) const{

    double r(fabs(rayon));
    double h(fabs(hauteur));
    double rho(fabs(masseVolumique));

    return 1.0/3*M_PI*r*r*h*rho;

}

    /* Accesseurs à des grandeurs physiques intrinséques au cône */

double ConeSimple::getRayon() const {

    return m_rayon;
}

double ConeSimple::getHauteur() const {

    return m_hauteur;
}
