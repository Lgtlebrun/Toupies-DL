QT += core gui opengl widgets

win32:LIBS += -lopengl32

TARGET = Ultimate-Toupie-Simulator

INCLUDEPATH = general

SOURCES += \
    general/source/ToupieChinoise.cpp \
    general/source/Matrice3.cpp \
    launcher/src/Bloc2Boutons.cpp \
    launcher/src/Grillage.cpp \
    launcher/src/LauncherAccueil.cpp \
    launcher/src/TextEdit.cpp \
    launcher/src/TypeBouton.cpp \
    launcher/src/bordMode.cpp \
    launcher/src/fichierSearch.cpp \
    general/source/constantes.cpp \
    general/source/Integrable.cpp \
    general/source/Toupie.cpp \
    general/source/Vecteur.cpp \
    general/source/Dessinable.cpp \
    general/source/ConeSimple.cpp \
    general/source/Integrateur.cpp \
    general/source/Systeme.cpp \
    general/source/TextViewer.cpp \
    general/source/Tests/Bille.cpp \
    general/source/Tests/Oscillateur.cpp \
    launcher/src/boutonPosition.cpp \
    launcher/src/QTextViewer.cpp \
    Qt_GL/glwidget.cc \
    Qt_GL/vue_opengl.cc \
    Qt_GL/sphere.cc \
    general/source/ObjetPhysique.cpp \
    general/source/Trace.cpp \
    main.cpp

HEADERS += \
    general/headers/ToupieChinoise.h \
    launcher/headers/Bloc2Boutons.h \
    launcher/headers/Grillage.h \
    launcher/headers/LauncherAccueil.h \
    launcher/headers/TextEdit.h \
    launcher/headers/TypeBouton.h \
    launcher/headers/bordMode.h \
    launcher/headers/fichierSearch.h \
    general/headers/constantes.h \
    general/headers/Clonable.h \
    general/headers/Integrable.h \
    general/headers/Dessinable.h \
    general/headers/Integrateur.h \
    general/headers/Systeme.h \
    general/headers/Toupie.h \
    general/headers/SupportADessin.h \
    general/headers/ConeSimple.h \
    general/headers/Vecteur.h \
    general/headers/Matrice3.h \
    general/headers/TextViewer.h \
    general/headers/Tests/Bille.h \
    general/headers/Tests/Oscillateur.h \
    launcher/headers/boutonPosition.h \
    launcher/headers/QTextViewer.h \
    Qt_GL/glwidget.h \
    Qt_GL/vue_opengl.h \
    Qt_GL/sphere.h \
    Qt_GL/vertex_shader.h \
    general/headers/ObjetPhysique.h \
    general/headers/Trace.h \



RESOURCES += \
    launcher/data/images.qrc \
    Qt_GL/resource.qrc


