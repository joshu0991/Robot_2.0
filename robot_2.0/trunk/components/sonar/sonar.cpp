#include "sonar.hpp"

#include <boost/chrono.hpp>
#include <boost/thread/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

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

boost::uint64_t Sonar::ping()
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
    std::cout << "Start time: " << startTime << std::endl;
    std::cout << "end time: " << endTime << std::endl;
    auto duration = boost::chrono::duration_cast<boost::chrono::nanoseconds>(endTime - startTime);
    std:: cout << "-----------The time is in nano seconds" << (boost::chrono::duration_cast<boost::chrono::nanoseconds>(endTime - startTime).count()) << std::endl;
    std:: cout << "-----------The time is in seconds" << (boost::chrono::duration_cast<boost::chrono::seconds>(endTime - startTime).count()) << std::endl;
    // calculate distance speed of sound in air is ~34300 so D/(t/2) = 34300 because want the time for half the journey.
    boost::chrono::seconds timeInSeconds = boost::chrono::duration_cast<boost::chrono::seconds>(duration);
    std::cout << "TIME IN SECONDS CONVERTED " << timeInSeconds << std::endl;
    return /*static_cast<boost::uint64_t>*/(timeInSeconds.count() * 17150);
}

void Sonar::setUp()
{
    // Set the pin initially to low.
    m_writeHeader->doWrite(m_trigger, "0");
    boost::this_thread::sleep(boost::posix_time::seconds(5));    
}
