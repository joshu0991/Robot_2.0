#include "robot.hpp"

#include "gpioaccess/gpiopin.hpp"
#include "gpioaccess/pinmanager/pinmanager.hpp"
#include "gpioaccess/writeheader/writeheader.hpp"

int main()
{
	std::string pins[] = {"18"};
	WriteHeader header(pins);
	std::cout << "Hello World " << std::endl;
	return 0;
}
