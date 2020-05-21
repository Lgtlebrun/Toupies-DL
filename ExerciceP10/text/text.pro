CONFIG += c++11

TARGET = ex_05_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_text.cc

HEADERS += \
    ../general/headers/Systeme.h \
    ../general/headers/TextViewer.h \
    ../general/headers/Dessinable.h \
    ../general/headers/SupportADessin.h
