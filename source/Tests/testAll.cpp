#include "../../headers/Tests/TestVecteur.h"
#include "../../headers/Tests/TestMatrice.h"

int main() {

    TestVecteur test1;
    TestMatrice test2;



    std::cout << "Début du test." << std::endl;

    test1.run();
    test2.run();

    return 0;
}