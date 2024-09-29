cmake_minimum_required(VERSION 3.23)
project(TetrisLib)
if(CODE_COVERAGE)
    target_code_coverage(${PROJECT_NAME} ALL)
endif()
file(GLOB_RECURSE ALL_SOURCES
        src/*.cpp
        inc/*.h
)

if (BUILD_TESTS)
    set(CMAKE_CXX_FLAGS "-g -O0  -fprofile-arcs -ftest-coverage")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WCompiler}")
endif ()
add_library(${PROJECT_NAME} SHARED "${ALL_SOURCES}")
target_link_libraries(${PROJECT_NAME} PRIVATE UnionModule)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}})