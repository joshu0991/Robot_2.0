
#include "gpioaccess/gpiopin.hpp"

#include <boost/intrusive_ptr.hpp>
#include <boost/unordered_set.hpp>

/*!
 * \brief class for managing all of the pins in use in the robot applocation is also responsable for cleanup.
 *     All hardware that access GPIO pins should inherit from this class. and add their pins that are intended 
 *     for use to the pinsInUse set. Each module may read and write to multiple pins so we will force all modules 
 *     to implement both functions.
 */
class PinManager : public GPIOPin
{
public:
    //! Add a pin to the set.
    bool addPin(boost::uint8_t p_pinNumber);
    
    //! Remove a pin from the set.
    bool removePin(boost::uint8_t p_pinNumber);
    
    //! check if a pin is in use.
    bool checkForPin(boost::uint8_t	p_pinNumber);
    
    //! Get a refernce to the pin for reading or writing.
    
private:
    //! Only want one of these so we can determine which pins are in use and check for conflicts.
    static boost::unordered_set<boost::intrusive_ptr<GPIOPin> > pinsInUse;
};
