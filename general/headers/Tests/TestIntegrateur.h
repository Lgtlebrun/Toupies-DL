#ifndef TOUPIES_DL_TESTINTEGRATEUR_H
#define TOUPIES_DL_TESTINTEGRATEUR_H

#include "Unittest.h"
#include "Bille.h"
#include "Oscillateur.h"
#include "../Integrateur.h"
#include "constantes.h"
#include <cmath>


class TestIntegrateur : public Unittest
{
public:

// =========

    TestIntegrateur();                          // ctor de TestIntegrator, par défaut

    virtual bool run();                         // méthode qui lance les tests

// =========

    bool testBille();                           // méthode qui teste la bille et les intégrateurs en comparant
                                                // les calculs avec les résultats donnés sur progmaph

    bool testOH();                              // méthode qui teste l'oscillateur harmonique et les intégrateurs
                                                // en vérifiant avec l'écart de la solution y(t) = cos(t)

};


#endif //TOUPIES_DL_TESTINTEGRATEUR_H
