cmake_minimum_required(VERSION 3.15)
project(Toupies_DL)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)
include_directories(headers/Tests)

add_executable(Toupies_DL
        headers/Tests/TestMatrice.h
        headers/Tests/TestVecteur.h
        headers/Tests/Unittest.h
        headers/Bille.h
        headers/ConeSimple.h
        headers/Integrable.h
        headers/Integrateur.h
        headers/Matrice3.h
        headers/Oscillateur.h
        headers/Toupie.h
        headers/Vecteur.h
        source/Tests/TestMatrice.cpp
        source/Tests/TestVecteur.cpp
        source/Tests/Unittest.cpp
        source/Bille.cpp
        source/ConeSimple.cpp
        source/Integrable.cpp
        source/Integrateur.cpp
        source/Matrice3.cpp
        source/Oscillateur.cpp
        source/Toupie.cpp
        source/Vecteur.cpp)
