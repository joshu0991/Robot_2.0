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
    /*!
     * \param[in] p_pinNum the pin to manager.
     * \param[in] p_direction input or output pin can be in or out.
     */
    GPIOPin(boost::uint8_t p_pinNum, std::string p_direction);

    virtual ~GPIOPin(); 

private:
    //! Functions needed for set up.
    void setUpPinDirection(std::string p_direction);
    bool exportPin();
    bool unexportPin();
    
private:
    //! The pin this class will be managing.
    boost::uint8_t m_gpioPin;
};

#endif // GPIOPIN_HPP
