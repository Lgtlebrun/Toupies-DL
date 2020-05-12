#include "../headers/ScWidget.h"
#include "ui_widget.h"

ScWidget::ScWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget), m_type(CUSTOM), m_mode(TEXTE), m_support(0), m_objet(0), m_console(0), m_fichierPret(false)
{
    ui->setupUi(this);



    // Initialisation


    QVBoxLayout* mainlay = new QVBoxLayout;
    mainlay->setAlignment(Qt::AlignTop);
    mainlay->setSpacing(40);


    QHBoxLayout* centralLay = new QHBoxLayout;
    centralLay->setAlignment(Qt::AlignCenter);

    QVBoxLayout* gaucheLay = new QVBoxLayout;
    QVBoxLayout* droiteLay = new QVBoxLayout;

    //Initialisation titre
    QLabel* titre = new QLabel("Toupie Simulator : Scientific Edition", this);
    titre -> setFixedSize(1460, 150);
    titre->setAlignment(Qt::AlignCenter);
    titre->setFont(QFont(QString('Times New Roman'), 25, 25, true));

    //Initialisation colonne gauche

    gaucheLay->setAlignment(Qt::AlignTop);

    // Type:
    QGroupBox* groupbox = new QGroupBox("Type d'objet", this);

    QRadioButton* cone = new QRadioButton("Cone Simple");
    QRadioButton* chinoise = new QRadioButton("Toupie chinoise");
    QRadioButton* bille = new QRadioButton("Bille");
    QRadioButton* oh = new QRadioButton("Oscillateur");
    QRadioButton* custom = new QRadioButton("Custom");

    QVBoxLayout* radioLay = new QVBoxLayout;
    radioLay->addWidget(cone);
    radioLay->addWidget(chinoise);
    radioLay->addWidget(bille);
    radioLay->addWidget(oh);
    radioLay->addWidget(custom);

    groupbox->setLayout(radioLay);

    QObject::connect(cone, &QRadioButton::clicked, this, &ScWidget::setCone);
    QObject::connect(chinoise, &QRadioButton::clicked, this, &ScWidget::setChinoise);
    QObject::connect(bille, &QRadioButton::clicked, this, &ScWidget::setBille);
    QObject::connect(oh, &QRadioButton::clicked, this, &ScWidget::setOh);
    QObject::connect(custom, &QRadioButton::clicked, this, &ScWidget::setCustom);



    gaucheLay->addWidget(groupbox);

    // Integrateurs:

    QGroupBox* integGroup = new QGroupBox("Integrateur(s)", this);
    QVBoxLayout* integLay = new QVBoxLayout;
    QVBoxLayout* casesLay = new QVBoxLayout;

    integLay->setAlignment(Qt::AlignLeft);
    integLay->setSpacing(5);

    casesLay->setAlignment(Qt::AlignLeft);
    casesLay->setSpacing(10);

    m_caseEC = new QCheckBox("Euler-Cromer", this);
    m_caseNewmark = new QCheckBox("Newmark", this);
    m_caseRK4 = new QCheckBox("Runge-Kutta 4", this);

    casesLay->addWidget(m_caseEC);
    casesLay->addWidget(m_caseNewmark);
    casesLay->addWidget(m_caseRK4);

    integLay->addLayout(casesLay);

    integGroup->setLayout(integLay);


    gaucheLay->addWidget(integGroup);

    m_caseEC->click();


    // Mode d'affichage

    QGroupBox* affGroup = new QGroupBox("Mode d'affichage", this);

    QVBoxLayout* modeLay = new QVBoxLayout;
    modeLay->setSpacing(5);
    modeLay->setAlignment(Qt::AlignLeft);

    m_boxMode = new QComboBox(this);
    m_boxMode->addItem("Texte");
    m_boxMode->addItem("Image");
    m_boxMode->addItem("Fichier");

    modeLay->addWidget(m_boxMode);

    affGroup->setLayout(modeLay);

    //CONNEXIOOOOOOON

    QObject::connect(m_boxMode, &QComboBox::currentTextChanged, this, &ScWidget::modeChanged);




    gaucheLay->addWidget(affGroup);

    // Reglages temps:

    tgroupBox = new QGroupBox("Réglages temps",this);


    QHBoxLayout* lineEditLay = new QHBoxLayout;
    lineEditLay->setAlignment(Qt::AlignLeft);

    m_duree = new QLineEdit(this);
    m_dt = new QLineEdit(this);

    m_duree->setText(0);
    m_dt->setText(0);

    QLabel* labDuree = new QLabel("Durée : ", this);
    QLabel* labDt = new QLabel("dt : ", this);

    QDoubleValidator* val = new QDoubleValidator(this);
    val->setBottom(0.);


    m_duree->setValidator(val);
    m_dt->setValidator(val);

    lineEditLay->addWidget(labDuree);
    lineEditLay->addWidget(m_duree);
    lineEditLay->addWidget(labDt);
    lineEditLay->addWidget(m_dt);

    tgroupBox->setLayout(lineEditLay);

    gaucheLay->addWidget(tgroupBox);

    // Trace

    m_caseTrace = new QCheckBox("Trace", this);
    m_caseTrace->hide();

    gaucheLay->addWidget(m_caseTrace);



    //Initialisation colonne droite

    QHBoxLayout* caracLay = new QHBoxLayout;
    QHBoxLayout* paramLay = new QHBoxLayout;
    QHBoxLayout* vitesseLay = new QHBoxLayout;
    QHBoxLayout* inertieLay = new QHBoxLayout;
    QHBoxLayout* distanceGLay = new QHBoxLayout;


    // Nom

    m_nomGroup = new QGroupBox("Nom", this);
    m_lineNom = new QLineEdit(this);

    QVBoxLayout* vlay = new QVBoxLayout;
    vlay->addWidget(m_lineNom);
    m_nomGroup->setLayout(vlay);

    droiteLay->addWidget(m_nomGroup);

    // Caracs
    caracLay->setAlignment(Qt::AlignRight);
    caracLay->setSpacing(6);

    QDoubleValidator* valChill = new QDoubleValidator(this);

    QGroupBox* caracGroup = new QGroupBox("Caractéristiques", this);

    m_labRayon = new QLabel("Rayon : ", this);
    m_lineRayon = new QLineEdit(this);
    m_lineRayon->setValidator(val);

    m_labHauteur = new QLabel("Hauteur : ", this);
    m_lineHauteur = new QLineEdit(this);
    m_lineHauteur->setValidator(val);

    m_labMasse = new QLabel("Masse : ", this);
    m_lineMasse = new QLineEdit(this);
    m_lineMasse->setValidator(val);

    m_labMvol = new QLabel("MVolumique : ", this);
    m_lineMVol = new QLineEdit(this);
    m_lineMVol->setValidator(val);

    caracLay->addWidget(m_labRayon);
    caracLay->addWidget(m_lineRayon);
    caracLay->addWidget(m_labHauteur);
    caracLay->addWidget(m_lineHauteur);
    caracLay->addWidget(m_labMasse);
    caracLay->addWidget(m_lineMasse);
    caracLay->addWidget(m_labMvol);
    caracLay->addWidget(m_lineMVol);

    caracGroup->setLayout(caracLay);


    droiteLay->addWidget(caracGroup);


    // Inertie


    m_inertGroup = new QGroupBox("Moments d'inertie", this);

    inertieLay->setAlignment(Qt::AlignRight);
    inertieLay->setSpacing(6);

    QLabel* labIA1 = new QLabel("IA1 : ", this);
    QLabel* labI3 = new QLabel("IA3 : ", this);

    m_lineIA1 = new QLineEdit(this);
    m_lineI3 = new QLineEdit(this);

    inertieLay->addWidget(labIA1);
    inertieLay->addWidget(m_lineIA1);
    inertieLay->addWidget(labI3);
    inertieLay->addWidget(m_lineI3);

    m_inertGroup->setLayout(inertieLay);


    droiteLay->addWidget(m_inertGroup);


    // Params

    m_paramGroup = new QGroupBox("Paramètres initiaux", this);

    paramLay->setAlignment(Qt::AlignRight);
    paramLay->setSpacing(6);

    m_labParam = new QLabel("Angle en t=0 (theta, psi, phi): ", this);
    m_param1 = new QLineEdit(this);
    m_param1->setValidator(valChill);
    m_param2 = new QLineEdit(this);
    m_param2->setValidator(valChill);
    m_param3 = new QLineEdit(this);
    m_param3->setValidator(valChill);

    paramLay->addWidget(m_labParam);
    paramLay->addWidget(m_param1);
    paramLay->addWidget(m_param2);
    paramLay->addWidget(m_param3);

    m_paramGroup->setLayout(paramLay);

    droiteLay->addWidget(m_paramGroup);



    // Vitesse

    QGroupBox* vGroup = new QGroupBox("Vitesses initiales", this);

    vitesseLay->setAlignment(Qt::AlignRight);
    vitesseLay->setSpacing(6);

    m_labVitesse = new QLabel("Angle en t=0 (theta, psi, phi)", this);

    m_v1 = new QLineEdit(this);
    m_v2 = new QLineEdit(this);
    m_v3 = new QLineEdit(this);

    m_v1->setValidator(valChill);
    m_v2->setValidator(valChill);
    m_v3->setValidator(valChill);

    vitesseLay->addWidget(m_labVitesse);
    vitesseLay->addWidget(m_v1);
    vitesseLay->addWidget(m_v2);
    vitesseLay->addWidget(m_v3);

    vGroup->setLayout(vitesseLay);

    droiteLay->addWidget(vGroup);


    //Setup bouton GO

    QFontDatabase::addApplicationFont(":/copper/Cooper-Black_.ttf");

    m_go = new QPushButton("GO !",this);
    m_go->setFont(QFont("Cooper Black", 70, 30));
    m_go->setStyleSheet("background: cyan; color: white");

    QObject::connect(m_go, &QPushButton::clicked, this, &ScWidget::go);


    droiteLay->addWidget(m_go);


    //Setupe fileSearch

    m_search = new FichierSearch("ScientificSimulation", this);


    //Dernières commandes

    QWidget* colonneGauche = new QWidget(this);
    colonneGauche->setLayout(gaucheLay);
    colonneGauche->setFixedWidth(540);

    QWidget* colonneDroite = new QWidget(this);
    colonneDroite->setLayout(droiteLay);
    colonneDroite->setMaximumWidth(840);


    centralLay->addWidget(colonneGauche);
    centralLay->addWidget(colonneDroite);
    mainlay->addWidget(titre);
    mainlay->addLayout(centralLay);

    this->setLayout(mainlay);
    cone->click();
}

