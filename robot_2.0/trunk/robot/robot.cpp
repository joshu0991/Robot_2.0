#include "robot.hpp"
#include "components/motorcontroller/motorcontroller.hpp"
int main()
{
    std::string pins[] = {"18", "19"};
    MotorController motors(pins);    
    return 0;    
}
