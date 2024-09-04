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
        view/mainwindow.cpp
        models/main.cpp
        models/gameModel.h
        models/gameModel.cpp
        models/boardModel.cpp
        models/boardModel.h
        models/TetraminoFactory.cpp
        models/TetraminoFactory.h
)
target_link_libraries(untitled2
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address")
