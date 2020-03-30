cmake_minimum_required(VERSION 3.15)
project(Toupies_DL)

ADD_DEFINITIONS(-std=c++17)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)
include_directories(source)

set(FILES
        source/constantes.cpp
        source/Integrable.cpp
        source/Integrateur.cpp
        source/Matrice3.cpp
        source/Toupie.cpp
        source/Vecteur.cpp
        source/Systeme.cpp
        source/Dessinable.cpp
        source/ConeSimple.cpp
        source/TextViewer.cpp)


set(TEST_FILES
        source/constantes.cpp
        source/Tests/TestMatrice.cpp
        source/Tests/Unittest.cpp
        source/Matrice3.cpp
        source/Tests/testAll.cpp
        source/Tests/TestVecteur.cpp
        source/Vecteur.cpp headers/Tests/TestIntegrateur.h
        source/Tests/TestIntegrateur.cpp
        source/Integrable.cpp
        source/Integrateur.cpp
        source/Tests/Bille.cpp
        source/Tests/Oscillateur.cpp
        source/Tests/TestTextViewer.cpp
        source/Tests/testSysteme.cpp)

add_executable(Toupies_DL

        ${FILES}
        main.cpp)

add_executable(testAll
        ${FILES}
        ${TEST_FILES})