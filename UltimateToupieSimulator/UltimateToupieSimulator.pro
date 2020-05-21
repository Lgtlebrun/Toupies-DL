QT += core gui opengl widgets

win32:LIBS += -lopengl32

TARGET = Ultimate-Toupie-Simulator

INCLUDEPATH = ../general

SOURCES += \
    ../general/source/ToupieChinoise.cpp \
    ../general/source/Matrice3.cpp \
    src/Bloc2Boutons.cpp \
    src/Grillage.cpp \
    src/LauncherAccueil.cpp \
    src/TextEdit.cpp \
    src/TypeBouton.cpp \
    src/bordMode.cpp \
    src/fichierSearch.cpp \
    ../general/source/constantes.cpp \
    ../general/source/Integrable.cpp \
    ../general/source/Toupie.cpp \
    ../general/source/Vecteur.cpp \
    ../general/source/Dessinable.cpp \
    ../general/source/ConeSimple.cpp \
    ../general/source/Integrateur.cpp \
    ../general/source/Systeme.cpp \
    ../general/source/TextViewer.cpp \
    ../general/source/Tests/Bille.cpp \
    ../general/source/Tests/Oscillateur.cpp \
    src/boutonPosition.cpp \
    src/QTextViewer.cpp \
    ../Qt_GL/glwidget.cc \
    ../Qt_GL/vue_opengl.cc \
    ../Qt_GL/sphere.cc \
    ../general/source/ObjetPhysique.cpp \
    ../general/source/Trace.cpp \
    UltimateMain.cpp

HEADERS += \
    ../general/headers/ToupieChinoise.h \
    headers/Bloc2Boutons.h \
    headers/Grillage.h \
    headers/LauncherAccueil.h \
    headers/TextEdit.h \
    headers/TypeBouton.h \
    headers/bordMode.h \
    headers/fichierSearch.h \
    ../general/headers/constantes.h \
    ../general/headers/Clonable.h \
    ../general/headers/Integrable.h \
    ../general/headers/Dessinable.h \
    ../general/headers/Integrateur.h \
    ../general/headers/Systeme.h \
    ../general/headers/Toupie.h \
    ../general/headers/SupportADessin.h \
    ../general/headers/ConeSimple.h \
    ../general/headers/Vecteur.h \
    ../general/headers/Matrice3.h \
    ../general/headers/TextViewer.h \
    ../general/headers/Tests/Bille.h \
    ../general/headers/Tests/Oscillateur.h \
    headers/boutonPosition.h \
    headers/QTextViewer.h \
    ../Qt_GL/glwidget.h \
    ../Qt_GL/vue_opengl.h \
    ../Qt_GL/sphere.h \
    ../Qt_GL/vertex_shader.h \
    ../general/headers/ObjetPhysique.h \
    ../general/headers/Trace.h \



RESOURCES += \
    data/images.qrc \
    ../Qt_GL/resource.qrc


