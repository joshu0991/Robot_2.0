#include "pinmanager.hpp"

PinManager::~PinManager()
{
}

bool PinManager::addPin(const boost::uint8_t p_pinNumber, const std::string p_mode)
{
	boost::unordered_map<boost::uint8_t, boost::intrusive_ptr<GPIOPin> >::const_iterator it = m_pinsInUse.find(p_pinNumber);
	// not found make a new pin object and insert it.
	if(it == m_pinsInUse.end())
	{
		return insertPin(p_pinNumber, p_mode);
	}
	// pin found can't insert pin it's in use.
	else
	{
		return false;
	}
	return true;
}

//bool PinManager::addPin(
