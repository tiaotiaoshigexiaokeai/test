cmake_minimum_required(VERSION 3.5)

project(pkgverify)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
ENABLE_TESTING()

set( file_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
add_executable(${PROJECT_NAME} ${file_SOURCE})

target_link_libraries(
    ${PROJECT_NAME}
    Qt5::Core
    Qt5::Gui
    )

install(TARGETS pkgverify DESTINATION ./src)
