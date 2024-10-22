cmake_minimum_required(VERSION 3.22)

include(../../compilerConfig.cmake)
project(PrimeNumbersTest)

set(SOURCE_FILES
    PrimeNumbersTest.cpp
)

add_library(PrimeNumbers SHARED ${SOURCE_FILES})

find_package(GTest REQUIRED)
target_link_libraries(PrimeNumbers PRIVATE GTest::gtest GTest::gtest_main)
