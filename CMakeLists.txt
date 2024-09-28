cmake_minimum_required(VERSION 3.23)
project(BrickGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

find_program(GCOV gcov)
find_program(LCOV lcov)
find_program(GENHTML genhtml)

find_package(Git REQUIRED)
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
find_package(GTest REQUIRED)

add_subdirectory(models/SnakeCore)
add_subdirectory(models/TetrisCore)
add_subdirectory(models/UnionModule)
add_subdirectory(view/Desktop)

set(TestLibs TetrisLib SnakeLib ${GTEST_LIBRARIES} gtest_main)
set(DesktopLibs DesktopLib TetrisLib SnakeLib Qt::Core Qt::Gui Qt::Widgets)
set(CLI_LIBS SnakeLib UnionLib -lncurses)

set(Tests
        models/SnakeCore/test/tests.cpp
        models/TetrisCore/test/tests.cpp
        models/UnionModule/test/tests.cpp)
set(Desktop view/Desktop/BrickGameDesktop.cpp)
set(CLI view/CLI/snakeCLI.cpp view/CLI/frontend.cpp)

option(BUILD_SNAKE_CLI "Build snake CLI version" ON)
option(BUILD_DESKTOP_APP "Build desktop application" ON)
option(BUILD_TESTS "Build tests" ON)

if(NOT Qt6_FOUND)
    message(FATAL_ERROR "Qt6 not found! Please install Qt6 or specify its path.")
else()
    message(STATUS "Qt6 Founded.")
endif()
if (GCOV OR LCOV OR GENHTML)
    message("Testing tool founded.")
endif ()

if (BUILD_TESTS)
    set(CMAKE_CXX_FLAGS " -fprofile-arcs -ftest-coverage ")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCOV_FLAGS}")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WCompiler}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
endif ()


# Создание цели для сборки тестов
if(BUILD_TESTS)
    message("Building tests...")
    add_executable(test ${Tests})
    target_link_libraries(test ${TestLibs})
    add_custom_target(gcov_report
            ./test
            COMMAND lcov --capture --directory . --output-file coverage.info
            COMMAND genhtml -o report coverage.info
            COMMAND xdg-open report/index.html
            DEPENDS test
    )
endif()

# Создание цели для сборки CLI версии
if(BUILD_SNAKE_CLI)
    add_executable(${PROJECT_NAME}_snake_cli ${CLI})
    target_link_libraries(${PROJECT_NAME}_snake_cli ${CLI_LIBS})
endif()

# Создание цели для сборки десктопного приложения
if(BUILD_DESKTOP_APP)
    add_executable(${PROJECT_NAME}_app ${Desktop})
    target_link_libraries(${PROJECT_NAME}_app ${DesktopLibs})
endif()
