#include "motorcontroller.hpp"

MotorController::MotorController(boost::shared_ptr<WriteHeader> p_header, std::string& p_leftPin, std::string& p_rightPin) :
    m_leftMotorState(false),
    m_rightMotorState(false),
    m_header(p_header),
    m_leftPin(p_leftPin),
    m_rightPin(p_rightPin),
    m_movementThread()
{
}

MotorController::~MotorController()
{
}

void MotorController::controller(const std::string& p_direction, /*boost::shared_ptr<*/MotorController p_instanceObj)
{
    if (p_direction == "forward")
    {
        m_movementThread = boost::thread(&MotorController::moveForward, &p_instanceObj);
    }
}

void MotorController::moveForward()
{
    // Write the pins to high
    while(m_leftMotorState == false && m_rightMotorState == false)
    {
        std::cout << "Running motors" << std::endl;
        m_header->doWrite(m_leftPin, "1");
        m_header->doWrite(m_rightPin, "1");
    }
    // write the pins to low we are done moving forward.
    m_header->doWrite(m_leftPin, "0");
    m_header->doWrite(m_rightPin, "0");

    // reset motors for running
    m_leftMotorState = false;
    m_rightMotorState = false;
}

void MotorController::stop()
{
    m_leftMotorState = true;
    m_rightMotorState = true;
    std::cout << "Waiting for thread to join" << std::endl;
    m_movementThread.join();
}
