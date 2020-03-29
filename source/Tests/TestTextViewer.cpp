#include "Tests/TestTextViewer.h"
#include "../../headers/Tests/Unittest.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>


TestTextViewer::TestTextViewer() : Unittest()
{
    // ctor
}

TestTextViewer::~TestTextViewer()
{
    // dtor
}


bool TestTextViewer::run(){

// Tests

    try {

        m_success = (TestSysteme_B_OH() && TestSysteme_Conique() && SimulationTexte());

    }

// Gestion des exceptions système

    catch (std::exception const &e) {

        std::string alerte("Erreur systeme dans la classe Integrateur : ");
        alerte += e.what();
        alerte += " \n";
        m_comment += (alerte);
        m_success = false;
    }

    std::cout << "Test de la classe TextViewer" << std::endl;

    if (m_success) {

        std::cout << "Le test s'est correctement déroulé. Classe opérationnelle." << std::endl;
    } else {

        std::ofstream flux;
        flux.open("TestTextViewer_ErrReport.txt");

        std::cout << "Echec du test." << std::endl;

        if (flux) {

            flux << m_comment << std::endl;
            std::cout << "Rapport d'erreur enregistré." << std::endl;

        } else { std::cout << "Erreur : ErrReport n'a pas pu etre ecrit." << std::endl; }
    }

    return m_success;

}

bool TestTextViewer::TestSysteme_B_OH() {

    // Teste si un système se comporte bien comme 2 objets indépendants

    std::ofstream statsSyst ( "StatsTextViewer.txt" );

    double dt(0.01);

    Bille Bs (0,1,1,2);                                                 // Bille et oscillateur système
    Oscillateur OHs(Vecteur({1}), Vecteur({0}));

    Bille Bc(0,1,1,2);                                                 // Bille et oscillateur de contrôle
    Oscillateur OHc(Vecteur({1}), Vecteur({0}));

    IntegrateurEulerCromer Is(0.0);
    IntegrateurEulerCromer Ic(0.0);

    Systeme S((&Bs, &OHs), &Is);

    S.affiche(statsSyst);

    for (int k(0); k< 68 ; ++k) {

        S.evolue(dt);

        Ic.integre(Bc, dt);
        Ic.integre(OHc, dt);

        Ic.augmente_t(dt);


        double EcartBille(norme(S.getCorps(0)->getParam() - *Bc.getParam()));
        double EcartOH(norme(S.getCorps(1)->getParam() - *OHc.getParam()));


        if (EcartBille >= PREC){

            double t(k*dt);

            m_comment += "Erreur dans la classe Systeme : \n";
            m_comment += "Ecart trop eleve sur la bille: probleme d'integration au temps t=" + std::to_string(t) + "\n";
            m_comment += "Valeur observee : ";

            std::stringstream stream;
            stream << std::fixed << std::setprecision(log10(PREC)) << S.getCorps(0)->getParam();
            std::string BilleObs = stream.str();

            m_comment += BilleObs ;

            m_comment += "\n";
            m_comment += "Valeur attendue : ";

            stream.str(std::string());

            stream << std::fixed << std::setprecision(log10(PREC)) << Bc.getParam().to_str();
            std::string BilleReel = stream.str();

            m_comment += BilleReel;
            m_comment += "\n";

            return false;

        } else if (EcartOH >= PREC){

            double t(k*dt);

            m_comment += "Ecart trop eleve sur la bille: probleme d'integration au temps t=" + std::to_string(t) + "\n";
            m_comment += "Valeur observee : ";

            std::stringstream stream;
            stream << std::fixed << std::setprecision(log10(PREC)) << S.getCorps(1)->getParam();
            std::string OHObs = stream.str();

            m_comment += OHObs ;

            m_comment += "\n";
            m_comment += "Valeur attendue : ";

            stream.str(std::string());

            stream << std::fixed << std::setprecision(log10(PREC)) << OHc.getParam().to_str();
            std::string OHReel = stream.str();

            m_comment += OHReel;
            m_comment += "\n";

            return false;

        }


    }

    return true;



}


bool TestTextViewer::TestSysteme_Conique() {

    // Teste si la conique se comporte bien comme prévu

    std::ofstream statsSyst ( "StatsTextViewer.txt" );

    TextViewer T(statsSyst);

    ConeSimple C ({0,M_PI/6, 0}, {0,0,60}, 0.5, 1.5, 0.1);
    IntegrateurEulerCromer I(0.0);

    Systeme S ({*C}, *I);

    double dt(0.01);

    for (int k(0); k< 20; ++k){

        S.evolue(dt);
        T.dessine(S);

    }

    Vecteur attendu({0.0265555, 0.598869, 5.0944});

    if (S.getCorps(0)->getParam() == attendu) {

        return true;

    } else {

        m_comment += "Erreur dans la classe ConeSimple : \n";
        m_comment += "Valeur calculee : ";
        m_comment += S.getCorps(0)->getParam().to_str();
        m_comment += "\n";
        m_comment += "Valeur theorique : ";
        m_comment += attendu.to_str();
        m_comment += "\n";

        return false;

    }

}


bool TestTextViewer::SimulationTexte() {

    // teste la simulation de 2 toupies Coniques

    std::ofstream flux ("SimulationTexte.txt");

    ConeSimple C1((0,M_PI/6, 0), (0,0,60), 0.5, 1.5, 0.1);
    ConeSimple C2((0,M_PI/4, 0), (0,0,40), 0.5, 1.5, 0.1);

    IntegrateurEulerCromer I(0.0);

    Systeme S({*C1, *C2}, *I);

    TextViewer T(flux);

    double dt(0.01);

    flux << S << std::endl;

    for (int k(0); k<1000; ++k){

        S.evolue(dt);
        T.dessine(*S);

    }

    flux.close();
    return true;


}
