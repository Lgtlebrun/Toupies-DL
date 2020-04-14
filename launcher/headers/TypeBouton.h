#include <QPushButton>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QMovie>


#ifndef TYPEBOUTON_H
#define TYPEBOUTON_H

enum Type {CONE, CHINOISE, OSCILLATEUR, BILLE, Null};

class TypeBouton : public QPushButton {

    Q_OBJECT

public:
    TypeBouton(Type, QWidget* = nullptr);

    bool isPresse()const {return m_pressed;}
    Type getType() const {return m_type;}

    double getRayon() {return m_barRayon->value();}
    double getHauteur() {return m_barHauteur->value();}
    double getMVol(){return m_barMVol->value();}

    void setPresse(bool);

    void changeStatut();
    void changeSkin();

signals:

    void statutChange();

private:

    bool m_pressed;

    QLabel* m_photo;
    Type m_type;
    QDoubleSpinBox* m_barRayon;
    QDoubleSpinBox* m_barHauteur;
    QDoubleSpinBox* m_barMVol;

};



#endif // TYPEBOUTON_H
