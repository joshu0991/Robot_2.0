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
    // Send a 20 microsecond pulse
    m_writeHeader->doWrite(m_trigger, "1");
    boost::this_thread::sleep(boost::posix_time::microseconds(20));
    m_writeHeader->doWrite(m_trigger, "0");
    std::cout << "------------------------in ping gfunction " << std::endl;    
    //while low increment the start time.
    while(m_readHeader->doRead(m_receiver) == 0)
    {
        std::cout << "---------------------------pin is low " << std::endl;
        // Start time listining for a ping.
        startTime = boost::chrono::high_resolution_clock::now();
    }
    while(m_readHeader->doRead(m_receiver) == 1)   
    {
        // Get the trip time 
        endTime = boost::chrono::high_resolution_clock::now();
    }
    std::cout << "Start time: " << startTime << std::endl;
    std::cout << "end time: " << endTime << std::endl;
    std:: cout << "-----------The time is " << (boost::chrono::duration_cast<boost::chrono::nanoseconds>(endTime - startTime).count()) << std::endl;
    // calculate distance speed of sound in air is ~34300 so D/(t/2) = 34300 because want the time for half the journey.
    return (boost::chrono::duration_cast<boost::chrono::seconds>(endTime - startTime).count()) * 17150;
}

void Sonar::setUp()
{
    // Set the pin initially to low.
    m_writeHeader->doWrite(m_trigger, "0");
    boost::this_thread::sleep(boost::posix_time::seconds(2));    
}
