#ifndef MOTOR_CONTROLLER
#define MOTOR_CONTROLLER

#include "gpioaccess/gpiopin.hpp"
#include "gpioaccess/pinmanager/pinmanager.hpp"
#include "gpioaccess/writeheader/writeheader.hpp"

/*! \brief a class to manage two motors */
class MotorController
{
public:
    /*! 
        Instantiate a motor controller
        param[in] gpio pin for left motor
        param[in] gpio pin for right motor
    */
    MotorController(std::string p_gpioPins[2]);
 
    //! Move foward until stop is set, drive both motors forward.
    void moveForward();

    //! Stop both motors
    void stop();
private:
    //! controls the left motor.
    bool m_leftMotorState;

    //! controls the right motor.
    bool m_rightMotorState;    

    //! Header for managing gpio pins.
    WriteHeader m_header;

    //! the array containing the gpio pins.
    std::string m_gpioPins[2];
};

#endif
