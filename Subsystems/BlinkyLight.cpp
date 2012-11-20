#include "BlinkyLight.h"
#include "../Robotmap.h"
#include "../Commands/BlinkyOff.h"

BlinkyLight::BlinkyLight() :
    Subsystem("BlinkyLight"),
    pwm( BLINKY_PWM  )
{
    pwm.Set(0.0);
    pwm.SetSafetyEnabled(false);	// blinky lights don't need watchdogs
}
    
void BlinkyLight::InitDefaultCommand()
{
    SetDefaultCommand(new BlinkyOff());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void BlinkyLight::Set( float value )
{
    pwm.Set(value);
}

