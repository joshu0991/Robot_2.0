#ifndef THERMOMETER_H
#define THERMOMETER_H

#include <boost/thread/thread.hpp>

#include <dirent.h>
#include <string>

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

    //! \return the temperarue in celcius.
    double getTemperatureCelcius()
    {
        m_mutex.lock();
        return m_temperature;
        m_mutex.unlock();
    }

    //! \return the temp in farenheit
    double getTemperatureFarenheit()
    {
        m_mutex.lock();
        return (m_temperature * (9 / 5)) + 32;
        m_mutex.unlock();
    }
 
    //! Shutdown the sensor.
    void shutDown()
    {
        m_shutDown = true;
    }

    /*!
        Convert the temp from a char [] to a double value
        \param[in] p_data the data to convert
        \return double precison temperature representation 5 digits
    */
    double convertTemperature(const std::string& p_data);

    //! Public for shared_ptr
    ~Thermometer();

private:

    //! Constructor
    Thermometer();

    //! Class has pointer members made private to comply
    Thermometer(const Thermometer& therm);

    //! Add kernal modules and make sure environment is sane.
    void initialize();

private:
    //! The thread reading the sensor
    boost::thread m_sensorThread;

    //! Mutex for locking the temperature variable
    boost::mutex m_mutex;;

    //! The current temperature in celcius
    double m_temperature;

    //! Used for finding the sensor
    struct dirent *dirent;

    //! Wheather or not to shutdown the thread
    bool m_shutDown;

    // need mutex and thread member
};

#endif
