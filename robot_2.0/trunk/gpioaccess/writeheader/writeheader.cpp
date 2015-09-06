#include "writeheader.hpp"

namespace gpioaccess {

WriteHeader::WriteHeader(std::vector<std::string> p_pinList)
{
    if (!(initilize(p_pinList)))
    {
        std::cout << "Failed to init pin" << std::endl;
    }
}

WriteHeader::~WriteHeader()
{
}

bool WriteHeader::initilize(std::vector<std::string> p_pinList)
{
    bool success = true;
    std::cout << "size of the init array to be smaller than " << p_pinList.size() <<" Zero element " << p_pinList[0] << " element one " << p_pinList[1]  << std::endl;
    for(boost::uint8_t i = 0; i < p_pinList.size(); ++i)
    {
        if(!checkForPin(p_pinList[i]))
        {
            std::cout << "adding pin" << std::endl;
            success = addPin(p_pinList[i], "out");
        }
    }
    return success;
}

void WriteHeader::doWrite(const std::string& p_pinNumber, const std::string& p_state)
{
    boost::shared_ptr<GPIOPin> pin = getPin(p_pinNumber);
    if (pin)
    {
        std::cout << "successfully writing: pin value is  " << pin <<  std::endl;
        pin->write(p_state);
        std::cout << "Write was successful." << std::endl;
    }
}

} // gpioaccess
