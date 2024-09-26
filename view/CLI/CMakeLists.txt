cmake_minimum_required(VERSION 3.23)
project(BrickGameCLI)
set(CMAKE_CXX_STANDARD 17)

set(CLI frontend.h
        frontend.cpp)
add_executable(snakeCLI.cpp ${CLI})
target_link_libraries(${PROJECT_NAME} )
