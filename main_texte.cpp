#include "general/headers/Tests/Oscillateur.h"
#include "general/headers/ConeSimple.h"
#include "general/headers/Systeme.h"
#include "general/headers/TextViewer.h"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    /* On initialise un TextViewer par où l'on souhaite qu'il écrive les résultats de l'intégration numérique */
    TextViewer TextV(cout);


    /* On initialise un intégrateur d'Euler-Cromer à t0 = 0.0s pour commencer l'intégration numérique
           A noter que dans l'exemple présenté, le temps initial n'importe que pour l'affichage du Systeme */
    IntegrateurEulerCromer IntE_C(0.0);


    /* On initialise un Systeme par un SupportADessin, qui affichera les Integrables. Dans l'exemple, TextViewer est  *
     * le SupportADessin qui dessinera le Systeme. De plus, il faut un Integrateur pour faire évoluer les Integrables */
    Systeme Syst(TextV, IntE_C);


    /* Nous initialisons un Oscillateur par le SupportADessin qui le dessinera (s'il ne fait pas partie d'un Systeme *
     * possédant un autre TextViewer). De plus il est initialisé en (0,0,1), avec une vitesse initiale de (0,0,-10)  *
     * et un centre du mouvement (=accélération nulle) de (0,0,0) ainsi qu'un rayon de 0.2m                          *
     *                          position        vitesse       centre du mvt  rayon                                   */
    Oscillateur O(TextV, {0.0,0.0,1.0}, {0.0,0.0,-10.0}, {0.0,0.0,0.0}, 0.2);

    /* Nous initialisons un ConeSimple par le SupportADessin qui le dessinera, un vecteur contenant ses angles en *
     * radians, les vitesses angulaires associées et la position de la pointe. Puis par le rayon et la hauteur du *
     * cône, ainsi que sa masse volumique. z sera automatiquement mis à 0.                                        *
     *                     (theta,psy,phi)  (theta',psy',phi') (x,  y, z=0.0)   rayon, hauteur, masseVolumique    */
    ConeSimple C(TextV, {M_PI/6,0.0,0.0}, {0.0,0.0,60.0},  {2.0,2.0,2.0}, 1.5,    0.5,       0.1);


    /* On ajoute les intégrables au Systeme un par un. */
    Syst.addIntegrable(O);
    Syst.addIntegrable(C);

    /* Nous posons le dt de l'intégration numérique à 0.001 */
    double dt(0.001);

    /* On affiche le Systeme dans un ostream, ce qui permet un affichage en plus de profondeur que ne le permet *
     * Systeme::dessine(), quelques lignes plus bas                                                             */
    Syst.affiche(cout);

    /* 1000 itérations (1s de simulation) où nous faisons évoluer le système de dt à chaque étape puis le dessinons *
     * à chaque 0.001s                                                                                              */
    for (int k(0); k < 1000 ; ++k) {

        Syst.evolue(dt);
        Syst.dessine();

    }
    

    return 0;
}