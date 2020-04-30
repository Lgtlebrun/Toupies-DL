#include <fstream>
#include "../general/headers/TextViewer.h"
#include <iostream>

using namespace std;

int main(){

    const double dt(0.01);

    string Exo("Exercice9a.txt");
    ofstream flux (Exo.c_str());

    IntegrateurEulerCromer I(0.0);

    TextViewer T(flux);

    if (!flux.fail()) {

        Bille B(T, Vecteur({0.0,0.0,1.0}), Vecteur({1.0,0.0,2.0}), 0.2);
        Oscillateur O(T, Vecteur({2.0,3.0,1.0}),Vecteur({0.0,0.0,0.0}), Vecteur({2.0,3.0,0.0}), 0.1);

        Systeme S(T, I);

        S.addIntegrable(B);
        S.addIntegrable(O);

        for (int k(0); k < 68; ++k) {

            S.evolue(dt);
            S.dessine();

        }

        flux.close();
    }

    return 0;
}

