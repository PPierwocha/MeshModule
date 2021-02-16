cmake_minimum_required(VERSION 2.8)

add_library(
    Face
    Face.h
    Face.cpp
)



target_include_directories(Face PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
