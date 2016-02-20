#ifndef THERMOMETER_H
#define THERMOMETER_H

#include <boost/thread/thread.hpp>
#include <string>

//! TODO add mutexes, spawn thread in initialize. 

class Thermometer
{
public:

    /*!
        Initialize and return a thermometer object with the sensor being read.
            thermometer is a singleton this gets the only instance
    */
    static boost::shared_ptr<Thermometer> initialize();
 
    //! Read the ds18b20 and update the temperature variable.
    void readSensor();

    //! \return the temperarue.
    double getTemperatureCelcius()
    {
        return m_temperature;
    }

    double getTemperatureFarenheit()
    {
        return (m_temperature * (9 / 5)) + 32;
    }
 
    void shutDown()
    {
        m_shutDown = true;
    }

    double convertTemperature(const std::string& p_data);
    }
private:
    //! Constructor
    Thermometer();

    //! Add kernal modules and make sure environment is sane.
    void initialize();

private:
    boost::thread m_sensorThread

    boost::mutex m_mutex;;

    //! The current temperature in celcius
    double m_temperature;

    bool m_shutDown;

    // need mutex and thread member
};

#endif
