#ifndef WIDGET_H
#define WIDGET_H

#include <vector>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QGroupBox>
#include <QRadioButton>
#include <string>
#include <QPushButton>
#include <QFontDatabase>
#include<QMessageBox>
#include "fichierSearch.h"
#include "QTextViewer.h"
#include "TextEdit.h"
#include "../general/headers/TextViewer.h"
#include "ScGLWidget.h"




enum Type{CONE, CHINOISE, CUSTOM, OH, BILLE};

enum Mode{TEXTE, IMAGE, FICHIER};


class ScWidget : public QWidget
{

    /// FENETRE PRINCIPALE DE SCIENTIFIC TOUPIE SIMULATOR
    ///
    /// Visuel : Simple launcher permettant la configuration d'une simulation scientifique.
    /// Les simulations ne peuvent contenir qu'un seul objet physique à la fois.
    /// Plusieurs simulations peuvent être lancées simultanément, en choisissant plusieurs
    /// intégrateurs.
    ///
    /// Gère le lancement et l'arrêt des simulations.
    /// Apparaît au lancement de l'application et à la fermeture des simulations.

    Q_OBJECT


// ========================== METHODES ==============================

public:
    ScWidget(QWidget *parent = nullptr);                // Cstor

    ~ScWidget();                                        // Dstor


    // Lancement des simulations (selon le format d'affichage)
    void goFichier(double duree, double dt);
    void goFichierBis();                                // Appelée par le FichierSearch que lance goFichier(...)
    void goTexte(double duree, double dt);
    void goImage();

    // Configuration et fabrication de l'objet physique à simuler
    bool checkAllCaracs();                              // Vérifie que tous les champs indispensables à l'objet sont renseignés
    ObjetPhysique* makeObjet() const;                   // Fabrique l'objet, retourne un pointeur dessus


    // Sauvegarde des données
    void saveData(ObjetPhysique* O, size_t indice);


public slots:

    // Appelés par les RadioButtons choisissant le type d'objet physique
    void setCone();
    void setChinoise();
    void setBille();
    void setOh();
    void setCustom();

    // Appelé par le changement de mode d'affichage
    void modeChanged();

    // Détruit les simulations, relance la fenêtre
    void restart();

    // Appelée par le bouton Go: redirige vers la méthode "go" adaptée
    void go();




// ========================= ATTRIBUTS ===============================

private:

    // ===== WIDGETS =====

    // Labels illustrant les champs à renseigner
    QLabel* m_labRayon;
    QLabel* m_labHauteur;
    QLabel* m_labMasse;
    QLabel* m_labMvol;
    QLabel* m_labParam;
    QLabel* m_labVitesse;

    // Groupes réunissant les types de champ à renseigner
    QGroupBox* tgroupBox;
    QGroupBox* m_paramGroup;
    QGroupBox* m_inertGroup;
    QGroupBox* m_nomGroup;


    // Champs à renseigner
    QLineEdit* m_duree;
    QLineEdit* m_dt;
    QLineEdit* m_lineNom;
    QLineEdit* m_lineRayon;
    QLineEdit* m_lineHauteur;
    QLineEdit* m_lineMasse;
    QLineEdit* m_lineMVol;
    QLineEdit* m_param1;
    QLineEdit* m_param2;
    QLineEdit* m_param3;
    QLineEdit* m_lineIA1;
    QLineEdit* m_lineI3;
    QLineEdit* m_v1;
    QLineEdit* m_v2;
    QLineEdit* m_v3;

    // Choix du mode d'affichage
    QComboBox* m_boxMode;

    // Choix des intégrateurs : cases à cocher
    QCheckBox* m_caseEC;
    QCheckBox* m_caseNewmark;
    QCheckBox* m_caseRK4;

    // Affichage de la trace : case à cocher
    QCheckBox* m_caseTrace;

    // Bouton go
    QPushButton* m_go;

    // MODE FICHIER
    FichierSearch* m_search;                        // Choix du dossier où créer le fichier

    // MODE TEXTE
    TextEdit* m_console;                            // Widget imitant une console


    // ===== ATTRIBUTS STANDARDS =====

    std::vector<ScGLWidget*> m_simulations;         // Collection de simulations en mode IMAGE

    bool m_trace;                                   // Affichage ou non de la trace
    bool m_fichierPret;                             // Mode fichier : retour du fichierSearch
    Type m_type;                                    // Type d'objet phyisique choisi
    Mode m_mode;                                    // Mode d'affichage choisi
    SupportADessin* m_support;                      // Support de l'objet physique
    ObjetPhysique* m_objet;                         // Objet physique à simuler
    std::vector<Integrateur*> m_integ;              // Les intégrateurs choisis
    std::vector<std::string> m_nomInteg;            // Noms des intégrateurs choisis
    std::vector<Systeme> m_sys;                     // Systèmes à simuler (même objet, intégrateur spécifique)

};

#endif // WIDGET_H
