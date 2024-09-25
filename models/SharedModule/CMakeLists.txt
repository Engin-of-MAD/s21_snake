get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME_WE)
cmake_minimum_required(VERSION 3.22)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME}
        inc/BaseBoardModel.h
        src/BaseBoardModel.cpp
        inc/Timer.h
        src/Timer.cpp)
