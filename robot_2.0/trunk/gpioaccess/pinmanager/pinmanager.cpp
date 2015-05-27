#include "pinmanager.hpp"

bool PinManager::addPin(boost::uint8_t p_pinNumber)
{
	boost::unordered_map<boost::uint8_t, boost::intrusive_ptr<GPIOPin> >::const_iterator it = m_pinsInUse.find(p_pinNumber);
	// not found make a new pin object and insert it.
	if(it == m_pinsInUse.end())
	{
		//insertPin(p_pinNumber);
	}
	// pin found can't insert pin it's in use.
	else
	{
		return false;
	}
	return true;
}
