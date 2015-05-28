
include_directories(${ROBOT_SOURCE_DIR}/robot ${ROBOT_SOURCE_DIR}/gpioaccess ${ROBOT_SOURCE_DIR}/gpioaccess/pinmanager)
add_executable(robot ${CMAKE_CURRENT_SOURCE_DIR}/robot.cpp ${CMAKE_CURRENT_SOURCE_DIR}/robot.hpp )
target_link_libraries(robot gpiopin)
