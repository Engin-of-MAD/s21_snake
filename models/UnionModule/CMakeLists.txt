cmake_minimum_required(VERSION 3.22)
project(UnionModule LANGUAGES CXX)
file(GLOB_RECURSE ALL_SOURCES
        src/*.cpp
        inc/*.h
)

set(CMAKE_INSTALL_BINDIR "${INSTALL_PREFIX}/bin")
set(CMAKE_INSTALL_LIBDIR "${INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_INCLUDEDIR "${INSTALL_PREFIX}/include")

set(CMAKE_CXX_FLAGS "-g -O0  -fprofile-arcs -ftest-coverage -fPIC")
add_library(UnionModule SHARED "${ALL_SOURCES}")
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS ${PROJECT_NAME}
        EXPORT UnionModule
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)