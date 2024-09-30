cmake_minimum_required(VERSION 3.23)
project(BrickGame)

include(GNUInstallDirs)
include(CPack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

##########################################################################################
#install dirs

set(INSTALL_PREFIX "$ENV{HOME}/.local")
set(CMAKE_INSTALL_BINDIR "${INSTALL_PREFIX}/bin")
set(CMAKE_INSTALL_LIBDIR "${INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_INCLUDEDIR "${INSTALL_PREFIX}/include")
set(CMAKE_INSTALL_DATADIR "${INSTALL_PREFIX}/share")
message("${CMAKE_INSTALL_RPATH}")
set(CMAKE_INSTALL_RPATH "$ENV{CMAKE_INSTALL_RPATH}:$ENV{HOME}/.local/lib")
message("${CMAKE_INSTALL_RPATH}")
##########################################################################################
#targets builds

option(BUILD_UI "Build UI components" ON)
option(BUILD_CLI "Build CLI components" ON)
option(BUILD_TESTS "Build TESTS components" ON)

##########################################################################################
#programs for testing
find_program(GCOV gcov)
find_program(LCOV lcov)
find_program(GENHTML genhtml)

##########################################################################################

find_package(Doxygen REQUIRED)
find_package(Git REQUIRED)
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
find_package(GTest REQUIRED)

#########################################################################################
#required libs

add_subdirectory(models/SnakeCore)
add_subdirectory(models/TetrisCore)
add_subdirectory(models/UnionModule)
add_subdirectory(view/Desktop)

set(TestLibs UnionModule TetrisModule SnakeModule ${GTEST_LIBRARIES} gtest_main)
set(DesktopLibs DesktopModule TetrisModule SnakeModule Qt::Core Qt::Gui Qt::Widgets)
set(CLI_LIBS SnakeModule UnionModule -lncurses)

#########################################################################################

set(Tests
        models/SnakeCore/test/tests.cpp
        models/TetrisCore/test/tests.cpp
        models/UnionModule/test/tests.cpp)
set(Desktop view/Desktop/BrickGameDesktop.cpp)
set(CLI view/CLI/snakeCLI.cpp view/CLI/frontend.cpp)

#########################################################################################

set(BUILD_TYPE "Debug" CACHE STRING "" FORCE)
if(NOT Qt6_FOUND)
    message(FATAL_ERROR "Qt6 not found! Please install Qt6 or specify its path.")
else()
    message(STATUS "Qt6 Founded.")
endif()
if (GCOV OR LCOV OR GENHTML)
    message("Testing tool founded.")
endif ()

if(BUILD_TESTS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror -Wextra -fPIC")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Werror -Wextra ")
endif()

if(DOXYGEN_FOUND)
    add_custom_target(dvi
            COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
            DEPENDS ${CMAKE_SOURCE_DIR}/Doxyfile
            COMMENT "Generating DVI documentation..."
    )
endif()
if (APPLE)
    set(OPEN open)
endif ()
if (LINUX)
    set(OPEN xdg-open)
endif ()


#########################################################################################
#########################################################################################
set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_LIBDIR})
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(LD_LIBRARY_PATH "$ENV{LD_LIBRARY_PATH}:$ENV{HOME}/.local/lib")




# Установка библиотек
install(TARGETS UnionModule TetrisModule SnakeModule DesktopModule
        EXPORT BrickGameTargets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Установка заголовочных файлов
install(DIRECTORY models/SnakeCore/inc/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/BrickGame/SnakeCore
        FILES_MATCHING PATTERN "*.h"
)
install(DIRECTORY models/TetrisCore/inc/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/BrickGame/TetrisCore
        FILES_MATCHING PATTERN "*.h"
)
install(DIRECTORY models/UnionModule/inc/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/BrickGame/UnionModule
        FILES_MATCHING PATTERN "*.h"
)
install(DIRECTORY view/Desktop/inc/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/BrickGame/Desktop
        FILES_MATCHING PATTERN "*.h"
)

# Установка исполняемых файлов
if(BUILD_UI)
    add_executable(QBrickGame ${Desktop})
    target_link_libraries(QBrickGame ${DesktopLibs})
    install(TARGETS QBrickGame DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()
if (BUILD_CLI)
    add_executable(SnakeCLI ${CLI})
    target_link_libraries(SnakeCLI ${CLI_LIBS})
    install(TARGETS SnakeCLI DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()

#########################################################################################
#########################################################################################

add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -E remove_directory "${INSTALL_PREFIX}/bin"
        COMMAND ${CMAKE_COMMAND} -E remove_directory "${INSTALL_PREFIX}/lib"
        COMMAND ${CMAKE_COMMAND} -E remove_directory "${INSTALL_PREFIX}/include/${PROJECT_NAME}"
        COMMAND ${CMAKE_COMMAND} -E remove_directory "${INSTALL_PREFIX}/share/${PROJECT_NAME}"
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        COMMENT "Удаление проекта..."
)


add_custom_target(dist
        COMMAND tar czf ${PROJECT_NAME}-${VERSION}.tar.gz
#            --transform='s|^|${PROJECT_NAME}-${VERSION}/|' \
#            --exclude-vcs \
#            --exclude=${PROJECT_NAME}-${VERSION}.tar.gz \
#            .
#        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
#        COMMENT "Creating distribution archive..."
)

# Set default build type to Release
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()


# Создание цели для сборки тестов

#########################################################################################

add_custom_target(test DEPENDS TestModels)
add_custom_target(app DEPENDS QBrickGame)
add_custom_target(cli DEPENDS SnakeCLI)

if (BUILD_TESTS)
    add_executable(TestModels ${Tests})
    target_link_libraries(TestModels ${TestLibs})

endif ()
# Создание цели для генерации отчетов
add_custom_target(gcov_report
    ./TestModels
    COMMAND lcov --capture --directory . --output-file coverage.info --ignore-errors inconsistent
    COMMAND genhtml -o report coverage.info
    COMMAND ${OPEN} report/index.html
    DEPENDS test
)

#########################################################################################