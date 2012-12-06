#include "BallCollector.h"
#include "../Robotmap.h"

BallCollector::BallCollector() :
    Subsystem("BallCollector"),
    pwm( BALL_COLLECTOR_PWM  )
{
    Disable();
}
    
// Put methods for controlling this subsystem
// here. Call these from Commands.

void BallCollector::Disable()
{
    pwm.Disable();
    pwm.SetSafetyEnabled(false);
}

void BallCollector::Set( float value )
{
    pwm.Set(value);
    pwm.SetSafetyEnabled(true);
}

