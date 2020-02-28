#include "Vecteur.h"
#include <vector>
#include <iostream>
#include <cmath>




double precision(1e-10);



void Vecteur::augmente(double coordSupplementaire){
    m_coords.push_back(coordSupplementaire); // avantage d'avoir pris vector
}



void Vecteur::setCoord(unsigned int nEmeCoord, double nouvelleValeur){ // on numérote les coordonnées d'un
    m_coords[nEmeCoord] = nouvelleValeur;                              // Vecteur comme celles d'un vector
}



void Vecteur::affiche() const{
    for (size_t k(0); k < m_coords.size(); ++k) {
        std::cout << m_coords[k] << " , "; // affichage avec virgules entre (plus clair pour nous)
    }
    std::cout << std::endl;
}



bool Vecteur::compare(Vecteur vecteur2) const{
    bool egalite(true);
    size_t k(0); // deux indicateurs pour ne pas tester des égalités pour rien

    if ( m_libelle == vecteur2.m_libelle ){ // Il faut qu'ils soient du même type. On ne compare pas les physiciens
            // et les SV, alors pas les forces et les vitesses non plus !
        if (vecteur2.m_coords.size() == m_coords.size()){ // test que ce soient bien le même nombre de ooordonnées
            while (k < m_coords.size() and egalite){ // on arrête si tout a été testé ou si on sait que ce
                                                    // n'est pas égal
                if (abs( vecteur2.m_coords[k] - m_coords[k] ) > precision) egalite = false;
                ++k;
            }
        } else {
            egalite = false;
        }
    } else {
        egalite = false;
        throw "taille incompatible"; // nous avons envie de déclarer l'erreur : nous avons mal utilisé la fonction...
                                    // De plus, dans les autres fonctions nous allons aussi utiliser cette erreur
    }

    return egalite;
}



Vecteur Vecteur::addition(Vecteur vecteur2) const{
    if (m_coords.size() != vecteur2.m_coords.size()){
        throw "taille incompatible";
        return vecteur2; // il y a erreur donc quoique l'on choisisse de retourner, ce sera un mauvais choix...
    } else {
        Vecteur sortie;
        sortie.m_libelle = vecteur2.m_libelle; // on n'additionne que des vecteurs du même type (mêmes unités...)
        for (size_t k(0); k < m_coords.size(); ++k){
            sortie.augmente(m_coords[k]+vecteur2.m_coords[k]);
        }
        return sortie;
    }
}



Vecteur Vecteur::mult(double scalaire) const{ // on multiplie chaque coordonnée par le scalaire
    Vecteur sortie;
    sortie.m_libelle = m_libelle;
    for (size_t k(0); k < m_coords.size(); ++k){
        sortie.augmente(scalaire*m_coords[k]);
    }
    return sortie;
}



Vecteur Vecteur::soustr(Vecteur vecteur2) const{ // Je ne sais pas comment faire ref au vecteur que l'on traite
                                                // dans la fonction, donc c'est du copié-collé :/
    if (m_coords.size() != vecteur2.m_coords.size()){
        throw "taille incompatible";
        return vecteur2; // il y a erreur donc quoique l'on choisisse de retourner, ce sera un mauvais choix...
    } else {
        Vecteur sortie;
        sortie.m_libelle = vecteur2.m_libelle; // on n'additionne que des vecteurs du même type (mêmes unités...)
        for (size_t k(0); k < m_coords.size(); ++k){
            sortie.augmente(m_coords[k]-vecteur2.m_coords[k]);
        }
        return sortie;
    }
}



Vecteur Vecteur::oppose() const{
    Vecteur sortie;
    sortie.m_libelle = m_libelle;
    for (size_t k(0); k < m_coords.size(); ++k){
        sortie.augmente(-1*m_coords[k]);
    }
    return sortie;
}



double Vecteur::prodScalaire(Vecteur vecteur2) const{

    if (m_coords.size() != vecteur2.m_coords.size()){
        throw "taille incompatible";
        return 1e10; // un exemple... très mauvais! Il faut return qqch de mieux... (exemples sur progmaph)
    } else {
        double sortie;
        for (size_t k(0); k < m_coords.size(); ++k){
            sortie += m_coords[k]*vecteur2.m_coords[k]; // definition du produit scalaire dans les coordonnées
                                                        // carthésiennes
        }
        return sortie;
    }
}



Vecteur Vecteur::prodVectoriel(Vecteur vecteur2) const{
    Vecteur sortie;

    if (m_coords.size() != 3 or vecteur2.m_coords.size() != 3){ // le produit vectoriel n'est défini que comme
                                            // opération R^3 --> R^3
        throw "taille incompatible";
        return sortie;

    } else { // opérations du produit vectoriel

        sortie.augmente(m_coords[2]*vecteur2.m_coords[3] - m_coords[3]*vecteur2.m_coords[2]);
        sortie.augmente(m_coords[3]*vecteur2.m_coords[1] - m_coords[1]*vecteur2.m_coords[3]);
        sortie.augmente(m_coords[1]*vecteur2.m_coords[2] - m_coords[2]*vecteur2.m_coords[1]);

    }


    return sortie;
}



double Vecteur::norme() const{ // Pythagore à n dimensions
    double sortie(0);
    for (size_t k(0); k < m_coords.size(); ++k) sortie += m_coords[k]*m_coords[k];
    return sqrt(sortie);
}



double Vecteur::norme2() const{ // idem que norme() sauf pas de racine sur le résultat final
    double sortie(0);
    for (size_t k(0); k < m_coords.size(); ++k) sortie += m_coords[k]*m_coords[k];
    return sortie;
}


Vecteur Vecteur::unitaire() const{
    double longueur(0);
    for (size_t k(0); k < m_coords.size(); ++k) longueur += m_coords[k]*m_coords[k]; // Eviter de mettre des arguments
                                                                    // supplementaires pour la facilité d'utilisation
                                                                    // vs l'efficacité
    longueur = sqrt(longueur);
    if (longueur == 0) { // Eviter la future division par 0
        throw "Le vecteur nul n'a pas de direction";
        Vecteur sortie2;
        sortie2.m_libelle = m_libelle;
        for (size_t k(0); k < m_coords.size(); ++k){
          sortie2.m_coords[k] = 0.0;
        }
        return sortie2;
    }
    Vecteur sortie;
    sortie.m_libelle = m_libelle;
    for (size_t k(0); k < m_coords.size(); ++k) sortie.m_coords[k] = m_coords[k] / longueur;
    return sortie;
}
