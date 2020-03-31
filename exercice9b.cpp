#include "headers/TextViewer.h"
#include <cmath>
#include <fstream>


using namespace std;

int main() {

    ConeSimple C1({M_PI/6,0, 0}, {0,0,60}, 0.5, 1.5, 0.1);
    ConeSimple C2({M_PI/4,0, 0}, {0,0,40}, 0.5, 1.5, 0.1);

    const double dt(0.01);

    string Exo("Exercice9b.txt");
    ofstream flux (Exo.c_str());

    IntegrateurNewmark I(0.0);

    if (!flux.fail()) {


        TextViewer T(flux);


        Systeme S(T, I);

        S.addIntegrable(&C1);
        S.addIntegrable(&C2);

        S.affiche(flux);

        for (int k(0); k < 19 ; ++k) {

            S.evolue(dt);
            S.dessine();

        }

        flux.close();

    }

    return 0;
}
