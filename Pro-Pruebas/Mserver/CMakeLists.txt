cmake_minimum_required(VERSION 3.16.3)

project(Mserver LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)


find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)


add_executable(Mserver
        main.cpp
        mserver.cpp
        mserver.h
        mserver.ui
        logger.cpp
        logger.h
        memory.h
        memory.cpp
        node.cpp
        node.h
        memoryblock.cpp
        memoryblock.h

)


target_link_libraries(Mserver Qt5::Core)
target_link_libraries(Mserver Qt5::Widgets)
target_link_libraries(Mserver Qt5::Network)
