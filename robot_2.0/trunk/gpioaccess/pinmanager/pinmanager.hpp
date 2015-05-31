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
class PinManager
{
protected:
    //! Default constructor
    PinManager();

    //! Add a pin to the set.
    bool addPin(const std::string&, const std::string& p_mode);
    
    //! Remove a pin from the set.
    bool removePin(const std::string& p_pinNumber);
    
    //! check if a pin is in use.
    bool checkForPin(const std::string&	p_pinNumber);
    
    //! Get a refernce to the pin for reading or writing.
    boost::shared_ptr<GPIOPin> getPin(const std::string& p_pinNumber);
    
    virtual ~PinManager();
    
private:
    //! insert a pin.
    bool insertPin(const std::string& p_pinNumber, const std::string& p_mode);

private:
    //! Only want one of these so we can determine which pins are in use and check for conflicts.
    static boost::unordered_map<std::string, boost::shared_ptr<GPIOPin> > m_pinsInUse;
};
#endif
