cmake_minimum_required(VERSION 3.22)

include(../../compilerConfig.cmake)
project(PrimeNumbersTest)

set(SOURCE_FILES
    PrimeNumbersTest.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE:${PROJECT_NAME}>)

find_package(GTest REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/.. PrimeNumbers)
target_link_libraries(${PROJECT_NAME} PRIVATE PrimeNumbers)
