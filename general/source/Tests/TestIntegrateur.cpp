#include "../../headers/Tests/TestIntegrateur.h"
#include <fstream>
#include <iostream>
#include "../../headers/TextViewer.h"


TestIntegrateur::TestIntegrateur() : Unittest() {}

bool TestIntegrateur::run() {
// Tests

    try {

        m_success = (testBilleEC() && testOHEC() && testConique());

    }

// Gestion des exceptions système

    catch (std::exception const &e) {

        std::string alerte("Erreur systeme dans la classe Integrateur : ");
        alerte += e.what();
        alerte += " \n";
        m_comment += (alerte);
        m_success = false;
    }


// Affichage


    std::cout << "Test de la classe Integrateur" << std::endl;

    if (m_success) {

        std::cout << "Le test s'est correctement déroulé. Classe opérationnelle." << std::endl;
    } else {

        std::ofstream flux;
        flux.open("TestIntegrateur_ErrReport.txt");

        std::cout << "Echec du test." << std::endl;

        if (flux) {

            flux << m_comment << std::endl;
            std::cout << "Rapport d'erreur enregistré." << std::endl;

        } else { std::cout << "Erreur : ErrReport n'a pas pu etre ecrit." << std::endl; }
    }

    return m_success;
}



bool TestIntegrateur::testBilleEC() {

    IntegrateurEulerCromer I(0);

    std::ofstream file("StatsBille.txt");
    std::string stats("0 1\n");

    TextViewer T(file);

    Bille B(T, Vecteur({0,0,1}),Vecteur({1,0,2}), 0.2);         // Initialisation de la bille selon l'exo 7 du projet
    double dt(0.01);

    for (size_t i(0); i < 68 ; i++){

        I.integre(B, dt);
        I.augmente_t(dt);
        stats += (std::to_string(B.getParam().getCoord(0)) + " " + std::to_string(B.getParam().getCoord(2)) + "\n");
    }


    // On inscrit les stats dans un fichier

    if (file){
        file << stats;
    }

    Vecteur attendu({0.68, 0, 0.058574});           // nous vérifions que nous avons les mêmes résultats

    if ((B.getParam()-attendu).norme() > 1e-14) {      // Opérateur surchargé : PREC = 1e-14

        m_comment += "Erreur dans la classe IntegrateurEulerCromer sur la bille : Attendu :";
        m_comment += attendu.to_str();
        m_comment += " Constaté : ";
        m_comment += B.getParam().to_str();
        m_comment += "\n";
        return false;
    }

    return true;
}







bool TestIntegrateur::testOHEC() {

    std::ofstream file("StatsOH.txt");

    std::string stats("0 1\n");

    TextViewer T(file);

    IntegrateurEulerCromer I(0);
    double dt(0.01);

    Oscillateur OH(T, Vecteur({1}), Vecteur({0}), Vecteur({0}), 0.1);
                                     // Initialisation pour une vérif facile

    double err_rel(0);

    for(size_t i(0); i < 68; i++){

        I.integre(OH, dt);
        I.augmente_t(dt);

        double newErr_rel(fabs((cos(I.getTemps()) - OH.getParam().getCoord(0))/cos(I.getTemps())));

        if(newErr_rel > err_rel) {err_rel = newErr_rel;}

        stats += (std::to_string(I.getTemps()) + " " + std::to_string(OH.getParam().getCoord(0)) + "\n");

    }
    // On écrit les stats dans un fichier pour les plotter

    if (file){
        file << stats;
    }

    // Etude de l'erreur relative observée par rapport à la fonction cos(t)

    double precision(0.005);
    if (err_rel > precision){
        m_comment += "Erreur dans le test d'IntegrateurEC sur l'OH : Erreur relative tolérée :";
        m_comment +=  std::to_string(precision) + " Observé : ";
        m_comment += std::to_string(err_rel);
        m_comment += "\n";

        return false;
    }

    return true;
}



bool TestIntegrateur::testConique() {

    bool sortie(true);

    IntegrateurNewmark N(0);
    IntegrateurRK4 R(0);

    std::ofstream fileN("StatsConiqueNewmark.txt");
    std::ofstream fileR("StatsConiqueRK4.txt");

    TextViewer Tn(fileN), Tr(fileR);

    ConeSimple C(Tn, {0.523599, 0., 0.}, {0., 0., 60.}, Vecteur(), 0.5, 1.5, 0.1);

    Systeme Sn(Tn, N);
    Systeme Sr(Tr, R);

    Sn.addObjet(C);
    Sr.addObjet(C);

    std::string saveN(""), saveR("");

    double err_rel(0), dt(0.01);

    saveN += (std::to_string(0) + ' ' + Sn.getCorps(0)->getParametre().to_mathString() + '\n');
    saveR += (std::to_string(0) + ' ' + Sr.getCorps(0)->getParametre().to_mathString() + '\n');


    for(size_t i(0); i < 19; i++){

        Sr.evolue(dt);
        Sn.evolue(dt);

        saveN += (std::to_string(dt * (i+1)) + ' ' + Sn.getCorps(0)->getParametre().to_mathString() + '\n');
        saveR += (std::to_string(dt * (i+1)) + ' ' + Sr.getCorps(0)->getParametre().to_mathString() + '\n');

    }

    // Enregistrement des résultats
    if(fileN) {fileN << saveN;}
    if(fileR) {fileR << saveR;}

    Vecteur attendu({0.594739, 0.0264512, 5.09449});

    if ((Sr.getCorps(0)->getParametre() - attendu).norme() > 1e-5){
        sortie = false;

        m_comment += ("Erreur dans le test d'IntegrateurRK4 : valeur attendue " + attendu.to_str() + "; Observé : "
                + Sr.getCorps(0)->getParametre().to_str() + '\n');
    }

    attendu = Vecteur({0.594753, 0.0264531, 5.09449});

    if ((Sn.getCorps(0)->getParametre() - attendu).norme() > 1e-4){
        sortie = false;

        m_comment += ("Erreur dans le test d'IntegrateurNewmark : valeur attendue " + attendu.to_str() + "; Observé : "
                      + Sn.getCorps(0)->getParametre().to_str() + '\n');
    }

    return sortie;
}