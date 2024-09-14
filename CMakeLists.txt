cmake_minimum_required(VERSION 3.23)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled2
        view/inc/boardview.h
        view/src/boardview.cpp
        view/inc/mainwindow.h
        view/src/mainwindow.cpp
        models/src/main.cpp
        models/inc/gameModel.h
        models/src/gameModel.cpp
        models/src/boardModel.cpp
        models/inc/boardModel.h
        models/src/TetrominoFactory.cpp
        models/inc/TetrominoFactory.h
        models/src/Timer.cpp
        models/inc/Timer.h
        tests/tests.cpp
)
target_link_libraries(untitled2
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Os")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address")
