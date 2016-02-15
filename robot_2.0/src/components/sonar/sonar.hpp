#ifndef SONAR_HPP
#define SONAR_HPP

#include <boost/shared_ptr.hpp>

#include "gpioaccess/gpiopin.hpp"
#include "gpioaccess/pinmanager/pinmanager.hpp"
#include "gpioaccess/writeheader/writeheader.hpp"
#include "gpioaccess/readheader/readheader.hpp"

/*
    \brief this class should be created on a thread from the pool.
*/
class Sonar
{
public:
    Sonar(boost::shared_ptr<gpioaccess::WriteHeader> p_writeHeader, boost::shared_ptr<gpioaccess::ReadHeader> p_readHeader, const std::string& p_trigger, const std::string& p_receiver);

    //! Send and receive a ping
    double ping();

    double ping30();
private:
    //! init the module
    void setUp();

private:
    //! Reference to the write header
    boost::shared_ptr<gpioaccess::WriteHeader> m_writeHeader;

    //! Reference read header
    boost::shared_ptr<gpioaccess::ReadHeader> m_readHeader;

    //! The trigger pin to ping out
    std::string m_trigger;

    //! The listner for the ping
    std::string m_receiver;
};

#endif
