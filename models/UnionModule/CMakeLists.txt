cmake_minimum_required(VERSION 3.22)
project(UnionModule LANGUAGES CXX)
file(GLOB_RECURSE ALL_SOURCES
        src/*.cpp
        inc/*.h
)
if (BUILD_TESTS)
    set(CMAKE_CXX_FLAGS "-g -O0  -fprofile-arcs -ftest-coverage")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WCompiler}")
endif ()
add_library(UnionModule SHARED "${ALL_SOURCES}")
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
