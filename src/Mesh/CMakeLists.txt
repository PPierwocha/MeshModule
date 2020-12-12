# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

add_library(
    Mesh
    Mesh.h
    Mesh.cpp
)

target_include_directories(Mesh PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")