ScWidget::~ScWidget()
{
    delete ui;
}



Integrable* ScWidget::makeObjet() const {

    Integrable* ptr(0);

    switch(m_type){

    case CONE:

        ptr = new ConeSimple(*m_support, Vecteur({m_param1->text().toDouble(), m_param2->text().toDouble(), m_param3->text().toDouble()}),
                             Vecteur({m_v1->text().toDouble(), m_v2->text().toDouble(), m_v3->text().toDouble()}), Vecteur(),
                             m_lineRayon->text().toDouble(), m_lineHauteur->text().toDouble(), m_lineMVol->text().toDouble());
        break;

    case CHINOISE:

        ptr = new ToupieChinoise(*m_support, Vecteur({m_param1->text().toDouble(), m_param2->text().toDouble(), m_param3->text().toDouble()}),
                                 Vecteur({m_v1->text().toDouble(), m_v2->text().toDouble(), m_v3->text().toDouble()}), Vecteur(),
                                 m_lineRayon->text().toDouble(), m_lineHauteur->text().toDouble(), m_lineMVol->text().toDouble());

        break;

    case BILLE:

        ptr = new Bille(*m_support, Vecteur(), Vecteur({m_v1->text().toDouble(), m_v2->text().toDouble(), m_v3->text().toDouble()}), m_lineRayon->text().toDouble());
        break;


    case OH:

        ptr = new Oscillateur(*m_support, Vecteur({m_param1->text().toDouble(), m_param2->text().toDouble(), m_param3->text().toDouble()}),
                          Vecteur({m_v1->text().toDouble(), m_v2->text().toDouble(), m_v3->text().toDouble()}), Vecteur(), m_lineRayon->text().toDouble());

        break;

    case CUSTOM:

        ptr = new Toupie(*m_support, m_lineNom->text().toStdString(), Vecteur({m_param1->text().toDouble(), m_param2->text().toDouble(), m_param3->text().toDouble()}),
                         Vecteur({m_v1->text().toDouble(), m_v2->text().toDouble(), m_v3->text().toDouble()}), Vecteur(), m_lineIA1->text().toDouble(), m_lineI3->text().toDouble(),
                         m_lineMVol->text().toDouble(), m_lineMasse->text().toDouble(), m_lineRayon->text().toDouble());

        break;
    }

    return ptr;


}



