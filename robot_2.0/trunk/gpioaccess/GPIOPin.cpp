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

//! Export a gpio pin to be used.
bool GPIOPin::exportPin()
{
    std::string pathToExport = "/sys/class/gpio/export";
    //has to be a c string to write to file sys.
    std::ofstream stream(pathToExport.c_str());
    if(stream < 0)
    {
        std::cout << "Failed to export pin" << std::endl;
        return false;
    }
    stream << m_gpioPin;
    stream.close();
    return true;
}

//! Unexport a gpio pin.
bool GPIOPin::unexportPin()
{
    std::string pathToUnexport = "/sys/class/gpio/unexport";
    //has to be a c string to write to file sys.
    std::ofstream stream(pathToUnexport.c_str());
        if(stream < 0)
    {
        std::cout << "Failed to unexport pin" << std::endl;
        return false;
    }
    stream << m_gpioPin;
    stream.close();
    return true;
}
