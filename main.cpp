#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include "launcher/headers/LauncherAccueil.h"


using namespace std;



int main(int argc, char *argv[]){



    QApplication app(argc, argv);
    LauncherAccueil launcher;


    launcher.show();

    return app.exec();

}


// To do list : sur les ordis du CO: programmer le gnuplot de TestIntegrateur
