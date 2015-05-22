#include "GPIOPin.hpp"

#include <boost/lexical_cast.hpp>

GPIOPin::GPIOPin(boost::uint8_t p_pinNum, std::string p_direction) : 
    m_gpioPin(p_pinNum)

{
	bool exported = exportPin();
	if(!exported)
	{
		std::cerr << "Could not set the pin" << std::endl;
	}
	else
	{
		setUpPinDirection(p_direction);
	}
    std::cout << m_gpioPin << std::endl;
}

//! **Virtual** Need to unexport the pins that are in use. 
GPIOPin::~GPIOPin()
{
	unexportPin();
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

//! Set up an input pin
void GPIOPin::setUpPinDirection(std::string dir)
{
	std::string location = "/sys/class/gpio/gpio" + boost::lexical_cast<std::string>(m_gpioPin) + "direction";
	std::ofstream stream (location.c_str());
	stream << dir;
	stream.close();
}
