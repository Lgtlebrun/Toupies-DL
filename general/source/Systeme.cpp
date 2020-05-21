#include "../headers/Systeme.h"


Systeme::Systeme(SupportADessin& support, Integrateur& I)
/* le ctor ne prend qu'un support à dessin, où représenter nos intégrables, ainsi qu'un intégrateur qui sera celui *
 * qui fera évoluer tous les intégrables à la même "vitesse temporelle" et surtout avec la même méthode intègre()  */
    : Dessinable(support), m_integrateur(I)
{}

Systeme::Systeme(Systeme const& S) : Dessinable(S), m_integrateur(*(S.m_integrateur.clone())) {
/* Constructeur de copie, pointeurs obligent */

    for (auto const& elt : S.m_corps){

        m_corps.push_back(elt->clone());
    }

}

Systeme& Systeme::operator=(Systeme const& S) {
/* Opérateur d'affectation, pointeurs obligent */

    if (this != &S){

        m_support = S.m_support;

        for (auto& elt : m_corps){
           delete elt;
    }

        for (auto const& elt : S.m_corps){

            m_corps.push_back(elt->clone());
        }

        m_integrateur = *(S.m_integrateur.clone());

    }

    return *this;
}

Systeme::~Systeme()
{
    for (auto& elt:m_corps) {

        delete elt;                 // Gestion de la collection de pointeurs
    }

}

// ==============================================================================================

Systeme* Systeme::clone() const {
/* Méthode de clonage de la classe Systeme */
    return new Systeme(*this);
}

// ==============================================================================================

void Systeme::dessine() {
/* Cette méthode appelle la méthode dessine(Systeme const&) d'un SupportADessin, qui va appeler tour à tour    *
 * les méthodes dessine() de chaque intégrable particulier, qui va appeler a son tour la méthode               *
 * dessine(IntegrableParticulier const&) du SupportADessin qui va enfin dessiner l'intégrable en question dans *
 * le bon milieu                                                                                              */
    m_support->dessine(*this);
}

// =============================================================================================

void Systeme::changeSupport(SupportADessin & sup) {
/* Permet de faire changer de s$SUpportADessin à chaque objet du Systeme */

    Dessinable::changeSupport(sup);

    for (auto& elt : m_corps) {

        elt->changeSupport(*m_support);

    }

}

void Systeme::addObjet(ObjetPhysique& O) {
/* méthode qui ajoute un intégrable au Systeme */
    m_corps.push_back(O.clone());

    /* On modifie le support de l'objet pour la cohérence du système */
    m_corps.back()->changeSupport(*m_support);
}

ObjetPhysique* Systeme::getCorps(size_t k) const {
/* Renvoie un pointeur sur la toupie en indice. En cas d'indice trop grand, renvoie nullptr */

    if (k >= m_corps.size()){
        return nullptr;
    }

    return m_corps[k];
}

unsigned int Systeme::getNbCorps() const {
/* Méthode donnant le nombre de corps que comporte le Systeme */
    return m_corps.size();
}


double Systeme::getTemps() const {
/* Méthode donnant le temps qu'il est dans la simulation, utile pour les affichages */
    return m_integrateur.getTemps();
}


void Systeme::evolue(double const& dt) {
/* Méthode permettant de faire évoluer le Systeme en intégrant chaque intégrable à son tour, puis montant *
 * le temps de l'intégrateur avec le même pas de temps                                                    */
    for (auto& elt: m_corps){
        m_integrateur.integre( *elt , dt);
    }

    m_integrateur.augmente_t(dt);

}

// =============================================================================================


std::ostream& operator<<(std::ostream& sortie, Systeme& s){
/* Surchage de l'opérateur << permettant un affichage des statistiques dans n'importe quel ostream */
    s.affiche(sortie);

    return sortie ;

}

void Systeme::affiche(std::ostream& sortie) {
/* Méthode permettant un affichage de tous les intégrables, avec la spécialité de statsCorps, permettant donc *
 * un affichage personnalisé                                                                                  */
    for (int k(0); k < m_corps.size() ; ++k) {

        sortie << "==== Corps " << k+1 << " :" << std::endl;
        sortie << m_corps[k]->getType() << std::endl;

        m_corps[k]->statsCorps(sortie);

        sortie << std::endl;


    }


}
