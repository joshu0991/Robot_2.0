#ifndef PINMANAGER_HPP
#define PINMANAGER_HPP

#include "gpioaccess/gpiopin.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>


/*!
 * \brief class for managing all of the pins in use in the robot applocation is also responsable for cleanup.
 *     All hardware that access GPIO pins should inherit from this class. and add their pins that are intended 
 *     for use to the pinsInUse set. Each module may read and write to multiple pins so we will force all modules 
 *     to implement both functions.
 */
class PinManager : public GPIOPin
{
protected:
    //! Add a pin to the set.
    bool addPin(std::string, const std::string p_mode);
    
    //! Remove a pin from the set.
    bool removePin(boost::uint8_t p_pinNumber);
    
    //! check if a pin is in use.
    bool checkForPin(boost::uint8_t	p_pinNumber);
    
    //! Get a refernce to the pin for reading or writing.
    boost::shared_ptr<GPIOPin> getPin(boost::uint8_t p_pinNumber);
    
    virtual ~PinManager();
    
private:
    //! insert a pin.
    bool insertPin(std::string, const std::string p_mode);

private:
    //! Only want one of these so we can determine which pins are in use and check for conflicts.
    static boost::unordered_map<std::string, boost::shared_ptr<GPIOPin> > m_pinsInUse;
};
#endif
