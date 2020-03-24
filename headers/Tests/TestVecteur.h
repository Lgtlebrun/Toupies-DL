#pragma once

#ifndef TESTVECTEUR_H
#define TESTVECTEUR_H

#include "Unittest.h"
#include "../Vecteur.h"


class TestVecteur : public Unittest
{
    public:
        TestVecteur();
        virtual ~TestVecteur();

        virtual bool run();

        bool test_augmente();
        bool test_norme();
        bool test_prodVect();
        bool test_prodScal();

    protected:

};

#endif // TESTVECTEUR_H
