cmake_minimum_required(VERSION 3.23)
project(BrickGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")
set(WCompiler "-Wall -Werror -Wextra")
set(GCOV_FLAGS "-fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WCompiler} ${GCOV_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCOV_FLAGS}")
set(COVERAGE_OUTPUT_DIR "${CMAKE_BINARY_DIR}/coverage")

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

set(Tests tests/tests.cpp)
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
    message("Testing tool founded")
endif ()



# Создание цели для сборки тестов
if(BUILD_TESTS)
    message("Building tests...")
    add_executable(${PROJECT_NAME}_tests ${Tests})
    target_link_libraries(${PROJECT_NAME}_tests ${TestLibs})
    set_target_properties(${PROJECT_NAME}_tests PROPERTIES COMPILE_FLAGS "${GCOV_FLAGS}" LINK_FLAGS "${GCOV_FLAGS}")
    # Создаем целевую команду для запуска тестов с покрытием
    add_custom_command(TARGET ${PROJECT_NAME}_tests POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E env COVERAGE=ON ctest ${GTEST_COV_ARGS})
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

