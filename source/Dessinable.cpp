#include "../headers/Dessinable.h"


Dessinable::Dessinable(SupportADessin *support) : m_support(support) {}

Dessinable::~Dessinable() {

    delete m_support;
}

