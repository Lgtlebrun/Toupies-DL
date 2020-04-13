
#include "../../headers/Tests/TestMatrice.h"
#include "../../headers/Matrice3.h"
#include <iostream>
#include <fstream>
#include <string>


TestMatrice::TestMatrice() : Unittest() {}

TestMatrice::~TestMatrice(){}



bool TestMatrice::run() {

    // Tests

    try{

        m_success = (testProdMatriciel() && testTranspo() && testInv() && testDet());

    }

        // Gestion des exceptions système

    catch(std::exception const& e){

        std::string alerte("Erreur systeme dans la classe Matrice : ");
        alerte +=  e.what();
        alerte +=  " \n";
        m_comment += (alerte);
        m_success = false;
    }


    // Affichage


    std::cout << "Test de la classe Matrice" << std::endl;

    if (m_success) {

        std::cout << "Le test s'est correctement déroulé. Classe opérationnelle." << std::endl;
    }

    else{

        std::ofstream flux;
        flux.open("TestMatrice_ErrReport.txt");

        std::cout << "Echec du test." << std::endl;

        if(flux){

            flux << m_comment << std::endl;
            std::cout << "Rapport d'erreur enregistré." << std::endl;

        }
        else {std::cout << "Erreur : ErrReport n'a pas pu etre ecrit." << std::endl;}
    }




    return m_success;
}


bool TestMatrice::testProdMatriciel() {

    Matrice3 m1(1,2,3,4,5,6,7,8,9), m2(10,11,12,13,14,15,16,17,18);
    Matrice3 attendu(84,90,96,201,216,231,318,342,366) , res(m1 * m2);
    if (res != attendu){

        m_comment += ("Erreur dans le Produit Matriciel : Attendu : " + attendu.to_str() + " Obtenu : " + res.to_str() + "\n");
        return false;
    }

    return true;
}



bool TestMatrice::testTranspo() {

    Matrice3 m1(1,2,3,4,5,6,7,8,9), attendu(1,4,7,2,5,8,3,6,9);
    Matrice3 m2(m1.transp());

    if(m2 != attendu){

        m_comment += ("Erreur dans la classe Matrice : Attendu : " + attendu.to_str() + "Observé : " + m2.to_str());
        return false;
    }

    return true;
}



bool TestMatrice::testInv() {

    Matrice3 m1(1,2,3,4,5,6,7,8,10), attendu((-2./3.), (-4./3.), 1, (-2./3.), (11./3.), -2, 1, -2, 1);
    m1 = m1.inv();

    if(m1 != attendu){

        m_comment += ("Erreur dans la méthode Inv : Attendu : \n" + attendu.to_str() + "Observé : \n" + m1.to_str());
        return false;
    }

    return true;
}



bool TestMatrice::testDet() {

    Matrice3 m1(1,2,3,4,5,6,7,8,9), m2(1,2,3,4,5,6,7,8,10);
    double det1(m1.det()), det2(m2.det());

    if(abs(det1) > PREC){

        m_comment += ("Erreur dans la méthode Det : Attendu : " + std::to_string(PREC) + "Observé : " + std::to_string(det1));
        return false;
    }

    if(abs(det2 + 3) > PREC){

        m_comment += ("Erreur dans la méthode Det : Attendu : -3   Observé : ");
        m_comment += std::to_string(det2);
        return false;
    }

    return true;
}


