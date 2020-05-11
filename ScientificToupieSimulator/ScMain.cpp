#include "headers/ScWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScWidget w;
    w.show();
    return a.exec();
}
