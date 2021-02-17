# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/../bin/tests)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


# Project's name

project(MeshModule_Test_01)
# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/../src/Mesh")


file(GLOB source_list "${PROJECT_SOURCE_DIR}/test_mesh_01.cpp" )

# Libraries
add_subdirectory("${PROJECT_SOURCE_DIR}/../src/Mesh" "${PROJECT_SOURCE_DIR}/../src/Mesh")



add_executable(test_mesh_01 ${source_list})


target_link_libraries(test_mesh_01 PRIVATE Mesh)
