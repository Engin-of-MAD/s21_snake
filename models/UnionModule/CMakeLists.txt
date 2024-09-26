cmake_minimum_required(VERSION 3.22)
project(UnionLib)
set(Union
        inc/BaseBoardModel.h
        inc/Timer.h
        src/BaseBoardModel.cpp
        src/Timer.cpp)

add_library(${PROJECT_NAME} SHARED "${Union}")
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})