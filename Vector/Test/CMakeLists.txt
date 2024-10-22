cmake_minimum_required(VERSION 3.22)

include(../../compilerConfig.cmake)
project(VectorTest)

set(SOURCE_FILES
    VectorTest.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(GTest REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/.. Vector)
target_link_libraries(${PROJECT_NAME} PRIVATE Vector)
