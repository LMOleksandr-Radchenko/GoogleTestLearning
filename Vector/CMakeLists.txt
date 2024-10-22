cmake_minimum_required(VERSION 3.22)

include(../compilerConfig.cmake)
project(Vector)

set(HEADER_FILES
    Vector.h
)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR})
