#include <fstream>
#include "headers/TextViewer.h"

using namespace std;

int main(){

    Bille B(0,1,1,2);
    Oscillateur O(Vecteur({1}),Vecteur({0}));

    const double dt(0.01);

    string Exo("Exercice9a.txt");
    ofstream flux (Exo.c_str());

    if ( !flux ) {

        flux(cout);

    }

    TextViewer T(flux);

    IntegrateurEulerCromer I(0.0);

    Systeme S(&T, &I);

    S.addIntegrable(B);
    S.addIntegrable(O);


    for (int k(0); k<68; ++k) {

        S.evolue(dt);
        S.dessine();

    }

    flux.close();

    return 0;
}

