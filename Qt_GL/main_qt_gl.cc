#include <QApplication>
#include "glwidget.h"
#include <iostream>
#include "../general/headers/Tests/Bille.h"
#include "../general/headers/TextViewer.h"
#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  TextViewer T(std::cout);
  ConeSimple C(T, {0.0,0.0,0.0},{0.0,0.0,5.0},{0.0,2.0,0.0},0.5,1.5,10);
  Oscillateur O1(T, {5.0,0.0,0.0}, {0.0,2.0,-3.0}, {0.0,0.0,0.0}, 1);
  Oscillateur O2(T, {4.0,0.0,0.0}, {0.0,-7.0,1.0}, {9.0,0.0,0.0}, 1);
  Bille B(T, {1.0,0.0,2.0},{2.0,1.0,5.0},2);
  IntegrateurEulerCromer I(0.0);
  Systeme S(T,I);
  S.addIntegrable(C);
  S.addIntegrable(O1);
  S.addIntegrable(O2);
  S.addIntegrable(B);
  GLWidget w(S);
  w.show();

  return a.exec();
}
