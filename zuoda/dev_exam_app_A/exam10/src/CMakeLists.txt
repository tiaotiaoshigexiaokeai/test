cmake_minimum_required(VERSION 3.5)

project(freedesktop)

set(BIN_NAME freedesktop)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
ENABLE_TESTING()

set( mainwindow_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
add_executable(${PROJECT_NAME} ${mainwindow_SOURCE})
add_test(${PROJECT_NAME} COMMAND ${PROJECT_NAME})
target_link_libraries(
    ${PROJECT_NAME}
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
)
