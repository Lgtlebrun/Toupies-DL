#include <QWidget>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QGridLayout>
#include <QTextStream>
#include <QDebug>
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

enum INTEGRATEUR {EC, NEWMARK};



class Grillage : public QWidget{

public:
    Grillage(QWidget* = nullptr);
    virtual ~Grillage();

    TypeBouton* getSelectedButton() const;
    QPushButton* getGo() const {return m_go;}
    INTEGRATEUR getInteg() const;
    std::vector<Integrable*> getCorps() const {return m_sys;}

    void clickTypeBouton();
    bool isInOccupe(Vecteur const& v);
    Vecteur findNewPos();

    void addIntegrable();
    void delIntegrable();
    void sendCaracErrorMess();

    bool checkAllCaracs() const;

private:

    TypeBouton* m_bCone;
    TypeBouton* m_bChinoise;
    TypeBouton* m_bBille;
    TypeBouton* m_bOscillateur;

    QComboBox* m_BoxIntegrateur;

    Type m_typeChoisi;

    QPushButton* m_go;

    std::vector<Vecteur> m_posOccupee;
    std::vector<Integrable*> m_sys;
    std::vector<std::vector<BoutonPosition*>> m_boutonsPos;


};



#endif // GRILLAGE_H
