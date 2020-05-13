#include "../headers/ScGLWidget.h"



ScGLWidget::ScGLWidget(Systeme& S, Vecteur const& POV, size_t indice, bool trace,
           QWidget* parent) : GLWidget(S, POV, parent), m_indice(indice), m_trace(trace)
{

    std::string pathE("data/EnergieTotale" + std::to_string(m_indice) + ".txt");
    std::string pathLa("data/L_a"+ std::to_string(m_indice) + ".txt");
    std::string pathLk("data/L_k"+ std::to_string(m_indice) + ".txt");
    std::string pathPMixte("data/ProduitMixte"+ std::to_string(m_indice) + ".txt");


    std::ofstream fluxE(pathE, std::ios_base::app);
    std::ofstream fluxLa(pathLa, std::ios_base::app);
    std::ofstream fluxLk(pathLk, std::ios_base::app);
    std::ofstream fluxPMixte(pathPMixte, std::ios_base::app);


}



void ScGLWidget::paintGL(){

    GLWidget::paintGL();

    if(m_trace) {
        m_memoire.addPoint(m_s.getCorps(0)->getPosition());
        m_memoire.dessine();
    }

    saveData();
}



void ScGLWidget::saveData(){

    ObjetPhysique* O(m_s.getCorps(0));



    if(!fluxE) {
        std::string pathE("EnergieTotale" + std::to_string(m_indice) + ".txt");
        fluxE = std::ofstream(pathE);
    }
    if(!fluxLa) {
        std::string pathLa("L_a"+ std::to_string(m_indice) + ".txt");
        fluxLa = std::ofstream(pathLa);
    }
    if(!fluxLk) {
        std::string pathLk("L_k"+ std::to_string(m_indice) + ".txt");
        fluxLk = std::ofstream(pathLk);
    }
    if(!fluxPMixte) {
        std::string pathPMixte("ProduitMixte"+ std::to_string(m_indice) + ".txt");
        fluxPMixte = std::ofstream(pathPMixte);
    }

    fluxE << O->Energie() << std::endl;
    std::cerr << O->Energie()  << std::endl;
    fluxLa << O->L_a() << std::endl;
    fluxLk << O->L_k() << std::endl;
    fluxPMixte << O->ProdMixte() << std::endl;

}
