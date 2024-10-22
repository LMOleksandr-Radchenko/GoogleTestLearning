cmake_minimum_required(VERSION 3.22)

include(../compilerConfig.cmake)
project(PrimeNumbers)

set(HEADER_FILES
    PrimeNumbers.h
)

set(SOURCE_FILES
    PrimeNumbers.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR})
