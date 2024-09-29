cmake_minimum_required(VERSION 3.23)
project(SnakeModule)
if(CODE_COVERAGE)
    target_code_coverage(${PROJECT_NAME} ALL)
endif()

file(GLOB_RECURSE ALL_SOURCES
        src/*.cpp
        inc/*.h
)
if (BUILD_TESTS)
    set(CMAKE_CXX_FLAGS "-g -O0  -fprofile-arcs -ftest-coverage ${WCompiler}")
endif ()
add_library(SnakeModule SHARED "${ALL_SOURCES}")
target_link_libraries(SnakeModule PRIVATE UnionModule)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})