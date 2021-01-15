cmake_minimum_required(VERSION 3.11)

project(read)

set(CMAKE_CXX_STANDARD 17)

# CONAN
include(${PROJECT_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${CMAKE_INCLUDE_PATH})
include_directories(${PROJECT_SOURCE_DIR}/client/graphical/widget/include)
include_directories(${PROJECT_SOURCE_DIR}/client/graphical/scenes/include)
include_directories(${PROJECT_SOURCE_DIR}/client/parser/read/include)
include_directories(${PROJECT_SOURCE_DIR}/client/parser/write/include)

add_library(read SHARED
    ${PROJECT_SOURCE_DIR}/client/parser/write/src/Write.cpp
    ${PROJECT_SOURCE_DIR}/client/parser/read/src/infoFile.cpp
    ${PROJECT_SOURCE_DIR}/client/parser/read/src/read.cpp
    ${PROJECT_SOURCE_DIR}/client/parser/read/src/ActiveIdeaGroup.cpp
    ${PROJECT_SOURCE_DIR}/client/parser/read/src/Colors.cpp
    ${PROJECT_SOURCE_DIR}/client/parser/read/src/Country.cpp
    ${PROJECT_SOURCE_DIR}/client/parser/read/src/Estates.cpp
    ${PROJECT_SOURCE_DIR}/client/parser/read/src/Government.cpp
    ${PROJECT_SOURCE_DIR}/client/parser/read/src/StateViews.cpp
    ${PROJECT_SOURCE_DIR}/client/parser/read/src/Technology.cpp
    ${PROJECT_SOURCE_DIR}/client/parser/read/src/Province.cpp
)
target_link_libraries(${CMAKE_PROJECT_NAME} ${CONAN_LIBS} Qt5::Widgets)