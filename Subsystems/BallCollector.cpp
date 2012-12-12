#include "BallCollector.h"
#include "../Robotmap.h"

BallCollector::BallCollector() :
    Subsystem("BallCollector"),
    pwm( BALL_COLLECTOR_PWM  ),
    raise( BALL_TRAY_RAISE  ),
    lower( BALL_TRAY_LOWER  ),
    m_speed(1.0)
{
    Disable();
}
    
// Put methods for controlling this subsystem
// here. Call these from Commands.

void BallCollector::Disable()
{
    // stop motor
    Stop();

    // stop pneumatics
    raise.Set(false);
    lower.Set(false);
}

void BallCollector::SetSpeed( float value )
{
    m_speed = value;
}

void BallCollector::RunForward()
{
    pwm.Set(m_speed);
//    pwm.SetSafetyEnabled(true);
    pwm.SetSafetyEnabled(false);
}

void BallCollector::RunReverse()
{
    pwm.Set(-m_speed);
//    pwm.SetSafetyEnabled(true);
    pwm.SetSafetyEnabled(false);
}

void BallCollector::Stop()
{
    pwm.Set(0);
    pwm.SetSafetyEnabled(false);
}

void BallCollector::Raise()
{
    lower.Set(false);
    raise.Set(true);
}

void BallCollector::Lower()
{
    raise.Set(false);
    lower.Set(true);
}

