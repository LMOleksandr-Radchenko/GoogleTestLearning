cmake_minimum_required(VERSION 3.22)

include(../compilerConfig.cmake)
project(Factorial)

set(HEADER_FILES
    Factorial.h
)

set(SOURCE_FILES
    Factorial.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR})
