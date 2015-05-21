#ifndef GPIOPIN_HPP
#define GPIOPIN_HPP

#include <fstream>
#include <iostream>
#include <string>

#include <boost/cstdint.hpp>

/*!
 * \brief Class to manager an individual pin.
 * \param[in] p_pinNum the pin this class will model.
 */
class GPIOPin
{
public:
    GPIOPin(boost::uint8_t p_pinNum);

    virtual ~GPIOPin(); 

private:
    //! Functions needed for set up.
    bool setUpForInput();
    bool setUpForOutput();
    bool exportPin();
    bool unexportPin();
    
private:
    boost::uint8_t m_gpioPin;
};

#endif // GPIOPIN_HPP
