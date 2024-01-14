cmake_minimum_required(VERSION 3.20)

project(Shooter
    DESCRIPTION "Shooter Game"
    VERSION     1.0.0
    LANGUAGES   CXX C
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Cm REQUIRED)

find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia)

find_package(SDL2 REQUIRED)

find_package(GameIO REQUIRED)

add_subdirectory(src)
