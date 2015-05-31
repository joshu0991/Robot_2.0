#include "gpiopin.hpp"
#include <string>
//! Direction can be "in" or "out"
GPIOPin::GPIOPin(const std::string& p_pinNum, const std::string& p_direction) : 
    m_gpioPin(p_pinNum),
    m_mode(p_direction)

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
    const std::string pathToExport = "/sys/class/gpio/export";
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
    const std::string pathToUnexport = "/sys/class/gpio/unexport";
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
void GPIOPin::setUpPinDirection(const std::string& dir)
{
	const std::string location = "/sys/class/gpio/gpio/" + m_gpioPin + "/direction";
	std::ofstream stream (location.c_str());
	stream << dir;
	stream.close();
}

void GPIOPin::write(const std::string& p_state)
{
	std::string path = "/sys/class/gpio/gpio" + m_gpioPin;
	if(m_mode == "out")
	{
		std::ofstream stream (path.c_str());
		if(stream < 0)
		{
		    std::cout << "Failed to write" << std::endl;
		}
		else
		{
     		stream << p_state;
     		stream.close();
		}
	}
}

void GPIOPin::read(std::string& p_return)
{
    std::string path = "/sys/class/gpio/gpio" + m_gpioPin;
	if(m_mode == "in")
	{
		std::ifstream stream (path.c_str());
		if(stream < 0)
		{
			std::cout << "Failed to read" << std::endl;
		}
		else
		{
     		stream >> p_return;
     		stream.close();
     		if(p_return != "0")
     		{
				 p_return = "1";
			}
			else
			{
				p_return = "0";
			}
		}
	}
			
}
