#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <string>
#include "fichierSearch.h"
#include "../../general/headers/SupportADessin.h"
#include "../../general/headers/TextViewer.h"

#ifndef TOUPIES_DL_BORDMODE_H
#define TOUPIES_DL_BORDMODE_H


enum FORMAT {TEXTE, IMAGE, FICHIER};

class BordMode : public QWidget {


    /// Classe utilitaire (widget enfant) servant à la gestion du choix de format:
    /// Texte, Images ou Fichier.

    Q_OBJECT

public:

    BordMode(QWidget* = nullptr);           // Cstor

    virtual ~BordMode() {}                  // Dstor


// ======== ACCESSEURS ========
    QPushButton* getBouton(int);
    int getFormat() {return m_formatChoisi;}
    FichierSearch* getSearch() const {return m_search;}


    void pathCheck(std::string);            // Vérification de la validité du path (mode fichier)

// ======== SLOTS ========

public slots:

    // Réaction aux boutons : choix du mode d'affichage
    void setToText();
    void setToImage();
    void setToFichier();



protected:

    FichierSearch* m_search;            // Le bro qui va chercher le chemin d'accès
    QLabel* m_labelMode;                // Label "Mode d'affichage :"

    // Boutons "choix du mode d'affichage"
    QPushButton* m_b1;
    QPushButton* m_b2;
    QPushButton* m_b3;

    FORMAT m_formatChoisi;              // Le mode d'affichage

};


#endif //TOUPIES_DL_BORDMODE_H
