#include "sonar.hpp"

#include <boost/chrono.hpp>
#include <boost/thread/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <numeric>
#include <vector>

Sonar::Sonar(boost::shared_ptr<gpioaccess::WriteHeader> p_writeHeader, 
             boost::shared_ptr<gpioaccess::ReadHeader> p_readHeader, 
             const std::string& p_trigger, 
             const std::string& p_receiver) : 
                 m_writeHeader(p_writeHeader),
                 m_readHeader(p_readHeader),
                 m_trigger(p_trigger),
                 m_receiver(p_receiver)
{
    setUp();
}

double Sonar::ping()
{
    boost::chrono::high_resolution_clock::time_point startTime, endTime; 
    bool receivedPulse = false;
    // Send a 10 microsecond pulse
    m_writeHeader->doWrite(m_trigger, "1");
    boost::this_thread::sleep(boost::posix_time::microseconds(10));
    m_writeHeader->doWrite(m_trigger, "0");
    //while low increment the start time.
    while(true)
    {
        boost::uint64_t value = m_readHeader->doRead(m_receiver);
        if (value == 0)
        {
            std::cout << "---------------------------pin is low " << std::endl;
            // Start time listining for a ping.
            if (receivedPulse)
            {
                break;
            }
            startTime = boost::chrono::high_resolution_clock::now();
        }

        if (value == 1)
        {   
            std::cout << "Pin is high" << std::endl; 
            endTime = boost::chrono::high_resolution_clock::now();
            receivedPulse = true;
        }
    }
    //boost::chrono::duration<double> distance = 
    boost::chrono::duration<double> time = endTime - startTime;
    std::cout << "Time of ping" << time.count() << std::endl;
    // calculate distance speed of sound in air is ~34300 so D/(t/2) = 34300 because want the time for half the journey.
    return time.count() * 17150.0;
}

double Sonar::ping30()
{

    std::vector<double> values; 
    for(boost::uint8_t i = 0; i < 30; ++i)
    {
        std::cout << "********************************** calling ping" << std::endl;
        values.push_back(ping());
        boost::this_thread::sleep(boost::posix_time::seconds(1));
    }
    double sum = std::accumulate(values.begin(), values.end(), 0);
    return sum / 30;
}

void Sonar::setUp()
{
    // Set the pin initially to low.
    m_writeHeader->doWrite(m_trigger, "0");
    boost::this_thread::sleep(boost::posix_time::seconds(5));    
}
