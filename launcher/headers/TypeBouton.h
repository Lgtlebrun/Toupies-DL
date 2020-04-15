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

    double getPX() const{return m_pX->value();}
    double getPY() const{return m_pY->value();}
    double getPZ() const{return m_pZ->value();}

    double getVX() const{return m_vX->value();}
    double getVY() const{return m_vY->value();}
    double getVZ() const{return m_vZ->value();}






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

    QLabel* m_LabParam;

    QDoubleSpinBox* m_pX;
    QDoubleSpinBox* m_pY;
    QDoubleSpinBox* m_pZ;

    QDoubleSpinBox* m_vX;
    QDoubleSpinBox* m_vY;
    QDoubleSpinBox* m_vZ;

};



#endif // TYPEBOUTON_H
