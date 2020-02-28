#ifndef DEF_VECTEUR
#define DEF_VECTEUR


#include <vector>
#include <string>

class Vecteur{


    public:


        void augmente(double coordSupplementaire); // augmente la taille du Vecteur. Met coordSupplementaire en derniere
        // place


        void setCoord(unsigned int nEmeCoord, double nouvelleValeur); // modifie la coordonn�e n du vecteur en mettant
        // nouvelleValeur � sa place


        void affiche() const; // affiche les coordonn�es du vecteur dans le terminal


        bool compare(Vecteur const& vecteur) const; // sort true si les vecteurs ont la m�me dimension et si les coordonn�es
        // des deux vecteurs sont au plus �loign�es de 1e-10 une-�-une. sort false sinon
        // Les m�thodes suivantes font d'abord un test de compabilit�

        Vecteur addition(Vecteur const& vecteur2) const; // addition de deux vecteurs


        Vecteur soustr(Vecteur const& vecteur2) const; // soustraction de deux vecteurs


        Vecteur oppose() const; // sort l'oppos� (donc signe n�gatif) du vecteur


        Vecteur mult(double scalaire) const; // multiplie un vecteur par un scalaire (un r�el)


        double prodScalaire(Vecteur const &vecteur2) const; // produit scalaire entre deux vecteurs


        Vecteur prodVectoriel(Vecteur const& vecteur2) const; // produit vectoriel classique somme toutes

            // A noter :
                // si on veut faire 3*v, il faudra �crire v = v.mult(3.0)...


        double norme() const; // calcule la norme d'un vecteur


        double norme2() const; // calcule la norme au carr� d'un vecteur


        Vecteur unitaire() const; // sort un vecteur unitaire de m�me dimension et direction, mais de longueur 1



    private:

        std::vector <double> m_coords; // les coordon�es du vecteur sont mises dans un vector afin de pouvoir
        // modifier la dimensionnalit� du vecteur � souhait


};

#endif // DEF_VECTEUR