void ScWidget::go(){

    if(!checkAllCaracs()){
        return;
    }



    // Il y a besoin d'un support par défaut pour fabriquer l'objet
    m_console = new TextEdit;
    m_console->setFixedSize(1000, 800);
    m_support = new QTextViewer(*m_console);

    m_objet = makeObjet();


    //Setup des systèmes

    if (m_caseEC->isChecked()){
        m_integ.push_back(new IntegrateurEulerCromer(0));
        m_nomInteg.push_back(std::string("Integrateur Euler-Cromer"));
    }
    if (m_caseNewmark->isChecked()){
        m_integ.push_back(new IntegrateurNewmark(0));
        m_nomInteg.push_back(std::string("Integrateur Newmark"));
    }
    if (m_caseRK4->isChecked()){
        m_integ.push_back(new IntegrateurRK4(0));
        m_nomInteg.push_back(std::string("Integrateur RK4"));
    }

    for (auto& elt:m_integ){
        Systeme S(*m_support, *elt);
        S.addIntegrable(*m_objet);
        m_sys.push_back(S);
    }

    double secondes (0);
    double dt (0);

    if (m_mode == FICHIER || m_mode == TEXTE){
        secondes = m_duree->text().toDouble();
        dt = m_dt->text().toDouble();
    }

    switch(m_mode){

    case TEXTE:
        hide();
        goTexte(secondes, dt);
        break;

    case FICHIER:

        goFichier(secondes, dt);
        break;

    case IMAGE:

        hide();
        goImage();
        break;
    }


}


