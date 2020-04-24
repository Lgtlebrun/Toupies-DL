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

enum INTEGRATEUR {EC, NEWMARK};



class Grillage : public QWidget{

public:


    Grillage(QWidget* = nullptr);
    virtual ~Grillage();


    // Accesseurs
    TypeBouton* getSelectedButton() const;
    QPushButton* getGo() const {return m_go;}
    INTEGRATEUR getInteg() const;
    std::vector<Integrable*> getCorps() const {return m_sys;}
    int getEchelle() const {return m_echelle->value();}

    // Gestion du choix d'un bouton-type (Cone, Bille...)
    void clickTypeBouton();

    // Gestion des positions disponibles
    bool isInOccupe(Vecteur const& v);          // Vérifie la disponibilité
    Vecteur findNewPos();                       // Identifie une position nouvellement occupée

    // Gestion de la liste d'Intégrables
    void addIntegrable();                       // Ajout d'un objet au futur systeme
    void delIntegrable();                       // Suppression "   "

    // Gestion d'ensemble
    bool checkAllCaracs() const;                // Vérification du nouvel objet
    void sendCaracErrorMess();                  // Message d'erreur (utilitaire)

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
    std::vector<Integrable*> m_sys;             // Les objets fabriqués


    std::vector<std::vector<BoutonPosition*>> m_boutonsPos;     // Le grillage à proprement parler


};



#endif // GRILLAGE_H
