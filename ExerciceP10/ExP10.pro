QT += core gui opengl widgets

win32:LIBS += -lopengl32

TARGET = ExerciceP10

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    exerciceP10.cpp \
    ../general/source/Trace.cpp \
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
    ../general/headers/Trace.h \
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

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

