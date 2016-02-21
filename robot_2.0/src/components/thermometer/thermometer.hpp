#ifndef THERMOMETER_H
#define THERMOMETER_H

#include <boost/thread/thread.hpp>

#include <dirent.h>
#include <string>

//! TODO add mutexes, spawn thread in initialize. 

class Thermometer
{
public:

    /*!
        Initialize and return a thermometer object with the sensor being read.
            thermometer is a singleton this gets the only instance
    */
    static boost::shared_ptr<Thermometer> thermometer();
 
    //! Read the ds18b20 and update the temperature variable.
    void readSensor();

    //! \return the temperarue.
    double getTemperatureCelcius()
    {
        m_mutex.lock();
        return m_temperature;
        m_mutex.unlock();
    }

    double getTemperatureFarenheit()
    {
        m_mutex.lock();
        return (m_temperature * (9 / 5)) + 32;
        m_mutex.unlock();
    }
 
    void shutDown()
    {
        m_shutDown = true;
    }

    double convertTemperature(const std::string& p_data);

    ~Thermometer();

private:
    //! Constructor
    Thermometer();

    Thermometer(const Thermometer& therm);

    //! Add kernal modules and make sure environment is sane.
    void initialize();

private:
    boost::thread m_sensorThread;

    boost::mutex m_mutex;;

    //! The current temperature in celcius
    double m_temperature;

    struct dirent *dirent;

    bool m_shutDown;

    // need mutex and thread member
};

#endif
