#pragma once

#ifndef TOUPIES_DL_TESTSYSTEME_H
#define TOUPIES_DL_TESTSYSTEME_H

#include "Unittest.h"
#include "../Systeme.h"


class TestSysteme : public Unittest {
public:

// =========

    TestSysteme();                          // ctor par défaut de la classe TestSysteme

// =========

    virtual bool run();                     // la méthode permetteant de lancer les tests

// =========

    bool test_evol();                       // la méthode qui vérifie l'évolution d'intégrables dans un système


// ================================================================================


protected:

// =========  METHODE INTERNE :

    void dispErrorInteg(double const &t, std::string const &attendu, std::string const &constat);
                                            // la méthode qui permet de préparer un message d'erreur

};


#endif //TOUPIES_DL_TESTSYSTEME_H
