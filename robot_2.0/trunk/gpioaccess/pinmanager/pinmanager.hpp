
#include "access/GpioPin.hpp"

#include <boost/unordered_set.hpp>

/*!
 * \brief class for managing all of the pins in use in the robot applocation is also responsable for cleanup.
 *     All hardware that access GPIO pins should inherit from this class. and add their pins that are intended 
 *     for use to the pinsInUse set. Each module may read and write to multiple pins so we will force all modules 
 *     to implement both functions.
 */
class PinManager : GPIOPin
{
protected:
    //! Possible additions of writing to spi and such so make this pure virtual for flexability.
    virtual bool writeToPin() = 0;   
    virtual bool readFromPin() = 0;   
private:
    //! Only want one of these so we can determine which pins are in use and check for conflicts.
    static boost::unordered_set pinsInUse;
};
