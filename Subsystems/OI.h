// sample robot code
// Steve Tarr - team 1425 mentor

#ifndef _OI_H_
#define _OI_H_

#include <WPILib.h>
#include "Commands/Subsystem.h"

class OI : public Subsystem
{
private:
    DriverStationEnhancedIO *pIO;
    Joystick driverStick, gunnerStick;

public:
    OI();

    float GetDriverY()		{ return driverStick.GetY(); }
    float GetDriverX()		{ return driverStick.GetX(); }
    float GetDriverTwist()	{ return driverStick.GetTwist(); }
    float GetDriverThrottle()	{ return driverStick.GetThrottle(); }
    bool  GetDriverTrigger()	{ return driverStick.GetTrigger(); }
    bool  GetDriverTop()	{ return driverStick.GetTop(); }

    bool TurnAuto()		{ return driverStick.GetRawButton(2); }
    bool TurnLeft10()		{ return driverStick.GetRawButton(3); }
    bool TurnRight10()		{ return driverStick.GetRawButton(4); }
    bool TurnLeft3()		{ return driverStick.GetRawButton(5); }
    bool TurnRight3()		{ return driverStick.GetRawButton(6); }
    bool Brake()		{ return driverStick.GetRawButton(7); }

    float GetGunnerY()		{ return gunnerStick.GetY(); }
    float GetGunnerX()		{ return gunnerStick.GetX(); }
    float GetGunnerTwist()	{ return gunnerStick.GetTwist(); }
    float GetGunnerThrottle()	{ return gunnerStick.GetThrottle(); }
    bool  GetGunnerTrigger()	{ return gunnerStick.GetTrigger(); }
    bool  GetGunnerTop()	{ return gunnerStick.GetTop(); }

    // 3-position switch (0,1,2), ball pickup
    int   BallPickup()		{ return (int)(pIO->GetAnalogInRatio(5) * 2.0 + 0.5); }
    // 3-position switch (0,1,2), cowcatcher
    int   Cowcatcher()		{ return 1; }
    // potentiometer (0..1), shot speed adjust
    float Adjust()		{ return pIO->GetAnalogInRatio(3); }
    // 3-position switch (0,1,2), shooter
    int   Shooter()		{ return (int)(pIO->GetAnalogInRatio(2) * 2.0 + 0.5); }
    // 3-position switch (0,1,2), magic lights
    int   Magic()		{ return 0; }
    // 3-position switch (0,1,2), tipper (ram control)
    int   Tipper()		{ return (int)(pIO->GetAnalogInRatio(6) * 2.0 + 0.5); }

    // pushbutton, fire control
    bool  Shoot()		{ return pIO->GetDigital(1); }
    // key switch, teach mode
    bool  Teach()		{ return pIO->GetDigital(2); }
    // pushbutton, store
    bool  Store()		{ return pIO->GetDigital(3); }
    // pushbutton, target top
    bool  TargetTop()		{ return pIO->GetDigital(4); }
    // pushbutton, target left
    bool  TargetLeft()		{ return pIO->GetDigital(5); }
    // pushbutton, target right
    bool  TargetRight()		{ return pIO->GetDigital(6); }
    // pushbutton, target bottom
    bool  TargetBottom()	{ return pIO->GetDigital(7); }
    // toggle switch, illuminator
    bool  Illuminator()		{ return pIO->GetDigital(8); }

    // LED, ready-to-shoot
    void  ReadyLED( bool value )  { pIO->SetDigitalOutput(10, value); }
    // LED, on-ramp
    void  OnRampLED( bool value ) { pIO->SetDigitalOutput(9, value); }
};

#endif // _OI_H_
