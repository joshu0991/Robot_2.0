cmake_minimum_required(VERSION 3.2)
set( CMAKE_VERBOSE_MAKEFILE on i)
project(robot)

#set(Boost_INCLUDE_DIR /home/pi/boost_1_58_0)
#set(Boost_LIBRARY_DIR /home/pi/boost_1_58_0/stage/lib)

find_package(Boost 1.49.0 COMPONENTS thread REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gpioaccess)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${Boost_INCLUDE_DIR} )

link_directories( ${Boost_LIBRARY_DIR} )

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++0x -L/usr/lib/libboost_thread.so -L/usr/lib/libboost_chrono.so -L/usr/lib/libboost_system.so -lboost_system -lboost_chrono -lboost_thread" )

add_subdirectory(gpioaccess)
add_subdirectory(components)
#add_subdirectory(threading)
add_subdirectory(robot)
