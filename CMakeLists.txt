cmake_minimum_required(VERSION 3.11)

set(CMAKE_PROJECT_NAME teuton)

project(${CMAKE_PROJECT_NAME})

include(${PROJECT_SOURCE_DIR}/client/CMakeLists.txt)
include(${PROJECT_SOURCE_DIR}/client/graphical/CMakeLists.txt)
include(${PROJECT_SOURCE_DIR}/client/parser/read/CMakeLists.txt)
include(${PROJECT_SOURCE_DIR}/client/parser/write/CMakeLists.txt)