cmake_minimum_required(VERSION 3.23)
project(BrickGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Os")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -Werror -Wextra")
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
find_package(GTest REQUIRED)
find_package(Curses REQUIRED)
include_directories(${Curses_INCLUDE_DIR})
add_subdirectory(models/SnakeCore)
add_subdirectory(models/TetrisCore)
add_subdirectory(models/UnionModule)
add_subdirectory(view/Desktop)
set(TestLibs TetrisLib SnakeLib ${GTEST_LIBRARIES} gtest_main)
set(DesktopLibs DesktopLib TetrisLib SnakeLib Qt::Core Qt::Gui Qt::Widgets)
set(CLI_LIBS SnakeLib UnionLib -lncurses)

set(Tests tests/tests.cpp)
set(Desktop view/Desktop/BrickGameDesktop.cpp)
set(CLI view/CLI/snakeCLI.cpp view/CLI/frontend.cpp)

if (NOT Qt6_FOUND)
    message(FATAL_ERROR "Qt6 not found! Please install Qt6 or specify its path.")
else ()
    message(STATUS "Qt6 Founded.")
endif ()

add_custom_target(snake_cli)
add_custom_target(brick_game_tests)
add_custom_target(brick_game_desktop)
add_executable(${PROJECT_NAME} ${Desktop})

target_link_libraries(${PROJECT_NAME} ${DesktopLibs})


