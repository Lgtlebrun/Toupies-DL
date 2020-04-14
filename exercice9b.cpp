#include "general/headers/TextViewer.h"
#include <cmath>
#include <fstream>


using namespace std;

int main() {

    const double dt(0.01);

    string Exo("Exercice9b.txt");
    ofstream flux (Exo.c_str());

    IntegrateurEulerCromer I(0.0);

    if (!flux.fail()) {


        TextViewer T(flux);

        ConeSimple C1(T, {M_PI/6,0, 0}, {0,0,60}, {0.0,0.0,0.0}, 0.5, 1.5, 0.1);
        ConeSimple C2(T, {M_PI/4,0, 0}, {0,0,40}, {0.0,3.0,0.0}, 0.5, 1.5, 0.1);

        Systeme S(T, I);

        S.addIntegrable(C1);
        S.addIntegrable(C2);

        S.affiche(flux);

        for (int k(0); k < 600 ; ++k) {

            S.evolue(dt);
            S.dessine();

        }

        flux.close();

    }

    return 0;
}
