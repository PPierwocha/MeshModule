cmake_minimum_required(VERSION 2.8)

add_library(
    Element
    Element.h
    Element.cpp
)

add_library(
    Line
    Line.h
    Line.cpp
)

add_library(
    Triangle
    Triangle.h
    Triangle.cpp
)

target_include_directories(Element PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Line PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Triangle PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")