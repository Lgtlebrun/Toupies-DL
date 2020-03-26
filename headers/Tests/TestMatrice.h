//
// Created by lgtle on 25/03/2020.
//
#pragma once
#include "Unittest.h"
#include "../Vecteur.h"
#include "../Matrice3.h"

#ifndef TOUPIES_DL_TESTMATRICE_H
#define TOUPIES_DL_TESTMATRICE_H

#endif //TOUPIES_DL_TESTMATRICE_H

class TestMatrice : public Unittest
        {
        public:
            TestMatrice();

            virtual bool run();

            bool testProdMatriciel();
            bool testTranspo();
            bool testInv();
            bool testDet();


};
