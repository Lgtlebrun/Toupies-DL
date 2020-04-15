#include <iostream>
#include "../general/headers/TextViewer.h"
#include "../general/headers/Systeme.h"
using namespace std;

int main()
{
  TextViewer ecran(cout);
  IntegrateurEulerCromer I(0.0);
  Oscillateur O(ecran, {1.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0},0.2);
  Systeme c(ecran, I);
  c.addIntegrable(O);

  cout << "Au départ :" << endl;
  c.dessine();

  c.evolue(0.1);
  cout << "Après un pas de calcul :" << endl;
  c.dessine();

  c.evolue(0.1);
  cout << "Après deux pas de calcul :" << endl;
  c.dessine();

  return 0;
}
