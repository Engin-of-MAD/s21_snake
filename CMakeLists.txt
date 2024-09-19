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

        models/inc/TetrisGameModel.h
        models/src/TetrisGameModel.cpp
        models/inc/BaseBoardModel.h
        models/src/BaseBoardModel.cpp
        models/inc/TetrominoFactory.h
        models/src/TetrominoFactory.cpp
        models/inc/Timer.h
        models/src/Timer.cpp
        models/src/main.cpp

        view/inc/StartScreenView.h
        view/src/StartScreenView.cpp
        view/inc/TetrisView.h
        view/src/TetrisView.cpp
        view/inc/SnakeView.h
        view/src/SnakeView.cpp
        models/inc/SnakeGameModel.h
        models/src/SnakeGameModel.cpp
        models/inc/SnakeItem.h
        models/src/SnakeModel.cpp
        models/inc/SnakeModel.h
        models/src/SnakeItem.cpp
        view/inc/BoardView.h
        view/src/BoardView.cpp
        view/inc/InfoBoardView.h
        view/src/InfoBoardView.cpp
        models/inc/TetrisBoardModel.h
        models/src/TetrisBoardModel.cpp
)
target_link_libraries(untitled2
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Os")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address")
