#include "../headers/Trace.h"


void Trace::addPoint(Vecteur const& v1) {

    m_points.push_back(v1);

    if(m_points.size() >50){
        m_points.pop_front();
    }
}

void Trace::dessine() {
    m_support->dessine(*this);
}
