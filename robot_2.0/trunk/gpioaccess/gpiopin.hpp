#ifndef GPIOPIN_HPP
#define GPIOPIN_HPP

#include <fstream>
#include <iostream>
#include <string>

#include <boost/cstdint.hpp>

/*!
 * \brief Class to manager an individual pin.
 */
class GPIOPin
{
public:
    /*!
     * \param[in] p_pinNum the pin to manager.
     * \param[in] p_direction input or output pin can be in or out.
     */
    GPIOPin(const std::string& p_pinNum, const std::string& p_direction);

    virtual ~GPIOPin();

    std::string getMode()
    {
		return m_mode;
	}
private:
    //! Functions needed for set up.
    void setUpPinDirection(const std::string& p_direction);
    bool exportPin();
    bool unexportPin();
    
private:
    //! The pin this class will be managing.
    const std::string& m_gpioPin;
    
    //! Wheather this pin is set up to read or write.
    const std::string& m_mode;
};

#endif // GPIOPIN_HPP
