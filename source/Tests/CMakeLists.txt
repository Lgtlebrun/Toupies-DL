cmake_minimum_required(VERSION 3.15)
project(TestMatrice)

set(CMAKE_CXX_STANDARD 14)

include_directories(../../headers)
include_directories(../../headers/Tests)

add_executable(Toupies_DL
        ../../headers/Tests/Unittest.h
        ../../headers/Matrice3.h
        ../../headers/Vecteur.h
        TestMatrice.cpp
        Unittest.cpp
        ../Matrice3.cpp
        ../Vecteur.cpp ../../headers/Tests/TestMatrice.h)
