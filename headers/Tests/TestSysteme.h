#pragma once

#ifndef TOUPIES_DL_TESTSYSTEME_H
#define TOUPIES_DL_TESTSYSTEME_H

#include "Unittest.h"
#include "../Systeme.h"

class TestSysteme : public Unittest
{
    public:

    TestSysteme();

    virtual bool run();
    bool test_evol();


    protected:

    void dispErrorInteg(double const& t, std::string const& attendu, std::string const& constat);

};





#endif //TOUPIES_DL_TESTSYSTEME_H
