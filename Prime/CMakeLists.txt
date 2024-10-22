cmake_minimum_required(VERSION 3.22)

include(../compilerConfig.cmake)
project(PrimeNumbers)

set(HEADER_FILES
    PrimeNumbers.h
)

set(SOURCE_FILES
    PrimeNumbers.cpp
)

add_library(PrimeNumbers SHARED ${SOURCE_FILES} ${HEADER_FILES})
