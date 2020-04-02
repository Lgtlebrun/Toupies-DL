#include "../headers/Dessinable.h"




Dessinable::Dessinable() : m_support(TextViewer(std::cout)) {}


Dessinable::Dessinable(SupportADessin& support) : m_support(support) {}



void Dessinable::changeSupport(SupportADessin& sup) {

    m_support = sup;
}



