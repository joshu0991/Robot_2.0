include_directories(${ROBOT_SOURCE_DIRECTORY})

add_library(writeheader ${CMAKE_CURRENT_SOURCE_DIR}/writeheader.hpp ${CMAKE_CURRENT_SOURCE_DIR}/writeheader.cpp)

target_link_libraries(pinmanager)
