#include <vector>
#include <string>

class Vecteur{


    public:

        void augmente(double coordSupplementaire); // augmente la taille du Vecteur. Met coordSupplementaire en derniere
        // place


        void setCoord(unsigned int nEmeCoord, double nouvelleValeur); // modifie la coordonnée n du vecteur en mettant
        // nouvelleValeur à sa place


        void affiche() const; // affiche les coordonnées du vecteur dans le terminal


        bool compare(Vecteur vecteur) const; // sort true si les vecteurs ont la même dimension et si les coordonnées
        // des deux vecteurs sont au plus éloignées de 1e-10 une-à-une. sort false sinon
        // Les méthodes suivantes font d'abord un test de compabilité

        Vecteur addition(Vecteur vecteur2) const; // addition de deux vecteurs


        Vecteur soustr(Vecteur vecteur2) const; // soustraction de deux vecteurs


        Vecteur oppose() const; // sort l'opposé (donc signe négatif) du vecteur


        Vecteur mult(double scalaire) const; // multiplie un vecteur par un scalaire (un réel)


        double prodScalaire(Vecteur vecteur2) const; // produit scalaire entre deux vecteurs


        Vecteur prodVectoriel(Vecteur vecteur2) const; // produit vectoriel classique somme toutes

            // A noter :
                // si on veut faire 3*v, il faudra écrire v = v.mult(3.0)...


        double norme() const; // calcule la norme d'un vecteur
        double norme2() const; // calcule la norme au carré d'un vecteur


        Vecteur unitaire() const; // sort un vecteur unitaire de même dimension et direction, mais de longueur 1

    private:

        std::vector <double> m_coords; // les coordonées du vecteur sont mises dans un vector afin de pouvoir
        // modifier la dimensionnalité du vecteur à souhait


        std::string m_libelle; // donner un type au vecteur pour faciliter son utilisation future
        // ex: vitesse, force, moment cinétique, etc...
};
