#pragma once

#ifndef TOUPIES_DL_TESTTEXTVIEWER_H
#define TOUPIES_DL_TESTTEXTVIEWER_H

#include "Unittest.h"
#include "../TextViewer.h"
#include "../Systeme.h"
#include "../constantes.h"

class TestTextViewer : public Unittest
{
public :

    TestTextViewer();


    virtual bool run();

    bool SimulationTexte();


};





#endif //TOUPIES_DL_TESTTEXTVIEWER_H
