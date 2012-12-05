#ifndef BALL_COLLECTOR_H
#define BALL_COLLECTOR_H

#include <WPILib.h>

class BallCollector: public Subsystem
{
private:
    Victor pwm;

public:
    BallCollector();
    void Disable();
    void Set( float value );
};

#endif
