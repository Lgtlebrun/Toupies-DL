TEMPLATE = lib

CONFIG = staticlib c++11

HEADERS += \
    headers/constantes.h \
    headers/Clonable.h \
    headers/Integrable.h \
    headers/Dessinable.h \
    headers/Integrateur.h \
    headers/Systeme.h \
    headers/Toupie.h \
    headers/SupportADessin.h \
    headers/ConeSimple.h \
    headers/Vecteur.h \
    headers/TextViewer.h \
    headers/Tests/Bille.h \
    headers/Tests/Oscillateur.h

SOURCES += \
    source/constantes.cpp \
    source/Integrable.cpp \
    source/Toupie.cpp \
    source/Vecteur.cpp \
    source/Dessinable.cpp \
    source/ConeSimple.cpp \
    source/Integrateur.cpp \
    source/Systeme.cpp \
    source/TextViewer.cpp \
    source/Tests/Bille.cpp \
    source/Tests/Oscillateur.cpp
