cmake_minimum_required(VERSION 3.2)

project(robot)

find_package(Boost 1.58.0)

set(CMAKE_CXX_FLAGS "-g -Wall")

add_subdirectory(gpioaccess)
add_subdirectory(robot)
