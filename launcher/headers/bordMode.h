#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <string>
#include "fichierSearch.h"

#ifndef TOUPIES_DL_BORDMODE_H
#define TOUPIES_DL_BORDMODE_H

class BordMode : public QWidget {

    Q_OBJECT

public:
    BordMode(QWidget* = nullptr);

    // Pas de destructeur nécessaire : Qt désalloue la mémoire des widgets enfants
    // Quelle intelligence!

    QPushButton* getBouton(int);
    int getFormat() {return m_formatChoisi;}
    std::string getPath() const {return m_path;}


    void pathCheck();

public slots:

    void setToText();
    void setToImage();
    void setToFichier();

signals:
    void fichierPret();


protected:

    QLabel* m_labelMode;

    QPushButton* m_b1;
    QPushButton* m_b2;
    QPushButton* m_b3;

    int m_formatChoisi;
    std::string m_path;

};


#endif //TOUPIES_DL_BORDMODE_H
