cmake_minimum_required(VERSION 3.23)
project(Assignment_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment_1
        insultgenerator_19srs12.cpp
        insultgenerator_19srs12.h
        cmake-build-debug/InsultsSource.txt
        TestInsultGenerator.cpp)
