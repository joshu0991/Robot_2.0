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
        std::cout << "Inserting pin " << std::endl;
        return insertPin(p_pinNumber, p_mode);
    }
    // pin found can't insert pin it's in use.
    else
    {
        std::cout << "Cannot add pin since it is already in use" << std::endl;
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
        std::cout << "successfully inserted pin " << std::endl;
        return true;
     }
    else
    {
        std::cout << "Failed to insert pin" << std::endl;
        return false;
    }
}

bool PinManager::removePin(const std::string& p_pinNumber)
{
    // Make sure the pin is in the map.
    boost::unordered_map<std::string, boost::shared_ptr<GPIOPin> >::const_iterator it = m_pinsInUse.find(p_pinNumber);
    if (it == m_pinsInUse.end())
    {
        std::cout << "Pin not in map" << std::endl;
        return false;
    }
    else
    {
        std::cout << "Erasing pin " << std::endl;
        m_pinsInUse.erase(it);
        return true;
    }
}

bool PinManager::checkForPin(const std::string& p_pinNumber)
{
    boost::unordered_map<std::string, boost::shared_ptr<GPIOPin> >::const_iterator it = m_pinsInUse.find(p_pinNumber);
    if (it == m_pinsInUse.end())
    {
        std::cout << "Could not find pin in map" << std::endl;
        return false;
    }
    else
    {
        std::cout << "Found pin in map" << std::endl;
        return true;
    }
}

boost::shared_ptr<GPIOPin> PinManager::getPin(const std::string& p_pinNumber)
{
    boost::unordered_map<std::string, boost::shared_ptr<GPIOPin> >::const_iterator it = m_pinsInUse.find(p_pinNumber);
    if (it == m_pinsInUse.end())
    {
        std::cout << "Failed to get pin returning null" << std::endl;
        return boost::shared_ptr<GPIOPin>();
    }
    else
    {
        std::cout << "Found pin returning it." << std::endl;
        return it->second;
    }
}
