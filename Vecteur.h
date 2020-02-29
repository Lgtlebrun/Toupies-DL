#ifndef DEF_VECTEUR
#define DEF_VECTEUR


#include <vector>
#include <string>
#include <iostream>

class Vecteur{


    public:

        Vecteur();                                                          // Constructeur par défaut

        Vecteur(std::initializer_list<double> il);                          // Constructeur à base d'une liste


        unsigned int getDim() const;                                        // Accesseur à la dimension du vecteur


        void augmente(double coordSupplementaire);                          // augmente la taille du Vecteur.


        void setCoord(unsigned int nEmeCoord, double nouvelleValeur);       // get et set pour une seule coordonnée


        double getCoord(unsigned int nEmeCoord) const;


        double norme() const;                                               // Calcule la norme d'un vecteur


        double norme2() const;                                              // Calcule la norme au carré d'un vecteur


        Vecteur unitaire() const;                                           // Retourne le vecteur unitaire (même dimension, même sens)



    // ================ OPERATEURS INTERNES ==================================================================


        bool operator==(Vecteur const& v2);                         // Comparaison


        bool operator!=(Vecteur const& v2);                         // Anti-comparaison


        double operator*(Vecteur const& v2);                        // Produit scalaire


        const Vecteur operator-();                                        // Opposé


        Vecteur& operator+=(Vecteur const& v2);                     // Addition à lui même d'un vecteur v2


        Vecteur& operator-=(Vecteur const& v2);                     // Soustraction à lui-même d'un vecteur v2


        const Vecteur operator*(double const& lambda);              // Multiplication par scalaire à droite


        const Vecteur operator^(Vecteur const& v2);                 // Produit vectoriel


    //=============================================================================================


    private:

    /* Attributs */

        std::vector <double> m_coords;                 // Stockage des coordonnées en tableau dynamique

        void rationnalise();                           // Méthode arrondissant les petites coordonnées à 0



    /* Méthodes nécessaires en interne */

        Vecteur prodVectoriel(Vecteur const& vecteur2) const;               // Produit vectoriel classique somme toutes

        double prodScalaire(Vecteur const &vecteur2) const;                 // Produit scalaire entre deux vecteurs

        Vecteur mult(double scalaire) const;                                // Multiplie un vecteur par un scalaire (un réel)

        Vecteur addition(Vecteur const& vecteur2) const;                    // Addition de deux vecteurs

};


//=====================================  OPERATEURS EXTERNES  ============================================


        const Vecteur operator+(Vecteur const& v1, Vecteur const& v2);                 // Addition


        const Vecteur operator-(Vecteur const& v1, Vecteur const& v2);                 // Soustraction


        const Vecteur operator*(double lambda, Vecteur v1);        // Multiplication par scalaire à gauche


        std::ostream& operator<<(std::ostream& sortie, Vecteur const& v); // Affichage du vecteur


//==========================================================================================================

#endif // DEF_VECTEUR
