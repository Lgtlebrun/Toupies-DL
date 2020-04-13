QT += widgets



SOURCES += \
    launcher/src/Bloc2Boutons.cpp \
    launcher/src/LauncherAccueil.cpp \
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
    main.cpp

HEADERS += \
    launcher/headers/Bloc2Boutons.h \
    launcher/headers/LauncherAccueil.h \
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
    general/headers/TextViewer.h \
    general/headers/Tests/Bille.h \
    general/headers/Tests/Oscillateur.h


DISTFILES += \
    build-ex_05-Desktop_Qt_5_14_1_MinGW_32_bit-Debug/general/libgeneral.a \
    launcher/data/toupie-bleue-marine.gif

