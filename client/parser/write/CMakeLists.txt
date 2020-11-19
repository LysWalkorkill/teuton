cmake_minimum_required(VERSION 3.11)

project(write)

set(CMAKE_CXX_STANDARD 17)

# CONAN
include(${PROJECT_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

# QT COMPONENTS
find_package(Qt5 REQUIRED COMPONENTS Core Network Widgets)

    # QT INCLUDES
include_directories(${Qt5Network_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})

include_directories(${CMAKE_INCLUDE_PATH})
include_directories(${PROJECT_SOURCE_DIR}/client/graphical/widget/include)
include_directories(${PROJECT_SOURCE_DIR}/client/graphical/scenes/include)
include_directories(${PROJECT_SOURCE_DIR}/client/parser/read/include)
include_directories(${PROJECT_SOURCE_DIR}/client/parser/write/include)

add_library(write SHARED
    ${PROJECT_SOURCE_DIR}/client/parser/write/src/write.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME} ${CONAN_LIBS} Qt5::Widgets)
