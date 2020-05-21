#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include "headers/LauncherAccueil.h"


using namespace std;

/// Main d'ULTIMATE TOUPIE SIMULATOR - All rights reserved

int main(int argc, char *argv[]){


    QApplication app(argc, argv);
    LauncherAccueil launcher;


    launcher.show();

    return app.exec();

}


