cmake_minimum_required(VERSION 3.23)
project(TetrisLib)

set(TetrisCore
        src/TetrisGameModel.cpp
        src/TetrisBoardModel.cpp
        src/TetrominoFactory.cpp
        inc/TetrisGameModel.h
        inc/TetrominoFactory.h
        inc/TetrisBoardModel.h)
add_library(${PROJECT_NAME} SHARED "${TetrisCore}")
target_link_libraries(${PROJECT_NAME} PRIVATE UnionLib)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}})