#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QMessageBox>
#include "../../general/headers/Vecteur.h"

#ifndef BOUTONPOSITION_H
#define BOUTONPOSITION_H

enum Couleur {GRIS, BLEU, ROUGE};

class BoutonPosition : public QPushButton {

    Q_OBJECT

public:

    BoutonPosition(Vecteur const&, QWidget* = nullptr);

    void changeCouleur(Couleur);
    void clickGestion();

    Couleur getCouleur(){return m_couleur;}
    Vecteur getPos(){return m_position;}

signals:

    void newIntegrable();
    void supprIntegrable();

private:

    Couleur m_couleur;
    QLabel* m_pastille;

    Vecteur m_position;


};



#endif // BOUTONPOSITION_H
