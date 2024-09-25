cmake_minimum_required(VERSION 3.23)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(untitled2


        models/TetrisCore/inc/TetrisGameModel.h
        models/TetrisCore/src/TetrisGameModel.cpp
        models/TetrisCore/inc/TetrominoFactory.h
        models/TetrisCore/src/TetrominoFactory.cpp
        models/TetrisCore/inc/TetrisBoardModel.h
        models/TetrisCore/src/TetrisBoardModel.cpp

        models/SharedModule/inc/BaseBoardModel.h
        models/SharedModule/src/BaseBoardModel.cpp
        models/SharedModule/inc/Timer.h
        models/SharedModule/src/Timer.cpp

        models/SnakeCore/inc/SnakeGameModel.h
        models/SnakeCore/src/SnakeGameModel.cpp
        models/SnakeCore/src/SnakeModel.cpp
        models/SnakeCore/inc/SnakeModel.h
        models/SnakeCore/src/FabricSnakeFood.cpp
        models/SnakeCore/inc/FabricSnakeFood.h
        main.cpp
        view/inc/BoardView.h
        view/src/BoardView.cpp
        view/inc/InfoBoardView.h
        view/src/InfoBoardView.cpp
        view/inc/StartScreenView.h
        view/src/StartScreenView.cpp
        view/inc/TetrisView.h
        view/src/TetrisView.cpp
        view/inc/SnakeView.h
        view/src/SnakeView.cpp
        view/inc/ButtonBoardView.h
        view/src/ButtonBoardView.cpp
        view/inc/mainwindow.h
        view/src/mainwindow.cpp
#        consoleView/main.cpp
#        consoleView/frontend.h
#        consoleView/frontend.cpp

        #        tests/tests.cpp
#        tests/test.h
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
#target_link_libraries(${PROJECT_NAME} PRIVATE ${GTEST_LIBRARIES} gtest_main)
target_link_libraries(${PROJECT_NAME} Qt::Core Qt::Gui Qt::Widgets)
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Os")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address")
#target_link_libraries(${PROJECT_NAME} PRIVATE -lcheck -lm -lrt -lpthread -lsubunit -g -fsanitize=address -lncurses)