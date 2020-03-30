#include "Tests/TestTextViewer.h"
#include "../../headers/Tests/Unittest.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

/*
TestTextViewer::TestTextViewer() : Unittest()
{
    // ctor
}



bool TestTextViewer::run(){

// Tests

    try {

        m_success = (SimulationTexte());

    }

// Gestion des exceptions système

    catch (std::exception const &e) {

        std::string alerte("Erreur systeme dans la classe Integrateur : ");
        alerte += e.what();
        alerte += " \n";
        m_comment += (alerte);
        m_success = false;
    }

    std::cout << "Test de la classe TextViewer" << std::endl;

    if (m_success) {

        std::cout << "Le test s'est correctement déroulé. Classe opérationnelle." << std::endl;
    } else {

        std::ofstream flux;
        flux.open("TestTextViewer_ErrReport.txt");

        std::cout << "Echec du test." << std::endl;

        if (flux) {

            flux << m_comment << std::endl;
            std::cout << "Rapport d'erreur enregistré." << std::endl;

        } else { std::cout << "Erreur : ErrReport n'a pas pu etre ecrit." << std::endl; }
    }

    return m_success;

}





bool TestTextViewer::SimulationTexte() {

    // teste la simulation de 2 toupies Coniques

    std::ofstream flux;
    flux.open("SimulationTexte.txt");

    ConeSimple C1({0,M_PI/6, 0}, {0,0,60}, 0.5, 1.5, 0.1);
    ConeSimple C2({0,M_PI/4, 0}, {0,0,40}, 0.5, 1.5, 0.1);

    IntegrateurEulerCromer I(0.0);

    TextViewer T(flux);

    Systeme S(&T, I);

    S.addIntegrable(C1);
    S.addIntegrable(C2);

    double dt(0.01);

    flux << S << std::endl;

    for (int k(0); k<1000; ++k){

        S.evolue(dt);
        T.dessine(S);

    }

    flux.close();
    return true;


}
*/