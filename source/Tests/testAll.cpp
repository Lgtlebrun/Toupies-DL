#include <vector>
#include "Tests/TestIntegrateur.h"
#include "../../headers/Tests/TestVecteur.h"
#include "../../headers/Tests/TestMatrice.h"


int main() {

    std::vector<Unittest*> Tests;

    Tests.push_back(new TestVecteur);
    Tests.push_back(new TestMatrice);
    Tests.push_back(new TestIntegrateur);

    std::cout << "Début du test." << std::endl;

  for (auto& ptr:Tests){
      ptr->run();
      delete ptr;
  }

    return 0;
}


