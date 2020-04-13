#pragma once
#include "Unittest.h"
#include "../Vecteur.h"
#include "../Matrice3.h"

#ifndef TOUPIES_DL_TESTMATRICE_H
#define TOUPIES_DL_TESTMATRICE_H

class TestMatrice : public Unittest {

public:

// =========

    TestMatrice();                          // ctor par défaut d'une classe testMatrice

    virtual ~TestMatrice();                 // son destructeur

// =========

    virtual bool run();                     // la méthode permetteant de lancer les tests

// =========

    bool testProdMatriciel();               // vérifie que le produit de 2 matrices se fasse correctement

    bool testTranspo();                     // vérifie que la transposition d'une matrice soit correcte

    bool testInv();                         // vérifie que l'inverse d'une matrice se fasse correctement

    bool testDet();                         // vérifie que le déterminant soit calculé exactement
};


#endif //TOUPIES_DL_TESTMATRICE_H