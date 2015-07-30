#include "robot.hpp"
#include "components/motorcontroller/motorcontroller.hpp"

#include <boost/shared_ptr.hpp>

#include <vector>

int main()
{
    // All of the pins used in the program
    std::vector<std::string> pins;
    pins.push_back("18");
    pins.push_back("19");
    boost::shared_ptr<WriteHeader> header(new WriteHeader(pins));
    
    //Instantiate with all of the pins and the two we should access for motor control
    MotorController motors(header, pins[0], pins[1]);
//    motors.moveForward();
//    motors.stop(); 
    return 0;    
}

