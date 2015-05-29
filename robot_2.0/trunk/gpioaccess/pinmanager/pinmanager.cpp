#include "pinmanager.hpp"

PinManager::~PinManager()
{
}

bool PinManager::addPin(std::string p_pinNumber, const std::string p_mode)
{
	boost::unordered_map<std::string, boost::shared_ptr<GPIOPin> >::const_iterator it = m_pinsInUse.find(p_pinNumber);
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

//! Gets called after we are certain that this pin isn't in use.
bool PinManager::insertPin(std::string p_pinNumber, std::string p_mode)
{
	boost::shared_ptr<GPIOPin> pin(new GPIOPin(p_pinNumber, p_mode));
	m_pinsInUse.insert(std::make_pair<std::string, boost::shared_ptr<GPIOPin> >(p_pinNumber, pin));
	return true;
}
