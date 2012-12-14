#ifndef DRIVE_BASE_H
#define DRIVE_BASE_H

#include <WPILib.h>
#include "../Smart/Smart.h"

class DriveBase: public Subsystem
{
private:
    SmartCANJaguar motorLR;
    SmartCANJaguar motorRR;
    SmartCANJaguar motorLF;
    SmartCANJaguar motorRF;

    RobotDrive drive;

    static void DisableMotor( XCANJaguar& motor );
    static void EnablePercentVbusControl( XCANJaguar& motor );
    static void EnableVoltageControl( XCANJaguar& motor );
    static void EnableSpeedControl( XCANJaguar& motor,
    			double p, double i, double d );
    static void EnablePositionControl( XCANJaguar& motor,
    			double p, double i, double d );
    unsigned long m_driveTime;

public:
    DriveBase();
    void InitDefaultCommand();
     
    void DisableMotors();
    void EnablePercentVbusControl();
    void EnableVoltageControl();
    void EnableSpeedControl();
    void EnablePositionControl();
    
    void DriveCartesian( float fwd, float right, float spin);
};

#endif
