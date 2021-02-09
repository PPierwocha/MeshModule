cmake_minimum_required(VERSION 2.8)

add_library(
    element
    Element.h
    Element.cpp
)

target_include_directories(element PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")