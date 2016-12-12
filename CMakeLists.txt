# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.3)
project( Asteroids )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-shadow -Wno-missing-braces -Wno-weak-vtables -Wno-padded")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)
find_package(Doxygen)
add_executable(asteroids "game.cc")

include_directories(SYSTEM ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(asteroids ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})

include( components/CMakeLists.txt )
include( messages/CMakeLists.txt )
include( graphics/CMakeLists.txt )
include( input/CMakeLists.txt )
include( systems/CMakeLists.txt )
include( entity/CMakeLists.txt )
include( engine/CMakeLists.txt )
