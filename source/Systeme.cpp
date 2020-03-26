#include <../headers/Systeme.h>


Systeme::Systeme(SupportADessin *support) : Dessinable(support)
{}

Systeme::~Systeme()
{
    for (auto& elt:m_toupies) {

        // Gestion de la collection de pointeurs
        delete elt;
    }
}


void Systeme::dessine() {

    m_support->dessine(*this);
}
