cmake_minimum_required(VERSION 3.23)
project(TetrisModule)
file(GLOB_RECURSE ALL_SOURCES
        src/*.cpp
        inc/*.h
)

set(CMAKE_INSTALL_BINDIR "${INSTALL_PREFIX}/bin")
set(CMAKE_INSTALL_LIBDIR "${INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_INCLUDEDIR "${INSTALL_PREFIX}/include")

set(CMAKE_CXX_FLAGS "-g -O0  -fprofile-arcs -ftest-coverage -fPIC")
add_library(TetrisModule SHARED "${ALL_SOURCES}")
target_link_libraries(TetrisModule PRIVATE UnionModule)
target_include_directories(TetrisModule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}})

install(TARGETS ${PROJECT_NAME}
        EXPORT TetrisLibTargets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)