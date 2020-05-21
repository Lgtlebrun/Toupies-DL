#include <QApplication>
#include "glwidget.h"
#include <iostream>
#include "../general/headers/Tests/Bille.h"
#include "../general/headers/TextViewer.h"
#include <iostream>
#include <cmath>
#include <string>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    TextViewer Graphique(std::cout);    // On initialise un TextViewer sur cout pour faire marcher le programme

        // Plusieurs objets type

    ConeSimple C(Graphique, {M_PI/6,0.0,0.0},{0.0,0.0,60},{0.0,2.0,0.0},0.5,1.5,0.1);
    Oscillateur O(Graphique, {0.0,0.0,0.0}, {0.0,-1.0,1.0}, {-3.0,0.0,0.0}, 1);
    Bille B(Graphique, {1.0,0.0,2.0},{2.0,0.0,3.0},2);

        // On initialise un intégrateur de Euler-Cromer

    IntegrateurEulerCromer I(0.0);

        // Un système est ensuite initialisé pour afficher les objets et les faire évoluer à l'aide de I

    Systeme S(Graphique,I);
    S.addIntegrable(C);
    S.addIntegrable(O);
    S.addIntegrable(B);

        /* On initialise un GLWidget qui prend comme objet à faire évoluer le système, ce qui change le SupportADessin *
         * de Graphique à une vue_opengl                                                                              */

    GLWidget w(S);

    w.show();

    return a.exec();
}

