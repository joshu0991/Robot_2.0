#include "gpiopin.hpp"
#include <string>

namespace gpioaccess {

//! Direction can be "in" or "out"
GPIOPin::GPIOPin(const std::string& p_pinNum, const std::string& p_direction) : 
    m_gpioPin(p_pinNum),
    m_mode(p_direction),
    m_scratchString()
{
    bool exported = exportPin();
    std::cout << " exported is " << exported << " direction is " << p_direction << std::endl;
    if(!exported)
    {
        std::cerr << "Could not set the pin" << std::endl;
    }
    else
    {
        setUpPinDirection(p_direction);
    }
}

//! **Virtual** Need to unexport the pins that are in use. 
GPIOPin::~GPIOPin()
{
    std::cout << "GPIO Destructor executing" << std::endl;
    unexportPin();
}	

//! Export a gpio pin to be used.
bool GPIOPin::exportPin()
{
    const std::string pathToExport = "/sys/class/gpio/export";
    // has to be a c string to write to file sys.
    std::ofstream stream(pathToExport.c_str());
    if(stream < 0)
    {
        std::cerr << "Failed to export pin" << std::endl;
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
        std::cerr << "Failed to unexport pin" << std::endl;
        return false;
    }
    stream << m_gpioPin;
    stream.close();
    return true;
}

//! Set up an input pin
void GPIOPin::setUpPinDirection(const std::string& dir)
{
    const std::string location = "/sys/class/gpio/gpio" + m_gpioPin + "/direction";
    std::ofstream stream (location.c_str());    
    if (stream < 0)
    {
        std::cerr << "FAILED TO SET GPIO PIN DIRECTION" << std::endl;
    }
    stream << dir;
    stream.close();
}

void GPIOPin::write(const std::string& p_state)
{
    std::string path = "/sys/class/gpio/gpio" + m_gpioPin + "/value";
    std::cout << "set the path " << std::endl;
    if(m_mode == "out")
    {
        std::cout << "Writing to pin" << std::endl;
        std::ofstream stream (path.c_str());
        std::cout << "Established stream" << std::endl;
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
    else
    {
        std::cout << "The mode was not properly set" << std::endl;
    }
}

boost::uint8_t GPIOPin::read()
{
    std::string path = "/sys/class/gpio/gpio" + m_gpioPin +"/value";
    
    if(m_mode == "in")
    {
        std::ifstream stream (path.c_str());
        if(stream < 0)
        {
            return 2;
        }
        stream >> m_scratchString;
        stream.close();
        if(m_scratchString != "0")
        {
             m_scratchString.clear();
             return 1;
        }
        m_scratchString.clear();
        return 0;
    }
    return 2;			
}

} // gpioaccess
