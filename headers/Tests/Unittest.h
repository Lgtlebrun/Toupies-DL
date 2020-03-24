#ifndef UNITTEST_H
#define UNITTEST_H

#include <string>


class Unittest

    /// Classe mère des tests unitaires

{
    public:

        Unittest();
        virtual ~Unittest();

        virtual bool run() = 0;


    protected:

        bool m_success;                             // Booléen indiquant le succès ou l'échec du test
        std::string m_comment;                      // Messages d'erreurs / de succès
};

#endif // UNITTEST_H
