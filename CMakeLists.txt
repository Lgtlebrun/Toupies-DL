cmake_minimum_required(VERSION 3.15)
project(Toupies_DL)

ADD_DEFINITIONS(-std=c++17)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)
include_directories(source)

set(FILES
        ../general/source/constantes.cpp
        ../general/source/Integrable.cpp
        ../general/source/Integrateur.cpp
        ../general/source/Matrice3.cpp
        ../general/source/Toupie.cpp
        ../general/source/Vecteur.cpp
        ../general/source/Systeme.cpp
        ../general/source/Dessinable.cpp
        ../general/source/ConeSimple.cpp
        ../general/source/TextViewer.cpp
        ../general/source/Tests/Bille.cpp
        ../general/source/Tests/Oscillateur.cpp)


set(TEST_FILES
        ../general/source/constantes.cpp
        ../general/source/Tests/TestMatrice.cpp
        ../general/source/Tests/Unittest.cpp
        ../general/source/Matrice3.cpp
        ../general/source/Tests/testAll.cpp
        ../general/source/Tests/TestVecteur.cpp
        ../general/source/Vecteur.cpp
        ../general/headers/Tests/TestIntegrateur.h
        ../general/source/Tests/TestIntegrateur.cpp
        ../general/source/Integrable.cpp
        ../general/source/Integrateur.cpp
        ../general/source/Tests/Bille.cpp
        ../general/source/Tests/Oscillateur.cpp
        ../general/source/Tests/testSysteme.cpp
        ../general/headers/Clonable.h)

add_executable(Toupies_DL
        ${FILES}
        main.cpp)

add_executable(testAll
        ${FILES}
        ${TEST_FILES})


add_executable(exoa
        ${FILES}
        exercice9a.cpp)

add_executable(exob
        ${FILES}
        exercice9b.cpp)