#ifndef TRACE_H
#define TRACE_H

#include "Dessinable.h"
#include <deque>


class Trace : public Dessinable {


public:

// =========

    Trace(SupportADessin& sup) : Dessinable(sup){}          // ctor de Trace

// =========

    virtual Trace* clone() const override {return new Trace(*this);}   // Renvoie un pointeur sur une copie polymorphique de la Trace

// =========

    Vecteur getPoint(size_t i) const {return m_points[i];}            // Retourne le ième point de la trace

    size_t size() const {return m_points.size();}                     // Retourne le nombres de points dans la trace

    void addPoint(Vecteur const& v1);                                 // Ajoute un point à la liste

    virtual void dessine() override;                                  // dessine la trace

// ===========================================================================================

private:

// =========  ATTRIBUT :

    std::deque<Vecteur> m_points;                                   // Liste des points

};






#endif // TRACE_H
