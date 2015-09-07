#ifndef READHEADER_HPP
#define READHEADER_HPP


#include <vector>

#include "gpioaccess/pinmanager/pinmanager.hpp"
#include "gpioaccess/gpiopin.hpp"

/*!
    \brief class that is responsible for specifing how reading should
      be done from a standard gpio pin. This class is similar to write
      header in the way it manages and sets up pins for reading
*/

namespace gpioaccess {

class ReadHeader : PinManager
{
public:
    //! initializes a vector of pins.
    ReadHeader(std::vector<std::string> p_pinList);

    //! Calls the read function for the given gpio pin
    boost::uint8_t doRead(const std::string& p_pinNumber);

private:
    //! Handles setting up all given pins
    bool initilize(std::vector<std::string> p_pinList);
};

} // gpioaccess

#endif
