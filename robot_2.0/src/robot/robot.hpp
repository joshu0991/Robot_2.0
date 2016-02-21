#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "components/motorcontroller/motorcontroller.hpp"
#include "components/thermometer/thermometer.hpp"

#include <boost/shared_ptr.hpp>

class Robot
{
public:

    Robot();

    /*
        \paramp[in] p_movement a byte which maps to a given direction or movement
            \note 1 forward 2 back 3 left 4 right 5 turn 180 degrees
    */
    void move(const boost::uint8_t p_movement);

    //! Return the distance to the object in front of the sensor.
    void getDistance();

    //! Listen for server connections
    void listen();

    //! Get the video stream and publish it to the client.
    void caputreVideo();

private:
    boost::shared_ptr<Thermometer> m_thermometer;    
        
};

#endif
