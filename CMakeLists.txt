cmake_minimum_required(VERSION 3.10)

project(CProperty
        VERSION 1.0.0
        DESCRIPTION "C# Propertys to C++"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(.)

add_library(CProperty STATIC
        CProperty.cpp
        CProperty.hpp
)

set_target_properties(CProperty PROPERTIES
        VERSION 1.0.0
        PUBLIC_HEADER CProperty.hpp
        PREFIX ""
)

