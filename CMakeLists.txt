cmake_minimum_required(VERSION 3.1.0)
project(NxpCarInterface)
add_definitions(-DQT_BUILD=1)
# Find includes in corresponding build directories
set(SOURCE
    NxpCarInterface/main.cpp
    NxpCarInterface/NxpCarInterface.cpp
    NxpCarInterface/NxpCarInterface.h
    NxpCarInterface/NxpDefines.h
    NxpCarInterface/NxpImage.cpp
    NxpCarInterface/NxpImage.h
    NxpCarInterface/Region.h
    NxpCarInterface/s_data.h
    NxpCarInterface/UDPClient.cpp
    NxpCarInterface/UDPClient.h)

set(EXT_SRC
    ../src/pch.h
    ../src/pch.cpp
    )

set(NXP_INCLUDES
    ../src
    #../tfc-k6x
    )

set(NXP_FILES
    ../src/pch.h
    ../src/pch.cpp
    )

include_directories(${OpenCV_INCLUDE_DIRS} ${NXP_INCLUDES})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find the QtWidgets library
set(CMAKE_PREFIX_PATH "C:/Qt/5.13.1/mingw73_64")
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui Network)


# Where to find CMake modules and OpenCV
set(OpenCV_DIR "C:/opencv-4.1.1/mingw-build/install_release")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
include(MacroOpenCV)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(NxpCarInterface ${SOURCE} ${NXP_FILES} NxpCarInterface/NxpCarInterface.qrc NxpCarInterface/NxpCarInterface.ico)

# Use the Widgets module from Qt 5
target_link_libraries(NxpCarInterface ${OpenCV_LIBS} Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Network)