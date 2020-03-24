#include "Vecteur.h"
#include <iostream>

using namespace std;

int main(){

    Vecteur v1, resultat;
    Vecteur v2({2,4,5}), v3({8,2,3});
    Vecteur v4({2,1});


    resultat = v2 ^ v3;

    resultat.affiche();

    resultat = v4 ^ v2;

    resultat.affiche();


return 0;
}
