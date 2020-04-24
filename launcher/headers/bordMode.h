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
    BordMode(QWidget* = nullptr);

    virtual ~BordMode() {}

    QPushButton* getBouton(int);
    int getFormat() {return m_formatChoisi;}
    FichierSearch* getSearch() const {return m_search;}

    void pathCheck(std::string);
public slots:

    void setToText();
    void setToImage();
    void setToFichier();



protected:

    FichierSearch* m_search;
    QLabel* m_labelMode;

    QPushButton* m_b1;
    QPushButton* m_b2;
    QPushButton* m_b3;

    FORMAT m_formatChoisi;

};


#endif //TOUPIES_DL_BORDMODE_H
