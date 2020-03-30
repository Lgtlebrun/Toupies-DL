#include "headers/TextViewer.h"
#include <cmath>
#include <fstream>


using namespace std;

int main() {

    ConeSimple C1({0,M_PI/6, 0}, {0,0,60}, 0.5, 1.5, 0.1);
    ConeSimple C2({0,M_PI/4, 0}, {0,0,40}, 0.5, 1.5, 0.1);

    const double dt(0.01);

    string Exo("Exercice9a.txt");
    ofstream flux (Exo.c_str());

    IntegrateurEulerCromer I(0.0);

    if (flux.fail()) {

        TextViewer T(cout);

    } else {

        TextViewer T(flux);

    }

    Systeme S(&T, &I);

    S.addIntegrable(C1);
    S.addIntegrable(C2);

    S.affiche(flux);

    for (int k(0); k<68; ++k){

        S.evolue(dt);
        S.dessine();

    }

    flux.close();

    return 0;
}
