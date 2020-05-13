#ifndef SCGLWIDGET_H
#define SCGLWIDGET_H

#include "../../Qt_GL/glwidget.h"
#include <fstream>


class ScGLWidget : public GLWidget {

public:

    ScGLWidget(Systeme& S, Vecteur const& POV = Vecteur({4.5,-10.0,0.0}), size_t indice = 0, bool trace = false,
               QWidget* parent = nullptr);

    void setIndice(size_t i) {m_indice = i;}
    size_t getIndice() const {return m_indice;}

    virtual void paintGL()                       override;

    void saveData();




private:

    size_t m_indice;
    bool m_trace;

    std::ofstream fluxE;
    std::ofstream fluxLa;
    std::ofstream fluxLk;
    std::ofstream fluxPMixte;

};

#endif // SCGLWIDGET_H
