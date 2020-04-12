#ifndef CONTENU_H
#define CONTENU_H

#include "../../headers/Dessinable.h"
#include <iostream>


class Contenu : public Dessinable {
public:

  Contenu(SupportADessin& vue)
    : Dessinable(vue), angle(0.0)
  {}
  virtual ~Contenu() {}

  virtual void dessine() override
  { m_support.dessine(*this); }

  virtual Contenu* clone() const;

  void evolue(double dt);

  // accesseur
  double getAngle() const { return angle; }

private:
  double angle; /* pour le mouvement ;
                   dans cet exemple, juste une rotation
                   au cours du temps                    */
};


std::ostream& operator<<(std::ostream& flux, Contenu const& c);

#endif // CONTENU_H
