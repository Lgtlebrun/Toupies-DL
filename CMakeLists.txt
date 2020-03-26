cmake_minimum_required(VERSION 3.15)
project(Toupies_DL)

ADD_DEFINITIONS(-std=c++17 -Wall -Wextra)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)
include_directories(headers/Tests)

add_executable(Toupies_DL
        headers/Bille.h
        headers/Integrable.h
        headers/Integrateur.h
        headers/Matrice3.h
        headers/Oscillateur.h
        headers/Toupie.h
        headers/Vecteur.h
        source/Bille.cpp

        source/Integrable.cpp
        source/Integrateur.cpp
        source/Matrice3.cpp
        source/Oscillateur.cpp
        source/Toupie.cpp
        source/Vecteur.cpp
        )

add_executable(testAll
        source/Tests/testAll.cpp
        headers/Tests/Unittest.h
        headers/Matrice3.h
        headers/Vecteur.h
        headers/Tests/TestVecteur.h
        source/Tests/TestVecteur.cpp
        headers/Tests/TestMatrice.h
        source/Tests/TestMatrice.cpp
        source/Tests/Unittest.cpp
        source/Matrice3.cpp
        source/Vecteur.cpp)