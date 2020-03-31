#include <fstream>
#include "headers/TextViewer.h"

using namespace std;

int main(){

    Bille B(0.0,1.0,1.0,2.0);
    Oscillateur O(Vecteur({1.0}),Vecteur({0.0}));

    const double dt(0.01);

    string Exo("Exercice9a.txt");
    ofstream flux (Exo.c_str());

    IntegrateurEulerCromer I(0.0);

    if (!flux.fail()) {


        TextViewer T(flux);


        Systeme S(T, I);

        S.addIntegrable(&B);
        S.addIntegrable(&O);


        for (int k(0); k < 68; ++k) {

            S.evolue(dt);
            S.dessine();

        }

        flux.close();
    }

    return 0;
}

