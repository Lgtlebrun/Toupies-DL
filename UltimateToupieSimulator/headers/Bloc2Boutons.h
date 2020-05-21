#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

#ifndef BLOC2BOUTONS_H
#define BLOC2BOUTONS_H


class Bloc2Boutons : public QWidget {

    /// Widget groupant deux boutons "OK" et "CANCEL"


public:
    Bloc2Boutons(QWidget* = nullptr);
    QPushButton* getBOk();
    QPushButton* getBCancel();

private:
    QPushButton* m_bOk;
    QPushButton* m_bCancel;

};


#endif // BLOC2BOUTONS_H
