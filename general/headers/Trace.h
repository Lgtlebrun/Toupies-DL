#ifndef TRACE_H
#define TRACE_H

#include "Dessinable.h"
#include <deque>


class Trace : public Dessinable {


public:

    Trace(SupportADessin& sup) : Dessinable(sup){}

    virtual Trace* clone() const override {return new Trace(*this);}
    Vecteur getPoint(size_t i) const {return m_points[i];}
    size_t size() const {return m_points.size();}
    void addPoint(Vecteur const& v1);
    virtual void dessine() override;




private:

    std::deque<Vecteur> m_points;

};






#endif // TRACE_H
