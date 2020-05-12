#include "../headers/Toupie.h"
#include <math.h>
#include <iostream>


Toupie::Toupie (SupportADessin& sup, std::string const& type, Vecteur const& angles, Vecteur const& anglespoint, Vecteur const& posA, double const& IA1, double const& I3, double const& masseVolumique, double const & masse, double const& d)
/* Nous prenons un support à dessin et le type de Toupie en string. Param et vit sont les vecteurs liés à l'intégrateur *
 * tandis que posA est la position du point de contact entre la toupie et le sol. Les moments d'inertie IA1 et I3 sont  *
 * laissés en argument car ça ne fait aucun sens de le calculer pour une toupie générale. De même, la masse dépend de   *
 * la masse volumique mais aussi de la forme sur laquelle nous ne pouvons rien dire dans le cas général. d est la       *
 * distance du centre de masse au point de contact au sol. La distance de sécurité est dépendante du type de toupie,    *
 * d'où la raison pour laquelle elle est en argument                                                                    */
    : ObjetPhysique(sup, type, angles.concatene(Vecteur({0.0,0.0,0.0})), anglespoint.concatene(posA)), m_IA1(IA1), m_I3(I3), m_masse(masse), m_d(d), m_masseVolumique(masseVolumique)
{}

Toupie::~Toupie() {}

Toupie* Toupie::clone() const {

    return new Toupie(*this);

}

void Toupie::dessine() {

    m_support->dessine(*this);

}

std::ostream& operator<<(std::ostream& flux, Toupie const& C){
/* Affichage générique via la surchage de l'opérateur << */
    flux << "Type : " << C.getType() << "  ; Angles : " << C.getAngles() << "  ;  Dérivées : " << C.getAnglesp()
         << "  ;  Position : " << C.getPosition() << "  ; Energie : " << C.Energie() << "  ; L_a : " << C.L_a() << "  ; L_K : " << C.L_k() <<
         "  ; det[omega, L, a] : " << C.ProdMixte() << std::endl;

    return flux;
}

// ===========================================================================================================

Vecteur Toupie::equEvol(double const& temps) {
/* Avec l'équation d'évolution en page 12 du complément mathématique, assumant donc distance centre de masse - *
 * point de contact = cste                                                                                     */


    Vecteur sortie;                // convention : (théta, psy, phi)
                                  // initialisation au vecteur nul

    m_P = modulo2Pi();

    Vecteur o(omega());

    Vecteur M_A({m_masse*g.norme()*m_d*sin(m_P.getCoord(0)),0.0,0.0});

    Matrice3 IA(TenseurInertie());

    Vecteur o_e(o-Vecteur({0.0,0.0,m_Ppoint.getCoord(2)}));

    Vecteur omegap(IA.inv()*(M_A- (o_e^(IA*o))));

    if ( fabs(sin(m_P.getCoord(0))) >= PREC ) {

        sortie.setCoord(0, omegap.getCoord(0));
        sortie.setCoord(1, (omegap.getCoord(1)-m_Ppoint.getCoord(0)*m_Ppoint.getCoord(1)*cos(m_P.getCoord(0)))/sin(m_P.getCoord(0)));
        sortie.setCoord(2, omegap.getCoord(2)
        +(m_Ppoint.getCoord(0)*m_Ppoint.getCoord(1)-omegap.getCoord(1)*cos(m_P.getCoord(0)))/sin(m_P.getCoord(0)));

    } else {

        sortie.setCoord(0, omegap.getCoord(0));
        sortie.setCoord(1, 0.0);
        sortie.setCoord(2, omegap.getCoord(2));

    }

    Vecteur v(-(AG()^omega()));

    return sortie.concatene(v);

}

// =====================================================================================================

void Toupie::setParam(const Vecteur & newV) {

    m_P = newV;

    m_P = modulo2Pi();

}

Vecteur Toupie::getAngles() const {

    return {m_P.getCoord(0), m_P.getCoord(1), m_P.getCoord(2)};

}
void Toupie::setAngles(const Vecteur &newV) {

    if (newV.getDim() >= 3) {

        m_P.setCoord(0, newV.getCoord(0));
        m_P.setCoord(1, newV.getCoord(1));
        m_P.setCoord(2, newV.getCoord(2));

    }

}

Vecteur Toupie::getAnglesp() const {

    return {m_Ppoint.getCoord(0), m_Ppoint.getCoord(1), m_Ppoint.getCoord(2)};

}
void Toupie::setAnglesp(const Vecteur &newV) {

    if (newV.getDim() >= 3) {

        m_Ppoint.setCoord(0, newV.getCoord(0));
        m_Ppoint.setCoord(1, newV.getCoord(1));
        m_Ppoint.setCoord(2, newV.getCoord(2));

    }

}



