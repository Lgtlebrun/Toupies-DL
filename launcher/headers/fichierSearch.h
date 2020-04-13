//
// Created by lgtle on 13/04/2020.
//

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QString>
#include <QPushButton>
#include "Bloc2Boutons.h"


#ifndef TOUPIES_DL_FICHIERSEARCH_H
#define TOUPIES_DL_FICHIERSEARCH_H


class FichierSearch : public QWidget {

public:

    FichierSearch();

protected:

    Bloc2Boutons* m_blocBoutons;
    QTextEdit* m_bar;
    QString m_path;

};



#endif //TOUPIES_DL_FICHIERSEARCH_H
