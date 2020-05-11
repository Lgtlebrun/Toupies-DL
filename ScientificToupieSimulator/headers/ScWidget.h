#ifndef WIDGET_H
#define WIDGET_H

#include <vector>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QGroupBox>
#include <QRadioButton>
#include <string>
#include <QPushButton>
#include <QFontDatabase>
#include<QMessageBox>
#include "fichierSearch.h"
#include "QTextViewer.h"
#include "TextEdit.h"
#include "../general/headers/TextViewer.h"
#include "../Qt_GL/glwidget.h"




//QtCreator se défoule on dirait... Surtout ne touchons à rien.
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE



enum Type{CONE, CHINOISE, CUSTOM, OH, BILLE};

enum Mode{TEXTE, IMAGE, FICHIER};


class ScWidget : public QWidget
{
    Q_OBJECT

public:
    ScWidget(QWidget *parent = nullptr);

    ~ScWidget();

    bool checkAllCaracs();
    Integrable* makeObjet() const;

    void goFichier(double duree, double dt);
    void goFichierBis();
    void goTexte(double duree, double dt);
    void goImage();

public slots:

   // void changeType();
    void setCone();
    void setChinoise();
    void setBille();
    void setOh();
    void setCustom();
    void modeChanged();

    void restart();

    void go();



private:

    Ui::Widget *ui;

    QLabel* m_labRayon;
    QLabel* m_labHauteur;
    QLabel* m_labMasse;
    QLabel* m_labMvol;
    QLabel* m_labParam;
    QLabel* m_labVitesse;


    QGroupBox* tgroupBox;
    QGroupBox* m_paramGroup;
    QGroupBox* m_inertGroup;
    QGroupBox* m_nomGroup;


    QLineEdit* m_duree;
    QLineEdit* m_dt;
    QLineEdit* m_lineRayon;
    QLineEdit* m_lineHauteur;
    QLineEdit* m_lineMasse;
    QLineEdit* m_lineMVol;
    QLineEdit* m_param1;
    QLineEdit* m_param2;
    QLineEdit* m_param3;
    QLineEdit* m_lineIA1;
    QLineEdit* m_lineI3;
    QLineEdit* m_v1;
    QLineEdit* m_v2;
    QLineEdit* m_v3;

    QComboBox* m_boxType;
    QComboBox* m_boxMode;

    QCheckBox* m_caseEC;
    QCheckBox* m_caseNewmark;
    QCheckBox* m_caseRK4;

    QCheckBox* m_caseTrace;

    QPushButton* m_go;

    FichierSearch* m_search;
    TextEdit* m_console;

    std::vector<GLWidget*> m_simulations;

    bool m_trace;
    bool m_fichierPret;
    Type m_type;
    Mode m_mode;
    SupportADessin* m_support;
    Integrable* m_objet;
    std::vector<Integrateur*> m_integ;
    std::vector<std::string> m_nomInteg;
    std::vector<Systeme> m_sys;

};

#endif // WIDGET_H