Vecteur Toupie::getPosition() const {
/* Retourne le point de contact entre la toupie et le sol */
    return  Vecteur({m_Ppoint.getCoord(3), m_Ppoint.getCoord(4), 0.0})+S().transp()*Vecteur({0.0,0.0,m_d});

}
void Toupie::setPosition(const Vecteur &newV) {

    if (newV.getDim() >= 2) {

        m_Ppoint.setCoord(3, newV.getCoord(0));
        m_Ppoint.setCoord(4, newV.getCoord(1));
        m_Ppoint.setCoord(5, 0.0);

    }

}

Vecteur Toupie::getVitesse() const {
/* Retourne la vitesse du centre de masse */
    return Vecteur({0.0, 0.0, -m_d})^omega();

}

Vecteur Toupie::AG() const {

    return S().transp()*Vecteur({0.0, 0.0, m_d});

}

// ====================================================================================================

double Toupie::Energie() const {

    Matrice3 IG(m_IA1-m_masse*m_d*m_d, 0.0, 0.0
                , 0.0, m_IA1-m_masse*m_d*m_d, 0.0
                , 0.0, 0.0, m_I3);

    return 1.0/2*(m_masse*getVitesse().norme2()+omega()*(IG*omega())) - m_masse*g.prodScalaire(getPosition()) ;


}

double Toupie::L_a() const {

    Vecteur a(Vecteur({0.0,0.0,1.0}));

    return a*(TenseurInertie()*omega());

}

double Toupie::L_k() const {

    Matrice3 I_O(S().transp()*TenseurInertie());

    Vecteur o(omega());

    return (I_O*o)*Vecteur({0.0,0.0,1.0});

}

double Toupie::ProdMixte() const {

    Vecteur o(omega());

    Vecteur L(TenseurInertie()*omega());

    Vecteur a(Vecteur({0.0,0.0,1.0}));

    Matrice3 M(o.getCoord(0), o.getCoord(1), o.getCoord(2)
            , L.getCoord(0), L.getCoord(1), L.getCoord(2)
            , a.getCoord(0), a.getCoord(1), a.getCoord(2));

    return M.det();

}

// =====================================================================================================

void Toupie::statsCorps(std::ostream& sortie) const {
/* Addiche les statistiques d'une toupie */
    sortie << "Angles                   :  " << getAngles() << std::endl;
    sortie << "Vitesse angulaire        :  " << getAnglesp() << std::endl;
    sortie << "masse [kg]               :  " << m_masse << std::endl;
    sortie << "masse volumique [kg m-3] :  " << m_masseVolumique << std::endl;
    sortie << "distance [m]             :  " << m_d << std::endl;

}

// ====================================================================================================

Vecteur Toupie::modulo2Pi() const{
/* Une méthode qui remet le paramètre d'une toupie modulo 2PI pour éviter la divergence des fonctions trigonométriques *
 * représentées par des séries de Taylor                                                                               */

    Vecteur sortie;

    for (unsigned int k(0); k < 3 ; ++k) {

        if (m_P.getCoord(k)<0) {

            int n(m_P.getCoord(k)/(2*M_PI)+1);

            sortie.setCoord(k, m_P.getCoord(k)+n*2*M_PI);

        } else if (m_P.getCoord(k)>=2*M_PI){

            int n(m_P.getCoord(k)/(2*M_PI));

            sortie.setCoord(k, m_P.getCoord(k)-n*2*M_PI);

        } else {

            sortie.setCoord(k, m_P.getCoord(k));

        }

    }

    return sortie.concatene(Vecteur({m_P.getCoord(3),m_P.getCoord(4),m_P.getCoord(5)}));

}

// ====================================================================================================

Matrice3 Toupie::S() const {

    Vecteur P(modulo2Pi());

    return Matrice3 (cos(P.getCoord(1)), sin(P.getCoord(1)), 0.0
            , -cos(P.getCoord(0))*sin(P.getCoord(1)), cos(P.getCoord(0))*cos(m_P.getCoord(1)), sin(P.getCoord(0))
            , sin(P.getCoord(0))*sin(P.getCoord(1)), -sin(P.getCoord(0))*cos(m_P.getCoord(1)), cos(P.getCoord(0)));

}


Matrice3 Toupie::TenseurInertie() const{
/* On suppose que le point de contact de la toupie est sensé être dans la même direction que l'axe */
    return Matrice3(m_IA1, 0.0, 0.0
                    , 0.0, m_IA1, 0.0
                    , 0.0, 0.0, m_I3);

}


Vecteur Toupie::omega() const {

    Vecteur P(modulo2Pi());

    double omega1(m_Ppoint.getCoord(0));
    double omega2(m_Ppoint.getCoord(1) * sin(P.getCoord(0)));
    double omega3(m_Ppoint.getCoord(1) * cos(P.getCoord(0)) + m_Ppoint.getCoord(2));
    return {omega1, omega2, omega3};
    
}

