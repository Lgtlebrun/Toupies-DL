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

    virtual ~TestTextViewer();

    virtual bool run();

    bool TestSysteme_B_OH();

    bool TestSysteme_Conique();

    bool SimulationTexte();


};





#endif //TOUPIES_DL_TESTTEXTVIEWER_H
