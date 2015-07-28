#include "motorcontroller.hpp"

MotorController::MotorController(std::string p_gpioPins[2]) :
    m_leftMotorState(false),
    m_rightMotorState(false),
    m_header(p_gpioPins),
    m_gpioPins()
{
    memcpy(m_gpioPins, p_gpioPins, 2 * sizeof(p_gpioPins));
    std::cout << "array values " << m_gpioPins[0] << " " << m_gpioPins[1] << std::endl;
}

void MotorController::moveForward()
{
    // Write the pins to high
    while(m_leftMotorState == false && m_rightMotorState == false)
    {
        m_header.doWrite(m_gpioPins[0], "1");
        m_header.doWrite(m_gpioPins[1], "1");
    }
    // write the pins to low we are done moving forward.
    m_header.doWrite(m_gpioPins[0], "0");
    m_header.doWrite(m_gpioPins[1], "0");

    // reset motors for running
    m_leftMotorState = false;
    m_rightMotorState = false;
}

void MotorController::stop()
{
    m_leftMotorState = true;
    m_rightMotorState = true;
}
