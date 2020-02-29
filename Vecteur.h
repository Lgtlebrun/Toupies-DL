#ifndef DEF_VECTEUR
#define DEF_VECTEUR


#include <vector>
#include <string>

class Vecteur{


    public:

        Vecteur();                                                          // Constructeur par d�faut

        Vecteur(std::initializer_list<double> il);                          // Constructeur � base d'une liste


        unsigned int getDim() const;                                        // Accesseur � la dimension du vecteur


        void augmente(double coordSupplementaire);                          // augmente la taille du Vecteur.


        void setCoord(unsigned int nEmeCoord, double nouvelleValeur);


        void affiche() const;                                               // affiche les coordonn�es du vecteur dans le terminal


        bool compare(Vecteur const& vecteur) const;                         // Comparaison : dimensions, coordonn�es.


        Vecteur addition(Vecteur const& vecteur2) const;                    // Addition de deux vecteurs


        Vecteur soustr(Vecteur const& vecteur2) const;                      // Soustraction de deux vecteurs


        Vecteur oppose() const;                                             // Retourne l'oppos� (donc signe n�gatif) du vecteur


        Vecteur mult(double scalaire) const;                                // Multiplie un vecteur par un scalaire (un r�el)


        double prodScalaire(Vecteur const &vecteur2) const;                 // Produit scalaire entre deux vecteurs


        Vecteur prodVectoriel(Vecteur const& vecteur2) const;               // Produit vectoriel classique somme toutes


        double norme() const;                                               // Calcule la norme d'un vecteur


        double norme2() const;                                              // Calcule la norme au carr� d'un vecteur


        Vecteur unitaire() const;                                           // Retourne le vecteur unitaire (m�me dimension, m�me sens)



    private:

        std::vector <double> m_coords;                 // Stockage des coordonn�es en tableau dynamique

        void rationnalise();                           // M�thode arrondissant les petites coordonn�es � 0


};


//=====================================  OPERATEURS SURCHARGES  ============================================


bool operator==(Vecteur const& v1, Vecteur const& v2);      // Comparaison

Vecteur operator+(Vecteur const& v1, Vecteur const& v2);    // Addition

Vecteur operator-(Vecteur const& v1, Vecteur const& v2);    // Soustraction

double operator*(Vecteur const& v1, Vecteur const& v2);     // Produit scalaire

Vecteur operator*(double lambda, Vecteur const& v1);        // Multiplication par scalaire � gauche

Vecteur operator*(Vecteur const& v1, double lambda);        // Multiplication par scalaire � droite

Vecteur operator^(Vecteur const& v1, Vecteur const& v2);    // Produit vectoriel



//==========================================================================================================

#endif // DEF_VECTEUR
