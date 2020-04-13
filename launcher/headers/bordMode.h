#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#ifndef TOUPIES_DL_BORDMODE_H
#define TOUPIES_DL_BORDMODE_H

class BordMode : public QWidget {

public:
    BordMode(QWidget*);

    // Pas de destructeur nécessaire : Qt désallou la mémoire des widgets enfants


protected:

    QLabel* m_labelMode;

    QPushButton* m_b1;
    QPushButton* m_b2;
    QPushButton* m_b3;

};


#endif //TOUPIES_DL_BORDMODE_H
