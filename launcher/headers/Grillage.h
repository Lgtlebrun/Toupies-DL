#include <QWidget>
#include <QGridLayout>
#include <vector>
#include "boutonPosition.h"
#include "../../general/headers/Integrable.h"
#include "../../general/headers/ConeSimple.h"
#include "../../general/headers/Tests/Bille.h"
#include "../../general/headers/Tests/Oscillateur.h"

#ifndef GRILLAGE_H
#define GRILLAGE_H


class Grillage : public QWidget{

public:
    Grillage(QWidget* = nullptr);
    virtual ~Grillage();



private:

    QWidget* m_grille;
    std::vector<Integrable*> m_sys;

};



#endif // GRILLAGE_H
