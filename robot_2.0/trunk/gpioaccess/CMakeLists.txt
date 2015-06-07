add_subdirectory(pinmanager)
add_subdirectory(writeheader)

include_directories(${ROBOT_SOURCE_DIRECTORY}/gpioaccess/pinmanager)

add_library(gpiopin ${CMAKE_CURRENT_SOURCE_DIR}/gpiopin.hpp ${CMAKE_CURRENT_SOURCE_DIR}/gpiopin.cpp)

