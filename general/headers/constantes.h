#pragma once

#ifndef TOUPIES_DL_CONSTANTES_H
#define TOUPIES_DL_CONSTANTES_H

#include "Vecteur.h"
#include <iostream>


class Vecteur;
class TextViewer;


// =========  DEFINITION DES CONSTANTES :


extern const Vecteur g;                                 // g l'intensité de l'accélération gravitationnelle à la surface
                                                        // de la terre
extern const double PREC;                               // une precision pour les égalités de double
extern const double EPSILON;                            // "Erreur" que l'on se permet sur l'intégrateur de Newmark


#endif //TOUPIES_DL_CONSTANTES_H
