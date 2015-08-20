#ifndef MOTOR_CONTROLLER
#define MOTOR_CONTROLLER

#include <cstring>

#include <boost/shared_ptr.hpp>
#include <boost/thread/thread.hpp>

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
        param[in] p_header the object which owns the pins
    */
    MotorController(boost::shared_ptr<WriteHeader> p_header, std::string& p_leftPin, std::string& p_rightPin);

    //! empty destructor
    ~MotorController();

    /*
        Spawn a thread calling a corrisponding function for direction 
        param[in] the direction to move
    */
    void controller(const std::string& p_direction);

    //! Stop both motor and join the movement thread.
    void stop();

    void joinThread()
    {
        m_movementThread.join();
    }

private: 
    //! Move foward until stop is set, drive both motors forward.
    void moveForward();

    //! Move the robot left
    void moveLeft();

    //! Move the robot right
    void moveRight();

    //! Move the robot backward
    void moveBackward();

private:
    //! controls the left motor.
    bool m_leftMotorState;

    //! controls the right motor.
    bool m_rightMotorState;    

    //! Header for managing gpio pins.
    boost::shared_ptr<WriteHeader> m_header;

    //! the left motor gpio pin.
    std::string& m_leftPin;

    //! the right motor gpio pin.
    std::string& m_rightPin;

    //! A boost thread for running our motor
    boost::thread m_movementThread;
};

#endif
