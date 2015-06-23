#include "robot.hpp"


#include "gpioaccess/gpiopin.hpp"
#include "gpioaccess/pinmanager/pinmanager.hpp"
#include "gpioaccess/writeheader/writeheader.hpp"

int main()
{
	std::string pins[] = {"18"};
	WriteHeader header(pins);
    header.doWrite("18", "1");
	return 0;
}
