#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps
#include "vue_opengl.h"
#include "../general/headers/Systeme.h"


class GLWidget : public QOpenGLWidget
/* La fenêtre hérite de QOpenGLWidget
 * les événements (clavier, souris, temps) sont des méthodes virtuelles à redéfinir. */
{


public:
    GLWidget(Systeme& S, Vecteur const& POV = Vecteur({4.5,-10.0,0.0}),
             QWidget* parent = nullptr)
    : QOpenGLWidget(parent)
     , m_s(S), m_memoire(vue)                   // la simulation commence qu'une fois le systeme établi
  {vue.setPOV(POV);
   m_s.changeSupport(vue);}
  virtual ~GLWidget() {}

    ObjetPhysique* getCorps(size_t i) {return m_s.getCorps(i);}


protected:
  // Les 3 méthodes clés de la classe QOpenGLWidget à réimplémenter
  virtual void initializeGL()                  override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL()                       override;

  // Méthodes de gestion d'évènements
  virtual void keyPressEvent(QKeyEvent* event) override;
  virtual void mousePressEvent(QMouseEvent* event) override;
  virtual void mouseMoveEvent(QMouseEvent* event)  override;
  virtual void timerEvent(QTimerEvent* event)  override;

  // Méthodes de gestion interne
  void pause();

  // Vue : ce qu'il faut donner au contenu pour qu'il puisse se dessiner sur la vue
  VueOpenGL vue;

  // Timer
  int timerId;
  // pour faire évoluer les objets avec le bon "dt"
  QTime chronometre;

  // objets à dessiner, faire évoluer
  Systeme m_s;
  Trace m_memoire;

  QPoint lastMousePosition;
};

#endif // GLWIDGET_H
