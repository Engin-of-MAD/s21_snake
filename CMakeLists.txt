cmake_minimum_required(VERSION 3.23)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled2
        view/inc/boardview.h
        view/boardview.cpp
        view/inc/mainwindow.h
        view/inc/ui_mainwindow.h
        view/mainwindow.cpp
        src/main.cpp
        src/gameModel.h
        src/gameModel.cpp
        view/mainwindow.ui
        src/boardModel.cpp
        src/boardModel.h
        src/TetraminoFactory.cpp
        src/TetraminoFactory.h
)
target_link_libraries(untitled2
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address")
