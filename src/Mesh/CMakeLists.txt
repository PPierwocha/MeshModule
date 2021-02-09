# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# include_directories(../../Element)


# Libraries
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../Element" "${CMAKE_CURRENT_SOURCE_DIR}/../Element")

add_library(
    Mesh
    Mesh.h
    Mesh.cpp
)

target_link_libraries(Mesh PUBLIC element)

target_include_directories(Mesh PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")