void ScWidget::goTexte(double duree, double dt){

    m_console->show();
    QObject::connect(m_console, &TextEdit::restartStp, this, &ScWidget::restart);



    for (size_t j(0); j < m_sys.size(); j++){   //On itère sur les systèmes

        *m_console << m_sys[j];
        *m_console << m_nomInteg[j];

        for(int i(0); i < duree/dt; i++){       //Puis sur les objets qu'ils contiennent

            m_sys[j].evolue(dt);
            m_sys[j].dessine();
        }
    }

}


void ScWidget::goFichier(double duree, double dt){


    if(!m_fichierPret) {
        m_search->open();
        QObject::connect(m_search, &FichierSearch::fichierPret, this, &ScWidget::goFichierBis);

        return;}

    std::ofstream flux(m_search->getPath());
    m_support = new TextViewer(flux);

    if(!flux.fail()){

        for (size_t j(0); j < m_sys.size(); j++){

            m_sys[j].affiche(flux);
            flux << m_nomInteg[j] << "\n";
            m_sys[j].changeSupport(*m_support);


            for (int i(0); i < duree/dt; i++){
                m_sys[j].evolue(dt);
                m_sys[j].dessine();
            }
         }

         std::string mess("La simulation s'est correctement déroulée. \nFichier correctement enrigistré à l'adresse " + m_search->getPath());
         QMessageBox::information(this, "Succès!", QString::fromStdString(mess));

     }
     else {
        std::string mess("Une erreur est survenue en fin de processus. Toutes nos excuses.\nLe fichier " + m_search->getPath() + " n'a pas été ouvert correctement.");

        QMessageBox::information(this, "Echec!", QString::fromStdString(mess));

    }

    restart();


}


