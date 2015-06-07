include_directories(${ROBOT_SOURCE_DIRECTORY} ${ROBOT_SOURCE_DIR}/gpioaccess )

add_library(writeheader ${ROBOT_SOURCE_DIR}gpioaccess/gpiopin.hpp ${CMAKE_CURRENT_SOURCE_DIR}/writeheader.hpp ${CMAKE_CURRENT_SOURCE_DIR}/writeheader.cpp)

#target_link_libraries(gpiopin)
