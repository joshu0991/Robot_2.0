#include "robot.hpp"
#include "components/motorcontroller/motorcontroller.hpp"

#include <boost/shared_ptr.hpp>

#include <vector>

int main()
{
    // All of the pins used in the program
    std::vector<std::string> pins;
    pins.push_back("18"); // Forward engine 1 (left)
    pins.push_back("23"); // Forward engine 2 (right)
    pins.push_back("24"); // Reverse engine 1 (left)
    pins.push_back("25"); // Reverse engine 2 (right)

    boost::shared_ptr<WriteHeader> header(new WriteHeader(pins));
    
    std::cin.ignore();
    // Instantiate with all of the pins and the two we should access for motor control
    MotorController motors(header, pins[0], pins[1], pins[2], pins[3]);
    motors.controller("forward");
    std::cin.ignore();
//    motors.joinThread();
//    motors.moveForward();
    motors.stop(); 
    return 0;    
}

