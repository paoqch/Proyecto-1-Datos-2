cmake_minimum_required(VERSION 3.5)

project(C_IDE LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5Network REQUIRED)

add_executable(C_IDE
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        logger.h
        logger.cpp
        client.h
        client.cpp
)

target_link_libraries(C_IDE Qt5::Core)
target_link_libraries(C_IDE Qt5::Widgets)
target_link_libraries(C_IDE Qt5::Quick)
target_link_libraries(C_IDE Qt5::Network)
