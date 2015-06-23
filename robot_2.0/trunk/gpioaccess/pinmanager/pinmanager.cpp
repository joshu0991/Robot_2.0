#include "pinmanager.hpp"

PinManager::PinManager() :
    m_pinsInUse()
{
}

PinManager::~PinManager()
{
}

bool PinManager::addPin(const std::string& p_pinNumber, const std::string& p_mode)
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
}

//! Gets called after we are certain that this pin isn't in use.
bool PinManager::insertPin(const std::string& p_pinNumber, const std::string& p_mode)
{
	boost::shared_ptr<GPIOPin> pin(new GPIOPin(p_pinNumber, p_mode));
	if(pin)
	{
	    m_pinsInUse.insert(std::make_pair<std::string, boost::shared_ptr<GPIOPin> >(p_pinNumber, pin));
	    return true;
	}
	else
	{
		return false;
	}
}

bool PinManager::removePin(const std::string& p_pinNumber)
{
	// Make sure the pin is in the map.
	boost::unordered_map<std::string, boost::shared_ptr<GPIOPin> >::const_iterator it = m_pinsInUse.find(p_pinNumber);
	if (it == m_pinsInUse.end())
	{
		return false;
	}
	else
	{
		m_pinsInUse.erase(it);
		return true;
	}
}

bool PinManager::checkForPin(const std::string& p_pinNumber)
{
	boost::unordered_map<std::string, boost::shared_ptr<GPIOPin> >::const_iterator it = m_pinsInUse.find(p_pinNumber);
	if (it == m_pinsInUse.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

boost::shared_ptr<GPIOPin> PinManager::getPin(const std::string& p_pinNumber)
{
	boost::unordered_map<std::string, boost::shared_ptr<GPIOPin> >::const_iterator it = m_pinsInUse.find(p_pinNumber);
	if (it == m_pinsInUse.end())
	{
		return boost::shared_ptr<GPIOPin>();
	}
	else
	{
		return it->second;
	}
}
