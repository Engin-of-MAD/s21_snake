cmake_minimum_required(VERSION 3.23)
project(SnakeLib)
set(SnakeCore
        inc/SnakeGameModel.h
        inc/FabricSnakeFood.h
        inc/SnakeModel.h
        src/SnakeGameModel.cpp
        src/FabricSnakeFood.cpp
        src/SnakeModel.cpp)
add_library(SnakeLib SHARED "${SnakeCore}")
target_link_libraries(SnakeLib PRIVATE UnionLib)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})