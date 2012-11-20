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

    static void DisableMotor( CANJaguar& motor );
    static void EnablePercentVbusControl( CANJaguar& motor );
    static void EnableVoltageControl( CANJaguar& motor );
    static void EnableSpeedControl( CANJaguar& motor,
    			double p, double i, double d );
    static void EnablePositionControl( CANJaguar& motor,
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
    
    void DriveCartesian( float x, float y, float rotation );
};

#endif
