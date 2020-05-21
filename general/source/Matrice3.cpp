#include "../headers/Matrice3.h"
#include <iostream>
#include <cmath>
#include <vector>




Matrice3::Matrice3(): m_coords({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}) {}
/* Le constructeur par défaut renvoie la matrice identité */


Matrice3::Matrice3( double l1c1, double l1c2, double l1c3,
                    double l2c1, double l2c2, double l2c3,
                    double l3c1, double l3c2, double l3c3) : m_coords({{l1c1, l1c2, l1c3}, {l2c1, l2c2, l2c3}, {l3c1, l3c2, l3c3}}) {}
/* Constructeur sur demande */

Matrice3::~Matrice3()
{
    //dtor
}

// ==================================================================================================

void Matrice3::setCoord(size_t ligne, size_t colonne, double valeur){
/* Permet de fixer une case d'une matrice en particulier */
    m_coords[ligne].setCoord(colonne, valeur);

}


Vecteur Matrice3::getLigne(size_t indice) const{
/* Accesseur du indice-ème vecteur */

    if (m_coords.size() <= indice) {return Vecteur();}          // sort le vecteur nul si l'indice est trop grand

    return m_coords[indice];                                    // sinon sort le vecteur-ligne associé

}

// =================================================================================================

Matrice3& Matrice3::operator+=(Matrice3 const& autre){
/* Surcharge de l'addition interne */

    for (size_t i(0); i < 3; i++){

        m_coords[i] += autre.m_coords[i];                   // Note : besoin d'un .rationnalise()? Pour l'instant il semble que non
    }

    return *this;
}


Matrice3& Matrice3::operator-=(Matrice3 const& autre){
/* Surcharge de la soustraction interne */

    operator+=((-1)*autre);

    return *this;
}


Matrice3& Matrice3::operator*=(double const& lambda){
/* Multiplication par sclaire à droite */

    for (size_t i(0); i < 3; i++){

        m_coords[i] *= lambda;                   // Note : besoin d'un .rationnalise()?
    }

    return *this;
}

// ====================================================================================================

const Matrice3 operator*(double const& lambda, Matrice3 mat1){
/* Multiplication par scalaire à gauche */

    mat1 *= lambda;      // On procède par copie : mat1 n'est pas modifiée hors de la fonction
    return mat1;
}


const Matrice3 Matrice3::operator*(Matrice3 const& m2){
/* Surcharge du produit matriciel */

    Matrice3 sortie;

    Matrice3 m2_transp(m2.transp());

    for (size_t colonne(0); colonne < 3; colonne++){

        for(size_t ligne(0); ligne < 3; ligne++){       //L'utilisation de la transposée de m2 permet l'appel au produit scalaire

            sortie.setCoord(ligne, colonne, (m_coords[ligne]) * m2_transp.m_coords[colonne]);

        }
    }

    return sortie;

}

Vecteur operator*(Matrice3 const& M, Vecteur const& v) {

    Vecteur sortie;

    for (unsigned int i(0); i< 3; ++i) {

        sortie.setCoord(i, M.getLigne(i)*v);

    }

    return sortie;

}

// ====================================================================================================

bool Matrice3::operator==(Matrice3 const& autre) const{
/* Opérateur de comparaison */

    for (size_t i(0); i < m_coords.size(); i++){

        if (m_coords[i] != autre.m_coords[i])  {return false;}

                // utilisation de la comparaison vectorielle qui a une precision maximale pour l'ordinateur

    }

    return true;
}


bool Matrice3::operator!=(Matrice3 const& autre) const{
/* Opérateur de comparaison */

    return !(operator==(autre));

}

// ===================================================================================================

std::ostream& operator<<(std::ostream& flux, Matrice3 const& m1){
/* Surchage de l'opérateur << qui permet un affichage dans n'importe quel ostream */
    flux << std::endl;

    flux << m1.to_str() << std::endl;

    return flux;
}

// =================================================================================================

std::string Matrice3::to_str() const{
/* Permet de mettre une matrice sous forme de string */
    return (m_coords[0].to_str() + "\n" + m_coords[1].to_str() + "\n" + m_coords[2].to_str()+"\n");
}

// ================================================================================================

