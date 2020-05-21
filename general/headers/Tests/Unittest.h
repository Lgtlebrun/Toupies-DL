#ifndef UNITTEST_H
#define UNITTEST_H

#include <string>
#include <iostream>


class Unittest

    /// Classe mère des tests unitaires

{
public:

// =========

    Unittest();                                 // ctor de la classe Unittest
    virtual ~Unittest();                        // dtor de la classe Unittest

// =========

    virtual bool run() = 0;                     // méthode abstraite permettant de lancer le test de chaque classe test

// ========================================================================================


protected:

// =========  ATTRIBUTS :

    bool m_success;                             // Booléen indiquant le succès ou l'échec du test
    std::string m_comment;                      // Messages d'erreurs / de succès

};

#endif // UNITTEST_H
