#include "GPIOPin.hpp"

GPIOPin::GPIOPin(boost::uint8_t p_pinNum) : 
    m_gpioPin(p_pinNum)

{
    std::cout << m_gpioPin << std::endl;
}

//! **Virtual** Need to unexport the pins that are in use. 
GPIOPin::~GPIOPin()
{
	
}	
