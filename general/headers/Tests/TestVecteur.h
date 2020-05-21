#pragma once

#ifndef TESTVECTEUR_H
#define TESTVECTEUR_H

#include "Unittest.h"
#include "../Vecteur.h"


class TestVecteur : public Unittest
{
public:

// =========

    TestVecteur();                                      // ctor de la classe TestVecteur
    virtual ~TestVecteur();                             // dtor de la classe TestVecteur

// =========

    virtual bool run();                                 // la méthode permetteant de lancer les tests

// =========

    bool test_augmente();                               // vérifie que la méthode augmente(double) augmente bien la dimension du vecteur
    bool test_norme();                                  // vérifie que le calcul de la norme soit exact
    bool test_prodVect();                               // vérifie que le produit vectoriel soit exact et qu'il ne se fasse pas entre vecteurs de dimension != 3
    bool test_prodScal();                               // vérifie que le calcul du produit scalaire soit exact

protected:

};

#endif // TESTVECTEUR_H
