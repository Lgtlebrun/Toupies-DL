#include "../headers/ScGLWidget.h"



ScGLWidget::ScGLWidget(Systeme& S, std::string nomInteg, Vecteur const& POV, size_t indice, bool trace,
           QWidget* parent) : GLWidget(S, POV, parent), m_indice(indice), m_trace(trace), m_nomInteg(nomInteg)
{

    std::string pathE("data/EnergieTotale_" + m_nomInteg + ".txt");
    std::string pathLa("data/L_a_" + m_nomInteg + ".txt");
    std::string pathLk("data/L_k_" + m_nomInteg + ".txt");
    std::string pathPMixte("data/ProduitMixte_" + m_nomInteg + ".txt");

    std::ofstream resetE(pathE);
    std::ofstream resetLa(pathLa);
    std::ofstream resetLk(pathLk);
    std::ofstream resetPMixte(pathPMixte);

    resetE.close();
    resetLa.close();
    resetLk.close();
    resetPMixte.close();


    fluxE = std::ofstream(pathE, std::ios_base::app);
    fluxLa = std::ofstream (pathLa, std::ios_base::app);
    fluxLk = std::ofstream (pathLk, std::ios_base::app);
    fluxPMixte = std::ofstream (pathPMixte, std::ios_base::app);

    if(!fluxE) {
        std::string pathE("EnergieTotale_" + m_nomInteg + ".txt");
        std::ofstream reset(pathE);
        reset.close();
        fluxE = std::ofstream(pathE, std::ios_base::app);
    }
    if(!fluxLa) {
        std::string pathLa("L_a_" + m_nomInteg + ".txt");
        std::ofstream reset(pathLa);
        reset.close();
        fluxLa = std::ofstream(pathLa, std::ios_base::app);
    }
    if(!fluxLk) {
        std::string pathLk("L_k_" + m_nomInteg + ".txt");
        std::ofstream reset(pathLk);
        reset.close();
        fluxLk = std::ofstream(pathLk, std::ios_base::app);
    }
    if(!fluxPMixte) {
        std::string pathPMixte("ProduitMixte_" + m_nomInteg + ".txt");
        std::ofstream reset(pathPMixte);
        reset.close();
        fluxPMixte = std::ofstream(pathPMixte, std::ios_base::app);
    }


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

    fluxE << m_s.getCorps(0)->Energie() << std::endl;
    fluxLa << m_s.getCorps(0)->L_a() << std::endl;
    fluxLk << m_s.getCorps(0)->L_k() << std::endl;
    fluxPMixte <<m_s.getCorps(0)->ProdMixte() << std::endl;

}
