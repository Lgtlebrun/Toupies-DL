#pragma once

#ifndef TOUPIES_DL_BILLE_H
#define TOUPIES_DL_BILLE_H

#include "../ObjetPhysique.h"
#include "../constantes.h"


class Bille : public ObjetPhysique
{
public :

// =========

    Bille(SupportADessin& sup, Vecteur const& Position, Vecteur const& Vitesse, double const& rayon);
/* ctor de Bille prenant comme argument le support à dessin où nous aimerions le dessiner ainsi que les coord. *
 * initiales et les composantes de la vitesse initiale, en 2D                                                  */

// =========

    virtual Bille* clone() const;                   // Renvoie un pointeur sur une copie polymorphique de la bille
    virtual void dessine() override;                // permet une customisation de l'affichage d'une bille

    void statsCorps(std::ostream& flux);

// =========

    virtual Vecteur equEvol(double const& temps) override;    // equation du mouvement d'une bille lâchée ou lancée

    virtual std::string getType() const;                      // sert à donner le typer pour les méthodes qui affichent des billes

    double getRayon() const;                                        // renvoit le rayon

// =========

    virtual double Energie() const;

    virtual double L_a() const;

    virtual double L_k() const;

    virtual double ProdMixte() const;

// ==================================================================================


protected :

    double m_rayon;

};


// =============================  SURCHARGE D'OPERATEUR EXTERNE  ======================================


std::ostream& operator<<(std::ostream& flux, Bille const& B);              // sortie personnalisée





#endif //TOUPIES_DL_BILLE_H