void ScWidget::goFichierBis(){
    m_fichierPret = true;
    goFichier(m_duree->text().toDouble(), m_dt->text().toDouble());
}


void ScWidget::goImage(){

    if(m_caseTrace->isChecked()) {m_trace = true;}

    for (auto& S:m_sys){
        m_simulations.push_back(new GLWidget(S, Vecteur({0.,-10, 0.}), m_trace));
    }

    for(size_t i(0); i < m_simulations.size(); i++){

        //Setup bouton Menu principal

        QPushButton* menuPrincipal = new QPushButton("Menu Principal", m_simulations[i]);
        QFontDatabase::addApplicationFont(":/copper/agency-fb_.ttf");


        menuPrincipal->setGeometry(20,20, 200, 75);
        menuPrincipal->setFont(QFont("Agency FB", 20, 15));
        menuPrincipal->setStyleSheet("background: red; color: white");

        QObject::connect(menuPrincipal, &QPushButton::clicked, this, &ScWidget::restart);

        //Setup label Integrateur

        QLabel* labInteg = new QLabel(QString::fromStdString(m_nomInteg[i]), m_simulations[i]);
        labInteg->move(20, 100);
        labInteg->setStyleSheet("background: white;");

    }

    for(auto& elt:m_simulations){
        elt->showFullScreen();
    }
}


void ScWidget::restart(){

    for(auto& elt:m_simulations){
        elt->hide();
        delete elt;
        elt = nullptr;
    }

    for (auto& elt:m_simulations){
        m_simulations.pop_back();
    }

    for (auto& elt:m_sys){
        m_sys.pop_back();
    }

    for (auto& elt:m_integ){
        delete elt;
        elt = nullptr;
    }


    for (auto& elt:m_integ){
        m_integ.pop_back();
    }

    for (auto& elt:m_nomInteg){
        m_nomInteg.pop_back();
    }

    delete m_objet;
    m_objet = nullptr;

    delete m_support;
    m_support = nullptr;



    show();

}



bool ScWidget::checkAllCaracs(){

    if (!(m_caseEC->isChecked() || m_caseNewmark->isChecked() || m_caseRK4->isChecked())) {
        QMessageBox::information(this, "Echec!", "Veuillez sélectionner au moins un intégrateur.");
        return false;
    }


    switch(m_mode){

    case TEXTE:
    case FICHIER:

        double duree(m_duree->text().toDouble());
        double dt(m_dt->text().toDouble());

        if (duree == 0. || dt == 0.){
            QMessageBox::information(this, "Echec!", "Ni la durée de la simulation, ni le pas de temps ne peuvent être égal à 0.");
            return false;
        }
        break;
    }



    switch(m_type) {


    case CONE:
    case CHINOISE:

        if(m_lineHauteur->text().toDouble() == 0. || m_lineMVol->text().toDouble() == 0.){
            QMessageBox::information(this, "Echec!", "Veuillez renseigner un rayon, une hauteur et une masse volumique.");
            return false;

        }

    case BILLE:
    case OH:

        if(m_lineRayon->text().toDouble() == 0. ){
            QMessageBox::information(this, "Echec!", "Veuillez renseigner un rayon.");
            return false;
        }

        break;

    case CUSTOM:

        if(m_lineI3->text().toDouble() == 0. || m_lineIA1->text().toDouble() == 0.){
            QMessageBox::information(this, "Echec!", "Veuillez renseigner des moments d'inertie.");
            return false;
        }

        if(m_lineMVol->text().toDouble() == 0. || m_lineMasse->text().toDouble() == 0 || m_lineRayon->text().toDouble() == 0.){
            QMessageBox::information(this, "Echec!", "Veuillez renseigner une masse, une masse volumique et la distance au sol du centre de masse.");
            return false;
        }

        break;

    }

    return true;
}


