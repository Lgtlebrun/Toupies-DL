#include "../../headers/Tests/TestVecteur.h"
#include "../../headers/Tests/Unittest.h"
#include "../../headers/Vecteur.h"
#include <iostream>
#include <fstream>
#include <string>

TestVecteur::TestVecteur() : Unittest()
{
    //ctor
}

TestVecteur::~TestVecteur()
{
    //dtor
}


bool TestVecteur::run(){




    // Tests

    try{

        m_success = (test_augmente() && test_norme() && test_prodScal() && test_prodVect());

    }

    // Gestion des exceptions système

    catch(std::exception const& e){

        std::string alerte("Erreur systeme dans la classe Vecteur : ");
        alerte +=  e.what();
        alerte +=  " \n";
        m_comment += (alerte);
        m_success = false;
    }





    // Affichage


    std::cout << "Test de la classe Vecteur" << std::endl;

    if (m_success) {

        std::cout << "Le test s'est correctement déroulé. Classe opérationnelle." << std::endl;
    }

    else{

        std::ofstream flux;
        flux.open("TestVecteur_ErrReport.txt");

        std::cout << "Echec du test." ;

        if(flux){

            flux << m_comment << std::endl;
            std::cout << "Rapport d'erreur enregistré." << std::endl;

        }
        else{ std::cout << "Erreur : ErrReport n'a pas pu etre ecrit." << std::endl;}
    }




    return m_success;
}


/* Nous vérifions la véracité du résultat de l'opération en comparant l'écart avec un vecteur pré-calculé */

bool TestVecteur::test_augmente() {

    Vecteur v1({2,3,4});
    v1.augmente(5);


    size_t taille(v1.getDim());

    if (taille != 4){

        m_comment += ("Erreur fonction augmente() : attendu : v1.size() = 4 ; constaté : v1.size() = " + std::to_string(taille)) + "\n";
        return false;

    }

    return true;
}



bool TestVecteur::test_norme(){

    Vecteur v1({1,2,2});
    double n;

    n = v1.norme();


    if (abs(n - 3.0) > PREC){

        m_comment += ("Erreur fonction norme. Attendu : 3.0 ; Constaté : " + std::to_string(n) + "\n");
        return false;
    }


    return true;
}



bool TestVecteur::test_prodVect(){

    Vecteur v1({1,2,3,4});
    Vecteur v2({1,2,3});
    Vecteur v3({2,3,4});
    Vecteur nul;

    bool succes(true);

    std::cout << "On attend une erreur de la part du produit vectoriel." << std::endl;
    if (nul != (v1 ^ v2)) {
        m_comment += "Erreur produit vectoriel: de mauvaises dimensions ne renvoient pas le vecteur nul \n";
        succes = false;
    }

    v1 = v2 ^ v3;
    if (v1 != Vecteur({2,2,-1})){

        m_comment += ("Erreur produit vectoriel (1,2,3) ^ (2,3,4) . Attendu (2,2,-1).  Constaté (" + std::to_string(v1.getCoord(0)) + ", " + std::to_string(v1.getCoord(1)) + ", " + std::to_string(v1.getCoord(2)) + ") \n");
        succes = false;
    }

    return succes;
}




bool TestVecteur::test_prodScal(){

    Vecteur v1({1,2,3}), v2({2,3,4});

    double res(v1 * v2);

    if (abs(res - 20) > PREC){

        m_comment += ("Erreur produit scalaire. Attendu : 14.0.  Constaté : " + std::to_string(res) +" \n");
        return false;
    }

    return true;
}


