cmake_minimum_required(VERSION 3.2)

project(robot)

set(Boost_INCLUDE_DIR /home/pi/boost_1_58_0)
set(Boost_LIBRARY_DIR /home/pi/boost_1_58_0/stage/lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

include_directories( ${Boost_INCLUDE_DIR} )
link_directories( ${Boost_LIBRARY_DIR} )

set(CMAKE_CXX_FLAGS "-g -Wall")

add_subdirectory(gpioaccess)
add_subdirectory(robot)
