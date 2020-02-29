#ifndef DEF_VECTEUR
#define DEF_VECTEUR


#include <vector>
#include <string>

class Vecteur{


    public:

        Vecteur();                                                          // Constructeur par défaut

        Vecteur(std::initializer_list<double> il);                          // Constructeur à base d'une liste


        unsigned int getDim() const;                                        // Accesseur à la dimension du vecteur


        void augmente(double coordSupplementaire);                          // augmente la taille du Vecteur.


        void setCoord(unsigned int nEmeCoord, double nouvelleValeur);


        void affiche() const;                                               // affiche les coordonnées du vecteur dans le terminal


        bool compare(Vecteur const& vecteur) const;                         // Comparaison : dimensions, coordonnées.


        Vecteur addition(Vecteur const& vecteur2) const;                    // Addition de deux vecteurs


        Vecteur soustr(Vecteur const& vecteur2) const;                      // Soustraction de deux vecteurs


        Vecteur oppose() const;                                             // Retourne l'opposé (donc signe négatif) du vecteur


        Vecteur mult(double scalaire) const;                                // Multiplie un vecteur par un scalaire (un réel)


        double prodScalaire(Vecteur const &vecteur2) const;                 // Produit scalaire entre deux vecteurs


        Vecteur prodVectoriel(Vecteur const& vecteur2) const;               // Produit vectoriel classique somme toutes


        double norme() const;                                               // Calcule la norme d'un vecteur


        double norme2() const;                                              // Calcule la norme au carré d'un vecteur


        Vecteur unitaire() const;                                           // Retourne le vecteur unitaire (même dimension, même sens)



    private:

        std::vector <double> m_coords;                 // Stockage des coordonnées en tableau dynamique

        void rationnalise();                           // Méthode arrondissant les petites coordonnées à 0


};


//=====================================  OPERATEURS SURCHARGES  ============================================


bool operator==(Vecteur const& v1, Vecteur const& v2);      // Comparaison

Vecteur operator+(Vecteur const& v1, Vecteur const& v2);    // Addition

Vecteur operator-(Vecteur const& v1, Vecteur const& v2);    // Soustraction

double operator*(Vecteur const& v1, Vecteur const& v2);     // Produit scalaire

Vecteur operator*(double lambda, Vecteur const& v1);        // Multiplication par scalaire à gauche

Vecteur operator*(Vecteur const& v1, double lambda);        // Multiplication par scalaire à droite

Vecteur operator^(Vecteur const& v1, Vecteur const& v2);    // Produit vectoriel



//==========================================================================================================

#endif // DEF_VECTEUR
