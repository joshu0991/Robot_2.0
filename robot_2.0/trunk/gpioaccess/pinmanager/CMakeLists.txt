include_directories(${ROBOT_SOURCE_DIRECTORY})

add_library(PinManager ${ROBOT_SOURCE_DIR}gpioaccess/gpiopin.hpp ${CMAKE_CURRENT_SOURCE_DIR}/pinmanager.hpp ${CMAKE_CURRENT_SOURCE_DIR}/pinmanager.cpp)
