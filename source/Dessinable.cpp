#include "../headers/Dessinable.h"


Dessinable::Dessinable(SupportADessin *support) : m_support(support) {}

Dessinable::~Dessinable() {

    delete m_support;
}

Dessinable::Dessinable(Dessinable const & autre) {

    m_support = autre.m_support->clone();
}

Dessinable& Dessinable::operator=(Dessinable const & autre) {

    m_support = autre.m_support->clone();

    return *this;
}

