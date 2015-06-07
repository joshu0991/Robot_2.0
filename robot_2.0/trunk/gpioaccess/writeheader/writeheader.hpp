#include "gpioaccess/pinmanager/pinmanager.hpp"
#include "gpioaccess/gpiopin.hpp"
#include <boost/cstdint.hpp>


/*!
 * \brief class that specifies how writing should be done to a gpio pin
 *   this class creates and manages the pins and ensures they are set up appropriately.
 *   to write to a pin a client moduel should inherit from this class implement how writing should be done and call doWrite.
 *   which in turn will call that write function. This class initializes all of the pins given to write and checks to make sure they aren't in use.
 */ 
class WriteHeader : PinManager
{
	
public:
    //! \param[in] vector containing a list of the pins that the user of this class needs to write to.
    WriteHeader(std::string p_pinList[]);

    //! calls the write function appropratly that is implemented by the user of this class.
    virtual void doWrite(const std::string& p_pinNumber, const std::string& p_state);
    
    //! Does nothing.
    virtual ~WriteHeader()
    {
	}

private:
    //! Set up all of the pins
    bool initilize(std::string p_pinList[]);
	
};