Matrice3 Matrice3::transp() const {
/* Méthode qui transpose la matrice */

    Matrice3 sortie ( m_coords[0].getCoord(0), m_coords[1].getCoord(0), m_coords[2].getCoord(0),
                      m_coords[0].getCoord(1), m_coords[1].getCoord(1), m_coords[2].getCoord(1),
                      m_coords[0].getCoord(2), m_coords[1].getCoord(2), m_coords[2].getCoord(2) );

    return sortie;

}


double Matrice3::det() const {
/* renvoie le déterminant de la matrice */

    double sortie(0.0);

    for (size_t k(0); k < 3 ; ++k) { sortie += m_coords[0].getCoord((0+k)%3)*m_coords[1].getCoord((1+k)%3)*m_coords[2].getCoord((2+k)%3); }

    for (size_t k(0); k < 3 ; ++k) { sortie -= m_coords[0].getCoord((1+k)%3)*m_coords[1].getCoord((0+k)%3)*m_coords[2].getCoord((2+k)%3); }


    return sortie;

    /* Le déterminant est défini comme étant la somme sur les permutations sigma du groupe symétrique d'ordre n de *
     * sgn(sigma) multiplié par le produit des A[i][sigma[i]]. Or, toute permutation paire de S_3 est une boucle   *
     * (1,2,3) étant décalée (i.e (2,3,1) et (3,1,2)), tandis qu'une permutation impaire est une permutation où    *
     * deux des éléments sont iterchangés (En effet, les permutations impaires sont (2,1,3), (3,2,1) et (1,3,2)).  *
     * Ainsi, à l'aide des modulos, nous arrivons à transcrire cette idée. En effet, les permutations paires       *
     * s'écrivent (k%3, (1+k)%3, (2+k)%3) et les impaires ((1+k)%3, k%3, (2+k)%3). d'où le corps de det().         */

}


Matrice3 Matrice3::inv() const {
/* Retourne l'inverse d'une matrice                                   *

 * Explications à la fin du code et dans le chapitre 4 de JOURNAL.txt */

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


    /* Nous avons écrit la méthode via les cofacteurs et d'une telle façon de que l'algorithme est seulement fait *
     * en 9 étapes (les 9 cases de la matrice) alors qu'il serait de 27 étapes si codé autrement (calcul du       *
     * déterminant non-compris). Quand nous calculons une matrice des cofacteurs à la main, nous nous occupons    *
     * d'abord du contenu de la case, puis de son signe, puis de la transposer.                                   *
     * Expliquons donc ceci dans cet ordre. Quand nous calculons la case de la matrice des cofacteurs, nous       *
     * "cachons" les lignes et colonnes de la matrice dont on veut calculer l'inverse.                            *
     * Ceci veut dire que si nous calculons Cof(A)[0][1], alors nous prenons les cases A[1][0], A[2][0], A[1][2]  *
     * et A[2][2] pour calculer un determinant avec (nous sommes passé à une notation informatique). Notons que   *
     * 1=(0+1)%3 et 2=(0-1)%3 (en maths).                                                                         *
     * C'est donc ceci que nous faisons. Cof(A)[k][t]=produit des max et min de (k+-1)%3 et (t+-1)%3 - le produit *
     * du max et du min. Or, en c++, le modulo est à valeur négative. Donc si c'est négatif, c'est forcément -1.  *
     * Il faut alors changer le min en l'ancienne valeur du max et que le max ait la valeur 2 (car 2 est la       *
     * valeur maximale, et c'est impossible que nous ayons 2 fois la même valeur).                                *
     * Une fois ceci fait, il faut s'occuper du signe. Il est (-1)^(i+j) où i,j appartiennent à {1,2,3} en maths. *
     * Or dans le code, k et t appartiennent à {0,1,2}. Nous nous retrouvons donc avec (-1)^((k+1)+(t+1))=        *
     * (-1)^(k+t+2)=(-1)^(k+t)*(-1)^2=(-1)^(k+t), qui est le facteur devant le déterminant.                       *
     * Nous avons donc, à ce stade, la matrice des cofacteurs, Cof(A).                                            *
     * Pour reprendre la formule, il ne reste plus qu'à transposer la matrice pour avoir la matrice inverse. Donc *
     * il nous suffit de dire que Cof(A^T)[k][t]=Cof(A)[t][k] et de multiplier Cof(A^T) par 1/det(A).             */



}