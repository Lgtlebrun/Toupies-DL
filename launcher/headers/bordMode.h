#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "fichierSearch.h"

#ifndef TOUPIES_DL_BORDMODE_H
#define TOUPIES_DL_BORDMODE_H

class BordMode : public QWidget {

    Q_OBJECT

public:
    BordMode(QWidget*);

    // Pas de destructeur nécessaire : Qt désalloue la mémoire des widgets enfants
    // Quelle intelligence!

    QPushButton* getBouton(int);
    FichierSearch* getFenetre();    // Accesseur au FichierSearch
    int getFormat() {return m_formatChoisi;}


public slots:

    void openFichierSearch();
    void setToText();
    void setToImage();
    void setToFichier();


protected:

    QLabel* m_labelMode;

    QPushButton* m_b1;
    QPushButton* m_b2;
    QPushButton* m_b3;

    int m_formatChoisi;

    FichierSearch* m_fenetre;

};


#endif //TOUPIES_DL_BORDMODE_H
