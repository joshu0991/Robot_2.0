#include "gpioaccess/pinmanager/pinmanager.hpp"

#include <boost/numeric/ublas/vector.hpp>
/*!
 * \brief class that specifies how writing should be done to a gpio pin
 *   this class creates and manages the pins and ensures they are set up appropriately.
 *   to write to a pin a client moduel should make this make a write header object and call write.
 *   This class initializes all of the pins given to write and checks to make sure they aren't in use.
 */ 
class WriteHeader : PinManager
{
public:
    //! \param[in] vector containing a list of the pins that the user of this class needs to write to.
    WriteHeader(boost::numeric::ublas::vector<const std::string&> p_pinList);

    //! Ensures pin is set up and in the correct direction. gets a pointer to the pin from the map in pin manager and writes the value.
    virtual bool write(const std::string& p_pinNumber, const std::string& p_state) = 0;
	
private: 
    //! handle the set up of the pin.
    void checkForPin(const std::string& p_pinNumber);
};
