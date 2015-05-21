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

bool GPIOPin::exportPin()
{
	std::string pathToExport = "/sys/class/gpio/export";
    ofstream stream(pathToExport.c_str());
    if(stream = -1)
    {
		std::cout << "Failed to export pin" << std::endl;
		return false;
	}
    stream << m_gpioPin;
    stream.close();
    return true;
}
