#include <QWidget>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QGridLayout>
#include <vector>
#include <QMessageBox>
#include "boutonPosition.h"
#include "TypeBouton.h"
#include "../../general/headers/Integrable.h"
#include "../../general/headers/ConeSimple.h"
#include "../../general/headers/Tests/Bille.h"
#include "../../general/headers/Tests/Oscillateur.h"
#include "../../general/headers/TextViewer.h"
#include "../../general/headers/Integrateur.h"

#ifndef GRILLAGE_H
#define GRILLAGE_H



class Grillage : public QWidget{

public:
    Grillage(QWidget* = nullptr);
    virtual ~Grillage();

    void clickTypeBouton();
    Vecteur findNewPos();

    void addIntegrable();
    void delIntegrable();

    bool checkAllCaracs() const;

private:

    TypeBouton* m_bCone;
    TypeBouton* m_bChinoise;
    TypeBouton* m_bBille;
    TypeBouton* m_bOscillateur;

    QLabel* m_LabParam;

    QDoubleSpinBox* m_pX;
    QDoubleSpinBox* m_pY;
    QDoubleSpinBox* m_pZ;

    QDoubleSpinBox* m_vX;
    QDoubleSpinBox* m_vY;
    QDoubleSpinBox* m_vZ;

    QComboBox* m_BoxIntegrateur;

    Type m_typeChoisi;



    //Rendu final
    std::vector<Integrable*> m_sys;
    std::vector<std::vector<BoutonPosition*>> m_boutonsPos;


};



#endif // GRILLAGE_H
