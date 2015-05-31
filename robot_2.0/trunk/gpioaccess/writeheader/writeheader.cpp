#include "writeheader.hpp"

WriteHeader::WriteHeader(std::vector<std::string>& p_pinList)
{
	initilize(p_pinList);
}

bool WriteHeader::initilize(std::vector<std::string>& p_pinList)
{
	for(boost::uint8_t i = 0; i < p_pinList.size(); ++i)
	{
		if(!checkForPin(p_pinList.at(i)))
		{
		    addPin(p_pinList.at(i), "out");
		}
		else 
		{
			return false;
		}
	}
	return true;
}
	
