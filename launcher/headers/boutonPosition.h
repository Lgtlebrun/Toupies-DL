#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QMessageBox>
#include "../../general/headers/Vecteur.h"

#ifndef BOUTONPOSITION_H
#define BOUTONPOSITION_H

enum Couleur {GRIS, BLEU};

class BoutonPosition : public QPushButton {

    /// Classe utilitaire. Un BoutonPosition représente un emplacement disponible
    /// dans l'espace simulable.

    Q_OBJECT

// ==== METHODES ====

public:

    BoutonPosition(Vecteur const&, QWidget* = nullptr); // Cstor

    void changeCouleur(Couleur);                        // Modifie la couleur du bouton
    void clickGestion();                                // Emet le signal adéquat

    // Accesseurs
    Couleur getCouleur(){return m_couleur;}
    Vecteur getPos(){return m_position;}

// ==== SIGNALS ====
signals:

    void newObjet();       // L'emplacement devient occupé. Le Grillage fabrique un objet.
    void supprObjet();     // L'emplacement est libéré. Le Grillage supprime l'objet correspondant.

// ==== ATTRIBUTS ====
private:

    Couleur m_couleur;          // Couleur du bouton
    QLabel* m_pastille;         // Gestion de la couleur

    Vecteur m_position;         // Position représentée dans l'espace simulable /!\ pas à l'échelle
};



#endif // BOUTONPOSITION_H
