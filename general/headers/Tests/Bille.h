#pragma once

#ifndef TOUPIES_DL_BILLE_H
#define TOUPIES_DL_BILLE_H

#include "../Integrable.h"
#include "../constantes.h"


class Bille : public Integrable
{
public :

// =========

    Bille(SupportADessin&, Vecteur const&, Vecteur const&, double const&);
                                                                    // ctor de Bille prenant comme argument le support à
                                                                    // dessin où nous aimerions le dessiner ainsi que
                                                                    // les coord. initiales et les composantes de la
                                                                    // vitesse initiale, en 2D

// =========

    virtual Bille* clone() const;                                   // Renvoie un pointeur sur une copie polymorphique
                                                                    // de la bille
    virtual void dessine() override;                                // permet une customisation de l'affichage d'une bille

// =========

    virtual Vecteur equEvol(double const& temps);             // equation du mouvement d'une bille lâchée ou lancée

    virtual std::string getType() const;                            // sert à donner le typer pour les méthodes qui affichent
                                                                    // des billes

    virtual void setDistSecu();

    double getRayon() const;                                        // renvoit le rayon


    virtual Vecteur getPosition() const;
    virtual void setPosition(Vecteur const&);


// ==================================================================================


protected :

    double m_rayon;

};


// =============================  SURCHARGE D'OPERATEUR EXTERNE  ======================================


std::ostream& operator<<(std::ostream&, Bille const&);              // sortie personnalisée





#endif //TOUPIES_DL_BILLE_H
