#include <QApplication>
#include "glwidget.h"
#include <iostream>
#include "../general/headers/Tests/Bille.h"
#include "../general/headers/TextViewer.h"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  TextViewer T (std::cout);
  Bille B(T, {1.0,0.0,0.0},{0.0,2.0,3.0});
  IntegrateurEulerCromer I(0.0);
  Systeme S(T,I);
  GLWidget w(S);
  w.show();

  return a.exec();
}
