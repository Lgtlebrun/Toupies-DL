QT += core gui opengl widgets
CONFIG += c++11

win32:LIBS += -lopengl32


TARGET = ex_05_gl

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    ../general/contenu.cc \
    main_qt_gl.cc \
    glwidget.cc \
    vue_opengl.cc \
    ../../source/Dessinable.cpp \
    ../../source/Toupie.cpp \
    ../../source/Integrable.cpp \
    ../../source/ConeSimple.cpp \
    ../../source/constantes.cpp \
    ../../source/Vecteur.cpp \

HEADERS += \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \
    ../../headers/SupportADessin.h \
    ../../headers/Dessinable.h \
    ../general/contenu.h \
    ../../headers/Toupie.h \
    ../../headers/Integrable.h \
    ../../headers/Clonable.h \
    ../../headers/ConeSimple.h \
    ../../headers/constantes.h \
    ../../headers/Vecteur.h \

RESOURCES += \
    resource.qrc
