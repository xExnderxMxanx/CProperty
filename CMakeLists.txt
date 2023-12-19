cmake_minimum_required(VERSION 3.10)

project(CProperty
        VERSION 1.0.0
        DESCRIPTION "C# Propertys to C++"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(CProperty CProperty.hpp CProperty.cpp)

