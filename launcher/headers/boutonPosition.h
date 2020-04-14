#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>

#ifndef BOUTONPOSITION_H
#define BOUTONPOSITION_H

enum Couleur {GRIS, BLEU, ROUGE};

class BoutonPosition : public QPushButton {

public:

    BoutonPosition(QWidget* = nullptr);

    void changeCouleur(Couleur);

private:

    Couleur m_couleur;
    QLabel* m_pastille;


};



#endif // BOUTONPOSITION_H
