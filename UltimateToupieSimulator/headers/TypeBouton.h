#include <QPushButton>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QMovie>


#ifndef TYPEBOUTON_H
#define TYPEBOUTON_H

enum Type {CONE, CHINOISE, OSCILLATEUR, BILLE, Null};

class TypeBouton : public QPushButton {

    /// Classe utilitaire. Bouton à presser pour choisir le type d'objet physique désiré.

    Q_OBJECT

// ==== METHODES ====

public:
    TypeBouton(Type, QWidget* = nullptr);               // Cstor. Paramètre : type représenté.

    // ---- Accesseurs ----

    bool isPresse()const {return m_pressed;}            // Indique si le bouton est pressé
    Type getType() const {return m_type;}               // Retourne le type représenté par le bouton

    double getRayon() {return m_barRayon->value();}
    double getHauteur() {return m_barHauteur->value();}
    double getMVol(){return m_barMVol->value();}

    // Paramètres initiaux (angles, position pour l'oscillateur)
    double getPX() const{return m_pX->value();}
    double getPY() const{return m_pY->value();}
    double getPZ() const{return m_pZ->value();}

    // Vitesses initiales
    double getVX() const{return m_vX->value();}
    double getVY() const{return m_vY->value();}
    double getVZ() const{return m_vZ->value();}


    // Set
    void setPresse(bool);   // Modifie m_pressed

    void changeStatut();    // Gestion du click : presse ou dépresse, en fonction.
    void changeSkin();      // Modifie la couleur du bouton

signals:

    void statutChange();    // Indique avoir été clické


// ==== ATTRIBUTS ====

private:

    bool m_pressed;

    QLabel* m_photo;
    Type m_type;

    // Champs à renseigner : caractéristiques
    QDoubleSpinBox* m_barRayon;
    QDoubleSpinBox* m_barHauteur;
    QDoubleSpinBox* m_barMVol;

    QLabel* m_LabParam;                             // Appelé à changer selon le type représenté

    // Champs à renseigner : paramètres initiaux
    QDoubleSpinBox* m_pX;
    QDoubleSpinBox* m_pY;
    QDoubleSpinBox* m_pZ;

    // Champs à renseigner : vitesses initiales
    QDoubleSpinBox* m_vX;
    QDoubleSpinBox* m_vY;
    QDoubleSpinBox* m_vZ;

};



#endif // TYPEBOUTON_H
