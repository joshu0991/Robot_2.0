#include "motorcontroller.hpp"

MotorController::MotorController(boost::shared_ptr<WriteHeader> p_header, std::string& p_leftForwardPin, std::string& p_rightForwardPin, std::string& p_leftReversePin, std::string& p_rightReversePin) :
    m_leftMotorState(false),
    m_rightMotorState(false),
    m_header(p_header),
    m_leftForwardPin(p_leftForwardPin),
    m_rightForwardPin(p_rightForwardPin),
    m_leftReversePin(p_leftReversePin),
    m_rightReversePin(p_rightReversePin),
    m_movementThread()
{
}

MotorController::~MotorController()
{
}

void MotorController::controller(const std::string& p_direction)
{
std::cout << "Made it to function" << std::endl;
    if (p_direction == "forward")
    {
        m_movementThread = boost::thread(&MotorController::moveForward, this);
    }
}

void MotorController::moveForward()
{
    // Write the pins to high
    while(m_leftMotorState == false && m_rightMotorState == false)
    {
        std::cout << "Running motors" << std::endl;
        m_header->doWrite(m_leftForwardPin, "1");
        m_header->doWrite(m_rightForwardPin, "1");
    }
    // write the pins to low we are done moving forward.
    m_header->doWrite(m_leftForwardPin, "0");
    m_header->doWrite(m_rightForwardPin, "0");

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

void MotorController::moveBackward()
{
    // Write the pins to high
    while(m_leftMotorState == false && m_rightMotorState == false)
    {
        std::cout << "Running motors" << std::endl;
        m_header->doWrite(m_leftReversePin, "1");
        m_header->doWrite(m_rightReversePin, "1");
    }
    // write the pins to low we are done moving forward.
    m_header->doWrite(m_leftReversePin, "0");
    m_header->doWrite(m_rightReversePin, "0");

    // reset motors for running
    m_leftMotorState = false;
    m_rightMotorState = false;
}
