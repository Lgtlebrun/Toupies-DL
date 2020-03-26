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

        ${FILES}
        main.cpp)

add_executable(testAll

        ${TEST_FILES})