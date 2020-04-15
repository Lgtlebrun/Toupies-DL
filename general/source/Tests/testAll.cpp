#include <vector>
#include "../../headers/Tests/TestIntegrateur.h"
#include "../../headers/Tests/TestVecteur.h"
#include "../../headers/Tests/TestMatrice.h"
#include "../../headers/Tests/TestSysteme.h"


int main() {

    std::vector<Unittest*> Tests;

    Tests.push_back(new TestVecteur);                           // On met tous les tests que l'on veut dans Tests
    Tests.push_back(new TestMatrice);
    Tests.push_back(new TestIntegrateur);
    Tests.push_back(new TestSysteme);

    std::cout << "Début du test." << std::endl;

  for (auto& ptr:Tests){

      ptr->run();                                               // On effectue le test puis détruit le pointeur
      delete ptr;
  }

    return 0;
}


