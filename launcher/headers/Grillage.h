#include <QWidget>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QGridLayout>
#include <QTextStream>
#include <QDebug>
#include <QSlider>
#include <QLCDNumber>
#include <QFontDatabase>
#include <vector>
#include <QMessageBox>
#include "boutonPosition.h"
#include "TypeBouton.h"
#include "../../general/headers/Integrable.h"
#include "../../general/headers/ConeSimple.h"
#include "../../general/headers/Tests/Bille.h"
#include "../../general/headers/Tests/Oscillateur.h"
#include "../../general/headers/TextViewer.h"
#include "../../general/headers/Integrateur.h"

#ifndef GRILLAGE_H
#define GRILLAGE_H

enum INTEGRATEUR {EC, NEWMARK, RK4};



class Grillage : public QWidget{

    /// Le frérot. Le rêve d'une vie. Un projet ébauché sous adrénaline, réalisé à grands frais de
    /// séries de retard, mais en définitive accompli et fonctionnel. Joie.
    ///
    /// Fenetre secondaire précédant le lancement de la simulation. Permet la configuration du
    /// système à simuler.
    ///
    /// Données traitées : Systeme à simuler, Objets physiques du systèmes, position de départ
    /// et paramètres initiaux des objets physiques, intégrateur, dimensions de l'espace de simulation.

public:


    Grillage(QWidget* = nullptr);
    virtual ~Grillage();


    // Accesseurs
    TypeBouton* getSelectedButton() const;
    QPushButton* getGo() const {return m_go;}
    INTEGRATEUR getInteg() const;
    std::vector<ObjetPhysique*> getCorps() const {return m_sys;}
    int getEchelle() const {return m_echelle->value();}


    // Gestion des positions disponibles
    bool isInOccupe(Vecteur const& v);          // Vérifie la disponibilité d'une position
    Vecteur findNewPos();                       // Identifie une position nouvellement occupée

    // Gestion d'ensemble
    bool checkAllCaracs() const;                // Vérification du nouvel objet
    void sendCaracErrorMess();                  // Message d'erreur (utilitaire)

public slots:
    // Gestion du choix d'un bouton-type (Cone, Bille...)
    void clickTypeBouton();

    // Gestion de la liste d'Intégrables
    void addObjet();                       // Ajout d'un objet au futur systeme
    void delObjet();                       // Suppression "   "

private:

    // Les boutons de type
    TypeBouton* m_bCone;
    TypeBouton* m_bChinoise;
    TypeBouton* m_bBille;
    TypeBouton* m_bOscillateur;

    // Choix de l'intégrateur
    QComboBox* m_BoxIntegrateur;

    Type m_typeChoisi;                          // Mémoire du bouton type sélectionné

    QSlider* m_slider;                          // Gestion de l'écart entre les cases
    QLCDNumber* m_echelle;

    QPushButton* m_go;                          // Bouton de lancement de la simulation

    std::vector<Vecteur> m_posOccupee;          // Le positions occupées par le système
    std::vector<ObjetPhysique*> m_sys;             // Les objets fabriqués


    std::vector<std::vector<BoutonPosition*>> m_boutonsPos;     // Le grillage à proprement parler


};



#endif // GRILLAGE_H
