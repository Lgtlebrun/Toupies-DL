#include <fstream>
#include <cmath>
#include "../../headers/TextViewer.h"
#include "../../headers/Tests/TestSysteme.h"






TestSysteme::TestSysteme() : Unittest() {}

bool TestSysteme::run() {

    // Tests

    try {

        m_success = test_evol();
    }

    // Gestion des exceptions système

    catch (std::exception const& e) {

        std::string alerte("Erreur systeme dans la classe Systeme : ");
        alerte += e.what();
        alerte += " \n";
        m_comment += (alerte);
        m_success = false;
    }



    // Affichage


    std::cout << "Test de la classe Systeme" << std::endl;

    if (m_success) {

        std::cout << "Le test s'est correctement déroulé. Classe opérationnelle." << std::endl;
    } else {

        std::ofstream flux;
        flux.open("TestSysteme_ErrReport.txt");

        std::cout << "Echec du test." << std::endl;

        if (flux) {

            flux << m_comment << std::endl;
            std::cout << "Rapport d'erreur enregistré." << std::endl;

        } else { std::cout << "Erreur : ErrReport n'a pas pu etre ecrit." << std::endl; }
    }


    return m_success;
}





bool TestSysteme::test_evol() {

    /// Teste le comportement d'un systeme composé d'un cone simple


    // Ouverture d'un fichier qui recevra les données du systeme
    std::string file("StatsSys.txt");
    std::ofstream statsSyst(file.c_str());


    double dt(0.01);


    if(statsSyst) {
        TextViewer T(statsSyst);

        ConeSimple Ct (T, {0,M_PI/6, 0}, {0,0,60}, {0.0,0.0,0.0}, 0.5, 1.5, 0.1);
        IntegrateurEulerCromer It(0.0);

        Systeme S(T, It);

        S.addIntegrable(Ct);


        statsSyst << S;


        for (size_t k(0); k < 68; ++k) {

            S.evolue(dt);
            S.dessine();

            It.integre(Ct, dt);
            It.augmente_t(dt);


            double EcartConique(fabs(S.getCorps(0)->getParam().norme() - Ct.getParam().norme()));

            double t(It.getTemps());


            if (EcartConique >= PREC) {

                dispErrorInteg(t, Ct.getParam().to_str(), S.getCorps(0)->getParam().to_str());

                return false;
            }


        }

        statsSyst.close();
    }
    else{
        m_comment += ("Erreur: impossible d'ouvrir le fichier " + file);
        return false;
    }

    return true;

}




void TestSysteme::dispErrorInteg(double const& t, std::string const& attendu, std::string const& constat) {

    /// Enregistre un message d'erreur au bon format (contexte : intégration)

    m_comment += "Ecart trop eleve sur la bille: probleme d'integration au temps t=" + std::to_string(t) + "\n";
    m_comment += "Valeur observee : ";


    m_comment += constat;

    m_comment += "\nValeur attendue : ";


    m_comment += attendu;
    m_comment += "\n";

}




