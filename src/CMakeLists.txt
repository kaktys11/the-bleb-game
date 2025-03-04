cmake_minimum_required(VERSION 3.16)

project(THE_BLEB_GAME VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH /mnt/c/libraries/Qt/6.8.0/gcc_64)
set(Qt6_DIR /mnt/c/libraries/Qt/6.8.0/gcc_64/lib/cmake/Qt6)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(${PROJECT_NAME} main.cc model/Choice.cc model/Choice.h model/DialogTree.cc model/DialogTree.h)