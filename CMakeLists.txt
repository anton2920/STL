cmake_minimum_required(VERSION 3.10)

project(STL VERSION 1.4 DESCRIPTION "The Standard Template Library (STL) for C")
include(GNUInstallDirs)

set(CMAKE_C_STANDARD 90)

# enable_testing()

add_subdirectory(src)
add_subdirectory(test)