/*
void ScWidget::saveData(Integrable* I){

    std::string pathE("data/EnergieTotale.txt");
    std::string pathLa("data/L_a.txt");
    std::string pathLk("data/L_k.txt");
    std::string pathPMixte("data/ProduitMixte.txt");

    std::ofstream fluxE(pathE);
    std::ofstream fluxLa(pathLa);
    std::ofstream fluxLk(pathLk);
    std::ofstream fluxPMixte(pathPMixte);

    if(!fluxE) {
        pathE = ("EnergieTotale.txt");
        fluxE = std::ofstream(pathE);
    }
    if(!fluxLa) {
        pathLa = ("L_a.txt");
        fluxLa = std::ofstream(pathLa);
    }
    if(!fluxLk) {
        pathLk = ("L_k.txt");
        fluxLk = std::ofstream(pathLk);
    }
    if(!fluxPMixte) {
        pathPMixte = ("ProduitMixte.txt");
        fluxPMixte = std::ofstream(pathPMixte);
    }

    fluxE << I->get

}

*/


void ScWidget::setCone() {

    m_type = CONE;

    m_nomGroup->hide();

    m_inertGroup->hide();

    m_paramGroup->show();

    m_labParam->setText("Angle en t=0 (theta, psi, phi)");
    m_labVitesse->setText("Angle en t=0 (theta, psi, phi)");

    m_labRayon->show();
    m_lineRayon->show();
    m_labHauteur->show();
    m_lineHauteur->show();
    m_labMvol->show();
    m_lineMVol->show();
    m_labMasse->hide();
    m_lineMasse->hide();

    m_labRayon->setText("Rayon : ");
}

void ScWidget::setChinoise() {

    m_type = CHINOISE;

    m_nomGroup->hide();

    m_inertGroup->hide();

    m_paramGroup->show();

    m_labParam->setText("Angle en t=0 (theta, psi, phi)");
    m_labVitesse->setText("Angle en t=0 (theta, psi, phi)");

    m_labRayon->show();
    m_lineRayon->show();
    m_labHauteur->show();
    m_lineHauteur->show();
    m_labMvol->show();
    m_lineMVol->show();

    m_labRayon->setText("Rayon : ");
}

void ScWidget::setOh() {

    m_type = OH;


    m_nomGroup->hide();

    m_inertGroup->hide();

    m_paramGroup->show();

    m_labParam->setText("Pos° de départ");
    m_labMvol->hide();
    m_lineMVol->hide();
    m_lineMasse->hide();
    m_labMasse->hide();
    m_labHauteur->hide();
    m_lineHauteur->hide();

    m_labRayon->show();
    m_lineRayon->show();

    m_labVitesse->setText("Coords (X, Y, Z)");


    m_labRayon->setText("Rayon : ");
}

void ScWidget::setBille() {

    m_type = BILLE;


    m_nomGroup->hide();

    m_inertGroup->hide();

    m_paramGroup->hide();

    m_labMvol->hide();
    m_lineMVol->hide();
    m_lineMasse->hide();
    m_labMasse->hide();
    m_labHauteur->hide();
    m_lineHauteur->hide();
    m_labRayon->show();
    m_lineRayon->show();

    m_labVitesse->setText("Coords (X, Y, Z)");


    m_labRayon->setText("Rayon : ");
}

void ScWidget::setCustom() {

    m_type = CUSTOM;

    m_nomGroup->show();

    m_inertGroup->show();

    m_paramGroup->show();

    m_labRayon->show();
    m_lineRayon->show();
    m_labHauteur->show();
    m_lineHauteur->show();
    m_labMvol->show();
    m_lineMVol->show();
    m_lineMasse->show();
    m_labMasse->show();


    m_labParam->setText("Angle en t=0 (theta, psi, phi)");
    m_labVitesse->setText("Angle en t=0 (theta, psi, phi)");


    m_labRayon->setText("Distance du centre de masse :");
}



void ScWidget::modeChanged() {

    QString mode(m_boxMode->currentText());

    if(mode == "Texte"){
        m_mode = TEXTE;
        tgroupBox->show();
        m_caseTrace->hide();

    }
    else if (mode == "Image"){
        m_mode = IMAGE;
        tgroupBox->hide();
        m_caseTrace->show();
    }
    else if (mode == "Fichier"){
        m_mode = FICHIER;
        tgroupBox->show();
        m_caseTrace->hide();
    }


}
