#include "../headers/ConeSimple.h"
#include <cmath>


ConeSimple::ConeSimple(SupportADessin& sup, Vecteur const& param, Vecteur const& vit, Vecteur const& pos, double const& rayon, double const& hauteur, double const& masseVolumique)
/* Nous pouvons calculer les moments d'inertie selon différents axes à base d'uniquement la masse volumique, le rayon *
 * et la hauteur du cône. De plus la distance de sécurité est définie comme étant la longueur de la paroi du cône     *
 * qui est calculée dans les accolades pour les mêmes raisons qu'expliqué dans le ctor de Bille.h                    */
        : Toupie(sup, "Cone simple", param, vit, pos, calculeIA1(rayon, hauteur, masseVolumique), calculeI3(rayon, hauteur, masseVolumique)
                , masseVolumique, masse(rayon, hauteur, masseVolumique), 3.0/4.0*hauteur, 0.0), m_rayon(rayon), m_hauteur(hauteur)
{
    setDistSecu();
}


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


Vecteur ConeSimple::equEvol(const double &temps) {

    Vecteur sortie;                // convention : (théta, psy, phi)
                                  // initialisation au vecteur nul

    modulo2Pi();

    if ( fabs(m_IA1) < PREC ) {

        return sortie;              // pas d'accélération de la rotation s'il n'y a rien à faire tourner !

    }
    if (fabs(sin(m_P.getCoord(0))) < PREC ) {

        return sortie;              // si la toupie a un angle à la verticale nul, alors, vu qu'il n'y a aucun frottement,
                                    // la somme des force est nule, entraînant une accélération nulle

    }
    if (m_P.getCoord(0) >= M_PI/2 - atan(getRayon()/getHauteur())) {

        m_Ppoint = {0.0, 0.0, 0.0};

        return sortie;

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
    sortie << "masse [kg]               :  " << m_masse << std::endl;
    sortie << "masse volumique [kg m-3] :  " << m_masseVolumique << std::endl;
    sortie << "distance [m]             :  " << m_d << std::endl;

    sortie << "rayon [m]                :  " << m_rayon << std::endl;
    sortie << "hauteur [m]              :  " << m_hauteur << std::endl;

    sortie << "position (x,y,z) [m]     :  " << m_position << std::endl;


}


std::ostream& operator<<(std::ostream& flux, ConeSimple const& C){
/* Affichage générique via la surchage de l'opérateur << */
    flux << "Type : " << C.getType() << "  ; Parametre : " << C.getParam() << "  ;  Vitesse : " << C.getVitesse()
         << "  ; Rayon : " << C.getRayon() << "  ; Hauteur : " << C.getHauteur() << std::endl;

    return flux;
}

// ==================================================================================================

    /* Calcul de pleins de grandeurs physiques par des formules données dans le complément mathématico-physique *
     * Nous ne permettons pas de set de ces garndeurs pusiqu'intrinsèques à l'objet dont les propriétés comme   *
     * la forme et la masse sont supposées constantes par l'aproximation du solide indéformable                 */

double ConeSimple::calculeIA1(double const& rayon, double const& hauteur, double const& masseVolumique) const {

    return masse(rayon, hauteur, masseVolumique)*(3.0/20*rayon*rayon+3.0/5*hauteur*hauteur);

}

double ConeSimple::calculeI3(double const& rayon, double const& hauteur, double const& masseVolumique) const {

    return 3*masse(rayon, hauteur, masseVolumique)/10*rayon*rayon;

}

double ConeSimple::masse(double const& rayon, double const& hauteur, double const& masseVolumique) const{

    return 1.0/3*M_PI*rayon*rayon*hauteur*masseVolumique;

}

void ConeSimple::setDistSecu() {

    m_distSecu = sqrt(m_hauteur*m_hauteur + m_rayon*m_rayon);

}

    /* Accesseurs à des grandeurs physiques intrinséques au cône */

double ConeSimple::getRayon() const {

    return m_rayon;
}

double ConeSimple::getHauteur() const {

    return m_hauteur;
}
