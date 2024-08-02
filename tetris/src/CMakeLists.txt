cmake_minimum_required(VERSION 3.22)
project(Tetris C)
set(CMAKE_C_STANDARD 11)


# Correctly find the NCurses package
#find_package(Curses REQUIRED)

# Request the NCurses include directories and libraries
#include_directories(${Curses_INCLUDE_DIRS})
#link_directories(${Curses_LIBRARY_DIRS})

# Specify sources
set(SOURCES
        gui/cli/frontend.c
        brick_game/tetris/backend.c
        brick_game/tests/check_lib.c
#                tetris.c
)

# Add the executable
add_executable(Tetris ${SOURCES})

# Link the NCurses libraries to the target
#target_link_libraries(Tetris ${Curses_LIBRARIES})

# Uncomment and adjust the linking for Check if needed
target_link_libraries(Tetris PRIVATE -lcheck -lm -lrt -lpthread -lsubunit -g -fsanitize=address -lncurses)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -g -fsanitize=address -lncurses")