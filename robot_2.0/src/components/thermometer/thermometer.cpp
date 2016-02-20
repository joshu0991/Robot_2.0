#include "thermometer.hpp"

#include <boost/date_time/posix_time/posix_time.hpp>

#include <dirent.h>
#include <fstream>
#include <stdexcept>
#include <ctime>

Thermometer::Thermometer() : m_sensorThread(), m_mutex(), m_temperature(0), m_shutDown(false)
{
}

void Thermometer::initialize()
{
    bool found = false;
    std::string line;
    std::ifstream bootFile("/boot/config.txt");
    if (bootFile.is_open())
    {
        while ( getline(bootFile, line) )
        {
            // check to see if this is the dtoverlay line
            std::size_t result = line.find("dtoverlay");
            if (result != std::string::npos)
            {
                result = line.fine("w1-gpio");
                if (result == std::string::npos)
                {
                    throw std::logic_error("boot.txt does not contain the necessary content.");
                }
            }
        }
        bootFile.close();
        found = true;
    }

    if (found)
    {
        system("sudo modprobe w1-gpio");
        system("sudo modprobe w1-therm");
    }
    else
    {
        throw std::logic_error("Failed to initialize");
    }

    //spawn member thread reading sensor need mutex!!!!i
    m_sensorThread = boost::thread(&Thermometer::readSensor, this);
}

void Thermometer::readSensor()
{
    char[] path = "/sys/bus/w1/devices";
    DIR* directory = opendir(path);
    char sensorID[16];
    char devicePath[128];
    
    if (directory == NULL)
    {
        throw std::system_error("failed to open directory");
    }

    while ((dirent = readdir(directory)))
    {
        // What we are looking for?
        if ((dirent->d_name[0] == '2'&&
            dirent->d_name[1] == '8' && dirent->d_name[2] == '-'))
        {
            strcpy(sensorID, dirent->d_name);
            (void) closedir(directory);
            sprintf(devicePath, "%s/%s/w1_slave", path, sensorID);
            // We'll only allow one temperature sensor.
            break;
        }
    }

    if (sensorID == NULL)
    {
        throw std::logic_exception("Failed to find sensor directory");
    }

    std::string sensorData;
    std::ifstream temperatureStream(devicePath);
    // spawns on own thread in initialize...
    while (!m_shutDown)
    {
        getline(temperatureStream, data);
        getline(temperatureStream, data);
        
        // Move back to the beginning
        temperatureStream.clear();
        temperatureStream.seekg(0, ios::begin);

        m_mutex.lock();
        m_temperature = convertTemperature(data);
        m_mutex.unlock();

        // only update every ten minutes.
        boost::this_thread::sleep(boost::posix_time::seconds(600));
    }
}

double Thermometer::convertTemperature(const std::string& p_data)
{
    boost::uint16_t counter = 0;

     // what we read the temperature into
    char buffer[5];

    while (counter < p_data.length())
    {
        if (p_data[counter] = 't')
        {
            break;
        }
        ++counter;
    }
 
    // temp starts 2 after the t!
    boost::uint16_t tPosition = counter += 2;
    counter = 0;
    
    while (tPosition < p_data.length() && counter < 5)
    {
        buffer[counter] = p_data[tPosition];
        ++tPosition;
        ++counter;
    }
    return static_cast<double>(atof(buffer));
}

boost::shared_ptr<Thermometer> Thermometer::initialize()
{
    static boost::shared_ptr<Thermometer> therm;
    if (!therm)
    {
        therm(new Thermometer());
        therm->initialize();
    } 
    return therm;
}
