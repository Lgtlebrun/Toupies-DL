#include "headers/ScWidget.h"

#include <QApplication>

/// MAIN DE SCIENTIFIC TOUPIE SIMULATOR  - All Rights reserved

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScWidget w;
    w.show();
    return a.exec();
}
