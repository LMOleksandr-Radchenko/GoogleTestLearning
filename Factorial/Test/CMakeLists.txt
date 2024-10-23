cmake_minimum_required(VERSION 3.22)

include(../../compilerConfig.cmake)
project(FactorialTest)

set(SOURCE_FILES
FactorialTest.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE:${PROJECT_NAME}>)

find_package(GTest REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gmock GTest::gmock_main)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/.. Factorial)
target_link_libraries(${PROJECT_NAME} PRIVATE Factorial)
