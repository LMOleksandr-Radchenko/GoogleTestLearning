cmake_minimum_required(VERSION 3.22)

include(compilerConfig.cmake)
project(AllTests)

enable_testing()

add_subdirectory("Prime/Test")
add_subdirectory("Vector/Test")
add_subdirectory("Factorial/Test")
