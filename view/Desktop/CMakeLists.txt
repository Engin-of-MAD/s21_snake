cmake_minimum_required(VERSION 3.22)
project(DesktopLib)
set(DesktopCore
        inc/mainwindow.h
        inc/BoardView.h
        inc/SnakeView.h
        inc/TetrisView.h
        inc/InfoBoardView.h
        inc/StartScreenView.h
        inc/ButtonBoardView.h

        src/BoardView.cpp
        src/InfoBoardView.cpp
        src/StartScreenView.cpp
        src/TetrisView.cpp
        src/SnakeView.cpp
        src/ButtonBoardView.cpp
        src/mainwindow.cpp
)
add_library(${PROJECT_NAME} SHARED "${DesktopCore}")
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(DesktopLib PRIVATE Qt::Core Qt::Gui Qt::Widgets)