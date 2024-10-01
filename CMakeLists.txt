cmake_minimum_required(VERSION 3.22)
project(BrickGame)

include(GNUInstallDirs)
#include(CPack)

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
set(CMAKE_INSTALL_RPATH "$ENV{CMAKE_INSTALL_RPATH}:$ENV{HOME}/.local/lib")

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

if (APPLE)
    set(OPEN open)
endif ()
if (LINUX)
    set(OPEN xdg-open)
endif ()


#########################################################################################

if(DOXYGEN_FOUND)
    add_custom_target(dvi
            COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
            DEPENDS ${CMAKE_SOURCE_DIR}/Doxyfile
            COMMAND ${OPEN} doxygen/html/index.html
            COMMENT "Generating DVI documentation..."
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    )
endif()

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



if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()


# Создание цели для сборки тестов

#########################################################################################

add_custom_target(tests DEPENDS TestModels)
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
    DEPENDS tests
)

#########################################################################################

# Подключаем модуль CPack
include(CPack)

# Определяем имя пакета
set(CPACK_PACKAGE_NAME "BrickGame")

# Определяем версию пакета
set(CPKA_PACKAGE_VERSION_MAJOR 1)
set(CPKA_PACKAGE_VERSION_MINOR 0)

# Устанавливаем формат архива
set(CPACK_GENERATOR "TGZ")  # или ZIP для Windows

# Настройки для CPack
set(CPACK_SET_DESTDIR ON)
set(CPACK_OUTPUT_FILE_PREFIX "${CMAKE_BINARY_DIR}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Brick Game package")
#set(CPACK_PACKAGE_VENDOR "Your Company/Organization")

# Создаем директорию для дистрибутива
file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/dist)

# Копируем необходимые файлы в директорию дистрибутива
file(COPY ${PROJECT_SOURCE_DIR}/models DESTINATION ${PROJECT_SOURCE_DIR}/dist)
file(COPY ${PROJECT_SOURCE_DIR}/view DESTINATION ${PROJECT_SOURCE_DIR}/dist)
file(COPY ${PROJECT_SOURCE_DIR}/CMakeLists.txt DESTINATION ${PROJECT_SOURCE_DIR}/dist)
file(COPY ${PROJECT_SOURCE_DIR}/gen_make.sh DESTINATION ${PROJECT_SOURCE_DIR}/dist)
file(COPY ${PROJECT_SOURCE_DIR}/cmake DESTINATION ${PROJECT_SOURCE_DIR}/dist)
file(REMOVE_RECURSE ${PROJECT_SOURCE_DIR}/dist/.git)
file(REMOVE_RECURSE ${PROJECT_SOURCE_DIR}/dist/.idea)

# Создаем файл конфигурации для CPack
configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/cpack_config.cmake.in
        ${CMAKE_BINARY_DIR}/CPackConfig.cmake
        @ONLY
)

# Проверяем наличие файла CPackConfig.cmake
file(WRITE ${CMAKE_BINARY_DIR}/CPackConfig.cmake "")
if(NOT EXISTS ${CMAKE_BINARY_DIR}/CPackConfig.cmake)
    message(FATAL_ERROR "Файл CPackConfig.cmake не был создан.")
endif()

# Добавляем CPack для создания установщика
include(${CMAKE_BINARY_DIR}/CPackConfig.cmake)
message(${PROJECT_SOURCE_DIR})
# Добавляем целевую цель для создания дистрибутива
add_custom_target(dist
        rm -f ${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.tar.gz
        COMMAND  echo ${CMAKE_COMMAND} -E tar czf ${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.tar.gz ${PROJECT_SOURCE_DIR}
        COMMAND ${CMAKE_COMMAND} -E tar czf ${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.tar.gz ${PROJECT_SOURCE_DIR}/dist
        COMMENT "Creating distribution..."
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)

