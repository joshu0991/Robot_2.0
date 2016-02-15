#include "readheader.hpp"

namespace gpioaccess {

ReadHeader::ReadHeader(std::vector<std::string> p_pinList)
{
    initilize(p_pinList);
}

bool ReadHeader::initilize(std::vector<std::string> p_pinList)
{
    bool success = true;
    for(boost::uint8_t i = 0; i < p_pinList.size(); ++i)
    {
        // Ensure we haven't initilized the pin
        if (!checkForPin(p_pinList[i]))
        {
            std::cout << "adding pin" << std::endl;
            success = addPin(p_pinList[i], "in");
        }
    }
    return success;
}

boost::uint8_t ReadHeader::doRead(const std::string& p_pinNumber)
{
    boost::shared_ptr<GPIOPin> pin = getPin(p_pinNumber);
    if (pin)
    {
        std::cout << "Successfully reading: Pin value is " << pin << std::endl;
        return pin->read();
    }
    return 2;
}

} //gpioaccess
