#pragma once

#ifndef TOUPIES_DL_OSCILLATEUR_H
#define TOUPIES_DL_OSCILLATEUR_H

#include "../Integrable.h"


class Oscillateur : public Integrable
{
public :

// =========

    Oscillateur(SupportADessin&, Vecteur const&, Vecteur const&, Vecteur const&, double const&);
                                                                            // ctor d'Oscillateur. Il faut entrer un
                                                                            // support à dessin sur lequel nous aimerions
                                                                            // afficher l'oscillateur. En plus, le pre-
                                                                            // mier vecteur est le vecteur de position
                                                                            // initiale et le second celui de la vitesse
                                                                            // initiale, le troisième est celui du centre
                                                                            // du mouvement. Le double est le rayon de
                                                                            // l'oscillateur


// =========

    virtual Oscillateur* clone() const;                                     // Renvoie un pointeur sur une copie
                                                                            // polymorphique de l'oscillateur
    virtual void dessine() override;                                        // permet un affichage customisé de la classe
                                                                            // Oscillateur

    void statsCorps(std::ostream& sortie);

// =========

    virtual Vecteur equEvol(double const& temps);                           // Equation d'évolution de l'oscillateur
                                                                            // harmonique

    virtual std::string getType() const;                                    // retourne le type de l'objet pour des

// =========

    double getRayon() const;                                                // renvoit le rayon

    Vecteur getPosition() const;                                            // revoit la position du centre du mvt
    void setPosition(Vecteur const&);

// =========

    virtual double Energie() const;

    virtual double L_a() const;

    virtual double L_k() const;

    virtual double ProdMixte() const;

// =====================================================================================


protected:

    Vecteur m_centreMVT;                                            // le centre du mouvement

    double m_rayon;                                                 // rayon de l'oscillateur considéré étant une bille

};

// =======================  SURCHARGE D'OPERATEUR EXTERNE  ===============================================


std::ostream& operator<<(std::ostream&, Oscillateur const&);               // sortie personnalisée





#endif //TOUPIES_DL_OSCILLATEUR_H
