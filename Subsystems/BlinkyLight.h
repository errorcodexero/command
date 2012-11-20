#ifndef BLINKY_LIGHT_H
#define BLINKY_LIGHT_H

#include <WPILib.h>

class BlinkyLight: public Subsystem
{
private:
    Victor pwm;

public:
    BlinkyLight();
    void InitDefaultCommand();
    void Set( float value );
};

#endif
