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
        view/inc/ButtonBoardView.h
        view/src/ButtonBoardView.cpp
        view/inc/mainwindow.h
        view/src/mainwindow.cpp

        models/TetrisCore/inc/TetrisGameModel.h
        models/TetrisCore/src/TetrisGameModel.cpp
        models/TetrisCore/inc/TetrominoFactory.h
        models/TetrisCore/src/TetrominoFactory.cpp

        models/inc/BaseBoardModel.h
        models/src/BaseBoardModel.cpp
        models/inc/Timer.h
        models/src/Timer.cpp
        models/src/main.cpp

        view/inc/StartScreenView.h
        view/src/StartScreenView.cpp
        view/inc/TetrisView.h
        view/src/TetrisView.cpp
        view/inc/SnakeView.h
        view/src/SnakeView.cpp
        models/SnakeCore/inc/SnakeGameModel.h
        models/SnakeCore/src/SnakeGameModel.cpp
        models/SnakeCore/src/SnakeModel.cpp
        models/SnakeCore/inc/SnakeModel.h
        view/inc/BoardView.h
        view/src/BoardView.cpp
        view/inc/InfoBoardView.h
        view/src/InfoBoardView.cpp
        models/TetrisCore/inc/TetrisBoardModel.h
        models/TetrisCore/src/TetrisBoardModel.cpp
)
target_link_libraries(untitled2
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Os")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address")
