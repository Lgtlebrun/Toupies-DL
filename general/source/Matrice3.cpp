#include "../headers/Matrice3.h"
#include <iostream>
#include <cmath>
#include <vector>




Matrice3::Matrice3(): m_coords({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}})

        /// Le constructeur par défaut renvoie la matrice identité
{
}

Matrice3::Matrice3( double l1c1, double l1c2, double l1c3,
                    double l2c1, double l2c2, double l2c3,
                    double l3c1, double l3c2, double l3c3) : m_coords({{l1c1, l1c2, l1c3}, {l2c1, l2c2, l2c3}, {l3c1, l3c2, l3c3}})

        /// Constructeur sur demande
{

}


Matrice3::~Matrice3()
{
    //dtor
}



void Matrice3::setCoord(size_t ligne, size_t colonne, double valeur){

    m_coords[ligne].setCoord(colonne, valeur);

}







Matrice3& Matrice3::operator+=(Matrice3 const& autre){

    /// Surcharge de l'addition interne


    for (size_t i(0); i < 3; i++){

        m_coords[i] += autre.m_coords[i];                   // Note : besoin d'un .rationnalise()? Pour l'instant il semble que non
    }

    return *this;
}





Matrice3& Matrice3::operator-=(Matrice3 const& autre){

        /// Surcharge de la soustraction interne

    operator+=((-1)*autre);

    return *this;
}





Matrice3& Matrice3::operator*=(double const& lambda){

    /// Multiplication par sclaire à droite

    for (size_t i(0); i < 3; i++){

        m_coords[i] *= lambda;                   // Note : besoin d'un .rationnalise()?
    }

    return *this;
}



bool Matrice3::operator==(Matrice3 const& autre) const{

    /// Opérateur de comparaison


    for (size_t i(0); i < m_coords.size(); i++){

        if (m_coords[i] != autre.m_coords[i])  {return false;}      // utilisation de la comparaison vectorielle
                                                                    // qui a une precision de 1e-14

    }

    return true;
}





bool Matrice3::operator!=(Matrice3 const& autre) const{

    /// Opérateur de comparaison


    return !(operator==(autre));
}






Vecteur Matrice3::getLigne(size_t indice) const{

        /// Accesseur du indice-ème vecteur

    if (m_coords.size() <= indice) {return Vecteur();}          // sort le vecteur nul si l'indice est trop grand

    return m_coords[indice];                                    // sinon sort le vecteur-ligne associé

}








Matrice3 Matrice3::transp() const {

        /// Méthode qui transpose la matrice

    Matrice3 sortie ( m_coords[0].getCoord(0), m_coords[1].getCoord(0), m_coords[2].getCoord(0),
                      m_coords[0].getCoord(1), m_coords[1].getCoord(1), m_coords[2].getCoord(1),
                      m_coords[0].getCoord(2), m_coords[1].getCoord(2), m_coords[2].getCoord(2) );


    return sortie;


}



double Matrice3::det() const {

        /// renvoie le déterminant de la matrice

    double sortie(0.0);

    for (size_t k(0); k < 3 ; ++k) { sortie += m_coords[0].getCoord((0+k)%3)*m_coords[1].getCoord((1+k)%3)*m_coords[2].getCoord((2+k)%3); }

    for (size_t k(0); k < 3 ; ++k) { sortie -= m_coords[0].getCoord((1+k)%3)*m_coords[1].getCoord((0+k)%3)*m_coords[2].getCoord((2+k)%3); }


    return sortie;

    // Utilise la définition du déterminant à l'aide des permutations de l'ensemble {0,1,2} pour arriver à ce code.
    // Plus d'explications dans le chapitre 4 de JOURNAL.txt

}



Matrice3 Matrice3::inv() const {

        /// Retourne l'inverse d'une matrice

        // Explications à la fin du code et dans le chapitre 4 de JOURNAL.txt

    double deter(det());

    if (fabs(deter) < PREC && deter >= 0) { deter = PREC; }

    else if (fabs(deter) < PREC && deter < 0) { deter = -PREC; }


    Matrice3 cofacteurs;


    for(int k(0); k < 3; ++k) {                         // /!\ int importants pour le modulo !

        for (int t(0); t < 3 ; ++t) {

        int MAX_k (std::max((k-1)%3, (k+1)%3));
        int MIN_k (std::min((k-1)%3, (k+1)%3));

        int MAX_t (std::max((t-1)%3, (t+1)%3));
        int MIN_t (std::min((t-1)%3, (t+1)%3));

        if (MIN_k == -1) {

            MIN_k = MAX_k;

            MAX_k = 2;

        }

        if (MIN_t == -1) {

            MIN_t = MAX_t;

            MAX_t = 2;

        }


        cofacteurs.m_coords[t].setCoord(k, pow(-1, k+t) * ( m_coords[MAX_k].getCoord(MAX_t) * m_coords[MIN_k].getCoord(MIN_t)
                                       - m_coords[MAX_k].getCoord(MIN_t) * m_coords[MIN_k].getCoord(MAX_t) )        );


        }


    }


    return (1.0/deter) * cofacteurs;


    // Ce code utilise un algorithme pour calculer un inverse d'une matrice via la méthode des cofacteurs et ne marche
    // Que dans le case des matrices 3x3. Il s'appuie sur le fait que pour cahcher une des colonnes, alors les colonnes
    // restantes sont (k-1)%3 et (k+1)%3 (idem pour les lignes) puis utilise le "produit en croix" du déterminant d'une
    // matrice 2x2 pour calculer le terme de chaque case de la matrice des cofacteurs.


            // Plus de détails dans JOURNAL.txt



}



const Matrice3 operator*(double const& lambda, Matrice3 mat1){

    /// Multiplication par scalaire à gauche

    mat1 *= lambda;      // On procède par copie : mat1 n'est pas modifiée hors de la fonction
    return mat1;
}




const Matrice3 Matrice3::operator*(Matrice3 const& m2){

        /// Surcharge du produit matriciel

    Matrice3 sortie;

    Matrice3 m2_transp(m2.transp());

    for (size_t colonne(0); colonne < 3; colonne++){

        for(size_t ligne(0); ligne < 3; ligne++){       //L'utilisation de la transposée de m2 permet l'appel au produit scalaire

            sortie.setCoord(ligne, colonne, (m_coords[ligne]) * m2_transp.m_coords[colonne]);

        }
    }


    for (auto& elt : sortie.m_coords) {elt.rationnalise();}

    return sortie;


}

std::string Matrice3::to_str() const{

    return (m_coords[0].to_str() + "\n" + m_coords[1].to_str() + "\n" + m_coords[2].to_str()+"\n");
}


const std::ostream& operator<<(std::ostream& flux, Matrice3 const& m1){

    flux << std::endl;

    flux << m1.to_str() << std::endl;

    return flux;
}




