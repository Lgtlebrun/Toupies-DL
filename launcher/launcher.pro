QT += core gui opengl widgets
CONFIG += c++11

win32:LIBS += -lopengl32


LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    src/LauncherAccueil.cpp \
    src/Bloc2Boutons.cpp \
    src/fichierSearch.cpp \
    src/Grillage.cpp \
    src/boutonPosition.cpp \
    src/bordMode.cpp \
    src/TypeBouton.cpp
    main.cpp

HEADERS += \
    headers/LauncherAccueil.h \
    headers/Bloc2Boutons.h \
    headers/fichierSearch.h \
    headers/Grillage.h \
    headers/boutonPosition.h \
    headers/bordMode.h \
    headers/TypeBouton.h

RESOURCES += \
    data/resource.qrc
