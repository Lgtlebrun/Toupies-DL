//
// Created by lgtle on 28/03/2020.
//

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
    TestIntegrateur();

    virtual bool run();

    bool testBille();
    bool testOH();

};







#endif //TOUPIES_DL_TESTINTEGRATEUR_H
