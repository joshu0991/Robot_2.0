add_library(components ${CMAKE_CURRENT_SOURCE_DIR}/motorcontroller/motorcontroller.cpp 
                       ${CMAKE_CURRENT_SOURCE_DIR}/motorcontroller/motorcontroller.hpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/sonar/sonar.hpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/sonar/sonar.cpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/thermometer/thermometer.hpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/thermometer/thermometer.cpp)
