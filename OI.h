// sample robot code
// Steve Tarr - team 1425 mentor

#ifndef _OI_H_
#define _OI_H_

#include <WPILib.h>
#include "../Smart/Smart.h"

class OI
{
private:
    DriverStationEnhancedIO *pIO;
    SmartJoystick driverStick;
    JoystickButton button2;
    JoystickButton button3;
    JoystickButton button4;
    JoystickButton button5;
    JoystickButton button6;

public:
    OI();

    float GetDriverY()		{ return driverStick.GetY(); }
    float GetDriverX()		{ return driverStick.GetX(); }
    float GetDriverTwist()	{ return driverStick.GetTwist(); }
    float GetDriverThrottle()	{ return driverStick.GetThrottle(); }
    bool  GetDriverTrigger()	{ return driverStick.GetTrigger(); }
    bool  GetDriverTop()	{ return driverStick.GetTop(); }

    bool GetDriverButton2()	{ return driverStick.GetRawButton(2); }
    bool GetDriverButton3()	{ return driverStick.GetRawButton(3); }
    bool GetDriverButton4()	{ return driverStick.GetRawButton(4); }
    bool GetDriverButton5()	{ return driverStick.GetRawButton(5); }
    bool GetDriverButton6()	{ return driverStick.GetRawButton(6); }
    bool GetDriverButton7()	{ return driverStick.GetRawButton(7); }
};

#endif // _OI_H_
