#include "robot.hpp"
#include "components/motorcontroller/motorcontroller.hpp"
#include "components/sonar/sonar.hpp"
#include "gpioaccess/readheader/readheader.hpp"
#include "gpioaccess/writeheader/writeheader.hpp"
#include <boost/shared_ptr.hpp>

#include <vector>

int main()
{

//////////////////////////Sonar test code
    std::vector<std::string> readPins;
    readPins.push_back("27"); //receive pin

    std::vector<std::string> writePins;
    writePins.push_back("17"); // trigger pin

    boost::shared_ptr<gpioaccess::ReadHeader> readHeader(new gpioaccess::ReadHeader(readPins));
    boost::shared_ptr<gpioaccess::WriteHeader> writeHeader(new gpioaccess::WriteHeader(writePins));
    Sonar sonar(writeHeader, readHeader, writePins[0], readPins[0]);
    boost::uint64_t dis = sonar.ping();

    std::cout << "Distance is " << dis << std::endl;



///////////////////////////////////Push button test code

//    std::vector<std::string> readPins;
//    readPins.push_back("19");
//    boost::shared_ptr<gpioaccess::ReadHeader> readHeader(new gpioaccess::ReadHeader(readPins));
//    while (true)
//    {
//        boost::uint64_t var = readHeader->doRead(readPins[0]);
//        std::cout << "PIN VALUE IS " << var << std::endl;
//    }




////////////////////////////////Motor controller code.

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

