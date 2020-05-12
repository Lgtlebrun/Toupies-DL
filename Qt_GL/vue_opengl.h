#ifndef VUEOPENGL_H
#define VUEOPENGL_H

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include "../general/headers/SupportADessin.h"
#include "../general/headers/Systeme.h"
#include "../general/headers/Tests/Bille.h"
#include "../general/headers/Tests/Oscillateur.h"
#include "../general/headers/ConeSimple.h"
#include "../general/headers/ToupieChinoise.h"
#include "../general/headers/Toupie.h"
#include "sphere.h"
#include "../general/headers/Trace.h"

class VueOpenGL : public SupportADessin {
 public:
  // méthode(s) de dessin (héritée(s) de SupportADessin)
  virtual void dessine(Systeme const& a_dessiner) override;
  virtual void dessine(Bille const&) override;
  virtual void dessine(ConeSimple const&) override;
  virtual void dessine(Oscillateur const&) override;
  virtual void dessine(ToupieChinoise const&) override;
  virtual void dessine(Toupie const&) override;
  virtual void dessine(const Trace &) override;

  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();
  void setPOV(Vecteur const& newPOV);

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes set
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  // méthode utilitaire offerte pour simplifier
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );
  void dessineSphere(QMatrix4x4 const& point_de_vue,
                       double rouge = 1.0, double vert = 1.0, double bleu = 1.0);
  void dessineLigne(Vecteur const& p1, Vecteur const& p2);

 private:
  // Un shader OpenGL encapsulé dans une classe Qt
  QOpenGLShaderProgram prog;
  GLSphere m_sphere;

  // Caméra
  QMatrix4x4 matrice_vue;
  Vecteur m_POV;

};

#endif
