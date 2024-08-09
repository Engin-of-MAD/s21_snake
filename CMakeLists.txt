cmake_minimum_required(VERSION 3.28)
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
        view/boardview.h
        view/boardview.cpp
        src/mainwindow.h
        src/ui_mainwindow.h
        src/mainwindow.cpp
        src/main.cpp
        src/gameobj.h
        src/gameobj.cpp
        src/mainwindow.ui
)
target_link_libraries(untitled2
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fno-limit-debug-info")