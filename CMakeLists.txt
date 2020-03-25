cmake_minimum_required(VERSION 3.15)
project(Toupies_DL)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)
include_directories(headers/Tests)
include_directories(source)

add_executable(Toupies_DL
    headers/Tests/TestVecteur.h
    headers/Tests/Unittest.h
    headers/Vecteur.h
    source/Tests/TestVecteur.cpp
    source/Tests/Unittest.cpp
    source/Vecteur.cpp)
