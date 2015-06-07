#include "writeheader.hpp"

WriteHeader::WriteHeader(std::string p_pinList[])
{
	initilize(p_pinList);
}

bool WriteHeader::initilize(std::string p_pinList[])
{
	for(boost::uint8_t i = 0; i < sizeof(p_pinList)/sizeof(std::string); ++i)
	{
		if(!checkForPin(p_pinList[i]))
		{
		    addPin(p_pinList[i], "out");
		}
		else 
		{
			return false;
		}
	}
	return true;
}

void WriteHeader::doWrite(const std::string& p_pinNumber, const std::string& p_state)
{
	boost::shared_ptr<GPIOPin> pin = getPin(p_pinNumber);
	if(pin)
	{
		pin->write(p_state);
	}
}

	
