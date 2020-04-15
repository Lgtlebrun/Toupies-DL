QT += core gui opengl widgets
CONFIG += c++11

win32:LIBS += -lopengl32


TARGET = ex_05_gl

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_qt_gl.cc \
    glwidget.cc \
    vue_opengl.cc

HEADERS += \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \
    general/headers/Dessinable.h \
    general/headers/SupportADessin.h \
    general/headers/Systeme.h \
    general/headers/ConeSimple.h \
    general/headers/Tests/Bille.h \
    general/headers/Tests/Oscillateur.h

RESOURCES += \
    resource.qrc
