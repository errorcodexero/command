#ifndef DRIVE_BASE_H
#define DRIVE_BASE_H

#include "WPILib.h"
#include "Commands/Subsystem.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveBase: public Subsystem
{
private:
    CANJaguar motorLR;
    CANJaguar motorRR;
    CANJaguar motorLF;
    CANJaguar motorRF;
    RobotDrive drive;
    static void DisableMotor(CANJaguar& motor);
    static void EnableVoltageControl(CANJaguar& motor);
    static void EnableSpeedControl(CANJaguar& motor, double p, double i, double d);
    static void EnablePositionControl(CANJaguar& motor, double p, double i, double d);
    unsigned long m_driveTime;

public:
    DriveBase();
    void InitDefaultCommand();
     
    void DisableMotors();
    void EnableVoltageControl();
    void EnableSpeedControl();
    void EnablePositionControl();
    
    void DriveCartesian(float x, float y, float rotation);
};

#endif
