cmake_minimum_required(VERSION 3.11)

set(CMAKE_PROJECT_NAME teuton_client)

project(${CMAKE_PROJECT_NAME})

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
include_directories(${CONAN_INCLUDE_DIRS})

link_directories(${CMAKE_SOURCE_DIR}/build)
link_directories(${CMAKE_SOURCE_DIR}/build/bin)
link_directories(${CMAKE_SOURCE_DIR}/build/lib)

file(GLOB_RECURSE SOURCES_CPP ${PROJECT_SOURCE_DIR}/client/main.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES_CPP})
target_link_libraries(${CMAKE_PROJECT_NAME} ${CONAN_LIBS} Qt5::Widgets graphical read write)
