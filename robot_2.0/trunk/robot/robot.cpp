#include "robot.hpp"
#include "components/motorcontroller/motorcontroller.hpp"
#include "gpioaccess/readheader/readheader.hpp"
#include <boost/shared_ptr.hpp>

#include <vector>

int main()
{

    std::vector<std::string> readPins;
    readPins.push_back("21");
    std::string returnValue;
    boost::shared_ptr<ReadHeader> readHeader(new ReadHeader(readPins));
    while (true)
    {
        readHeader->doRead(readPins[0], returnValue);
        std::cout << returnValue << std::endl;
    }

    // All of the write pins used in the program
//    std::vector<std::string> writePins;
//    writePins.push_back("18"); // Forward engine 1 (left)
//    writePins.push_back("23"); // Forward engine 2 (right)
//    writePins.push_back("24"); // Reverse engine 1 (left)
//    writePins.push_back("25"); // Reverse engine 2 (right)

//    boost::shared_ptr<WriteHeader> writeHeader(new WriteHeader(writePins));
    
//    std::cin.ignore();

    // Instantiate with all of the pins and the two we should access for motor control
//    MotorController motors(writeHeader, writePins[0], writePins[1], writePins[2], writePins[3]);
//    motors.controller("forward");
//    std::cin.ignore();
//    motors.controller("back");
//    std::cin.ignore();
//    motors.controller("rleft");
//    std::cin.ignore();
//    motors.controller("rright");
//    std::cin.ignore();
//    motors.stop(); 
    return 0;    
}

