QT += core gui opengl widgets

win32:LIBS += -lopengl32

TARGET = Scientific-Toupie-Simulator

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    ../general/source/Trace.cpp \
    src/ScGLWidget.cpp \
    ScMain.cpp \
    src/ScWidget.cpp \
    src/QTextViewer.cpp \
    src/TextEdit.cpp \
    src/fichierSearch.cpp \
    src/Bloc2Boutons.cpp \
    ../Qt_GL/glwidget.cc \
    ../Qt_GL/vue_opengl.cc \
    ../Qt_GL/sphere.cc \
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
    ../general/source/ToupieChinoise.cpp \
    ../general/source/Matrice3.cpp \
    ../general/source/ObjetPhysique.cpp

HEADERS += \
    headers/ScGLWidget.h \
    ../general/headers/Trace.h \
    headers/ScWidget.h \
    headers/QTextViewer.h \
    headers/TextEdit.h \
    headers/fichierSearch.h \
    headers/Bloc2Boutons.h \
    ../Qt_GL/glwidget.h \
    ../Qt_GL/vue_opengl.h \
    ../Qt_GL/sphere.h \
    ../Qt_GL/vertex_shader.h \
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
    ../general/headers/ToupieChinoise.h \
    ../general/headers/ObjetPhysique.h


RESOURCES += \
    ../Qt_GL/resource.qrc \
    polices/police.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
