cmake_minimum_required(VERSION 3.15)
project(Toupies_DL)

ADD_DEFINITIONS(-std=c++17)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)
include_directories(source)

set(FILES
        source/Integrable.cpp
        source/Integrateur.cpp
        source/Matrice3.cpp
        source/Oscillateur.cpp
        source/Toupie.cpp
        source/Vecteur.cpp
        source/Systeme.cpp
        source/Bille.cpp
        source/Dessinable.cpp)


set(TEST_FILES
        source/Tests/TestMatrice.cpp
        source/Tests/Unittest.cpp
        source/Matrice3.cpp
        source/Tests/testAll.cpp
        source/Tests/TestVecteur.cpp
        source/Vecteur.cpp)

add_executable(Toupies_DL
        headers/Bille.h
        headers/Integrable.h
        headers/Integrateur.h
        headers/Matrice3.h
        headers/Oscillateur.h
        headers/Toupie.h
        headers/Vecteur.h
        headers/Dessinable.h
        headers/SupportADessin.h
        headers/ConeSimple.h
        ${FILES}
        main.cpp)

add_executable(testAll

        headers/Tests/Unittest.h
        headers/Matrice3.h
        headers/Vecteur.h
        headers/Tests/TestVecteur.h
        headers/Tests/TestMatrice.h
        headers/Systeme.h
        ${TEST_FILES})