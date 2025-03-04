cmake_minimum_required(VERSION 3.16)

project(THE_BLEB_GAME VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH /mnt/c/libraries/Qt/6.8.2/gcc_64)
set(Qt6_DIR /mnt/c/libraries/Qt/6.8.2/gcc_64/lib/cmake/Qt6)

# set(CMAKE_PREFIX_PATH /usr/local/lib/qt/6.8.0/gcc_64)
# set(Qt6_DIR /usr/local/lib/qt/6.8.0/gcc_64/lib/cmake/Qt6)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Charts)
list(APPEND QT_MODULES Core Quick Gui Widgets Charts)
set(QT_PREFIXED_MODULES ${QT_MODULES})
list(TRANSFORM QT_PREFIXED_MODULES PREPEND "Qt6::")

find_package(Qt6 COMPONENTS ${QT_MODULES} REQUIRED)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(${PROJECT_NAME} main.cc model/Choice.cc model/Choice.h model/DialogTree.cc model/DialogTree.h)
