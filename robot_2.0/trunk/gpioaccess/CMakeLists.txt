#add_subdirectory(pinmanager)
#add_subdirectory(writeheader)

#include_directories(${ROBOT_SOURCE_DIRECTORY}/gpioaccess/pinmanager)

add_library(gpioaccess ${CMAKE_CURRENT_SOURCE_DIR}/gpiopin.hpp ${CMAKE_CURRENT_SOURCE_DIR}/gpiopin.cpp ${CMAKE_CURRENT_SOURCE_DIR}/pinmanager/pinmanager.hpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/pinmanager/pinmanager.cpp ${CMAKE_CURRENT_SOURCE_DIR}/writeheader/writeheader.hpp ${CMAKE_CURRENT_SOURCE_DIR}/writeheader/writeheader.cpp)

