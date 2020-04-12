CONFIG += c++11

TARGET = ex_05_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    ../../source/TextViewer.cpp \
    main_text.cc \
    ../../source/Dessinable.cpp \
    ../../source/Toupie.cpp \
    ../../source/Integrable.cpp \
    ../../source/ConeSimple.cpp \
    ../../source/constantes.cpp \
    ../../source/Vecteur.cpp \


HEADERS += \
    ../../headers/SupportADessin.h \
    ../../headers/Dessinable.h \
    ../general/contenu.h \
    ../../headers/Toupie.h \
    ../../headers/Integrable.h \
    ../../headers/Clonable.h \
    ../../headers/ConeSimple.h \
    ../../headers/constantes.h \
    ../../headers/Vecteur.h \
