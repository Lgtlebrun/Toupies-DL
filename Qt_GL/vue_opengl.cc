#include "vue_opengl.h"
#include "vertex_shader.h"  // Identifiants Qt de nos différents attributs
#include <cmath>

// ======================================================================
void VueOpenGL::dessine(Bille const& B) {

    /* Jette une petite boîte à chaque étape, dont le seul mouvement est une  *
     * translation selon le déplacement que va ordonner l'équation du mvt     */

    QMatrix4x4 matrice;

    Vecteur position(B.getParam());

    matrice.translate(position.getCoord(0), position.getCoord(1),
                      position.getCoord(2)-B.getRayon());

    matrice.scale(B.getRayon());

    dessineSphere(matrice,1.0,0.0,0.0);

}
void VueOpenGL::dessine(ConeSimple const& C) {

    /* puisque la toupie doit tourner sur elle-même, il faut d'abord faire *
     * les rotations puis la translation. Nous la faisons proportionnelle  *
     * à la hauteur. */

    QMatrix4x4 matrice;

    Vecteur enDegre(C.getParam().rad_to_deg());

    matrice.translate(  C.getPosition().getCoord(0)
                      , C.getPosition().getCoord(1)
                      , C.getPosition().getCoord(2)+C.getHauteur()/2.0);

    matrice.rotate(enDegre.getCoord(0), 1.0, 0.0, 0.0);

    matrice.rotate(enDegre.getCoord(1), 0.0, 0.0, 1.0);

    matrice.rotate(  enDegre.getCoord(2)
                   , sin(enDegre.getCoord(0))*cos(enDegre.getCoord(1))
                   , sin(enDegre.getCoord(0))*cos(enDegre.getCoord(1))
                   , cos(enDegre.getCoord(0))        );

    matrice.rotate(45, 1.0, 0.0, 0.0);

    matrice.rotate(45, 0.0, 1.0, 0.0);

    matrice.scale(C.getHauteur()/2.0);

    dessineCube(matrice);

}
void VueOpenGL::dessine(Oscillateur const& O) {

    /* On assume que l'oscillateur ne peut pas tourner sur lui-même. Le mvt    *
     * est alors une succession de translations. Nous rendons les oscillateurs *
     * deux fois plus petits que les Billes pour les distinguer mieux          */

    QMatrix4x4 matrice;

    Vecteur position(O.getParam());

    matrice.translate(position.getCoord(0), position.getCoord(1),
                      position.getCoord(2));

    matrice.scale(O.getRayon()/2.0);

    dessineSphere(matrice, 0.0);

}
// ======================================================================
void VueOpenGL::dessine(Systeme const& a_dessiner) {

    for (size_t k(0); k < a_dessiner.getNbCorps() ; ++k) {

            a_dessiner.getCorps(k)->dessine();

   }

}
// ======================================================================
void VueOpenGL::init()
{
  /* Initialise notre vue OpenGL.
   * Dans cet exemple, nous créons et activons notre shader.
   *
   * En raison du contenu des fichiers *.glsl, le shader de cet exemple
   * NE permet QUE de dessiner des primitives colorées
   * (pas de textures, brouillard, reflets de la lumière ou autres).
   *
   * Il est séparé en deux parties VERTEX et FRAGMENT.
   * Le VERTEX :
   * - récupère pour chaque sommet des primitives de couleur (dans
   *     l'attribut couleur) et de position (dans l'attribut sommet)
   * - multiplie l'attribut sommet par les matrices 'vue_modele' et
   *     'projection' et donne le résultat à OpenGL
   *   - passe la couleur au shader FRAGMENT.
   *
   * Le FRAGMENT :
   *   - applique la couleur qu'on lui donne
   */

  prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

  /* Identifie les deux attributs du shader de cet exemple
   * (voir vertex_shader.glsl).
   *
   * L'attribut identifié par 0 est particulier, il permet d'envoyer un
   * nouveau "point" à OpenGL
   *
   * C'est pourquoi il devra obligatoirement être spécifié et en dernier
   * (après la couleur dans cet exemple, voir plus bas).
   */

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);

  // Compilation du shader OpenGL
  prog.link();

  // Activation du shader
  prog.bind();

  /* Activation du "Test de profondeur" et du "Back-face culling"
   * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
   * partielement caché par d'autres objets.
   *
   * Le Back-face culling consiste à ne dessiner que les face avec ordre
   * de déclaration dans le sens trigonométrique.
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  m_sphere.initialize();
  initializePosition();
}

// ======================================================================
void VueOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.rotate(-90, 1.0, 0.0, 0.0);
  matrice_vue.translate(-m_POV.getCoord(0),-m_POV.getCoord(1)
                        , -m_POV.getCoord(2));
}
// ======================================================================
void VueOpenGL::setPOV(Vecteur const& newPOV) {
    // point de vue sur le système
    m_POV = newPOV;

}

// ======================================================================
void VueOpenGL::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::dessineCube (QMatrix4x4 const& point_de_vue)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_QUADS);
  // face coté X = +1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);

  // face coté X = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);

  // face coté Y = +1
  prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);

  // face coté Y = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0); // cyan
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);

  // face coté Z = +1
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); // jaune
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);

  // face coté Z = -1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0); // magenta
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);

  glEnd();
}

// =====================================================================
void VueOpenGL::dessineSphere (QMatrix4x4 const& point_de_vue,
                               double rouge, double vert, double bleu)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  prog.setAttributeValue(CouleurId, rouge, vert, bleu);  // met la couleur
  m_sphere.draw(prog, SommetId);                          // dessine la sphère
}
