#pragma once

#ifndef TOUPIES_DL_OSCILLATEUR_H
#define TOUPIES_DL_OSCILLATEUR_H

#include "Integrable.h"


class Oscillateur : public Integrable
{
public :

// =========

    Oscillateur(SupportADessin&, Vecteur const&, Vecteur const&);           // ctor d'Oscillateur. Il faut entrer un
                                                                            // support à dessin sur lequel nous aimerions
                                                                            // afficher l'oscillateur. En plus, le pre-
                                                                            // mier vecteur est le vecteur de position
                                                                            // initiale et le second celui de la vitesse
                                                                            // initiale

// =========

    virtual Oscillateur* clone() const;                                     // Renvoie un pointeur sur une copie
                                                                            // polymorphique de l'oscillateur
    virtual void dessine() override;                                        // permet un affichage customisé de la classe
                                                                            // Oscillateur

// =========

    virtual Vecteur equEvol(double const& temps) const;                     // Equation d'évolution de l'oscillateur
                                                                            // harmonique

    virtual std::string getType() const;                                    // retourne le type de l'objet pour des


// =====================================================================================


protected:

};

// =======================  SURCHARGE D'OPERATEUR EXTERNE  ===============================================


std::ostream& operator<<(std::ostream&, Oscillateur const&);               // sortie personnalisée





#endif //TOUPIES_DL_OSCILLATEUR_H
