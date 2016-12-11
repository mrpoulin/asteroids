# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.3)
project( Asteroids )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Weverything -Wreserved-id-macro")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)
find_package(Doxygen)
add_executable(asteroids "game.cc")

include_directories(${SDL2_INCLUDE_DIR} ${SDL2IMAGE_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(asteroids ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARIES})

include( components/CMakeLists.txt )
include( messages/CMakeLists.txt )
include( graphics/CMakeLists.txt )
include( input/CMakeLists.txt )
include( systems/CMakeLists.txt )
include( entity/CMakeLists.txt )
include( engine/CMakeLists.txt )
