#include "DriveCommand.h"
#include "CollectBalls.h"
#include "DumpBalls.h"
#include <math.h>

DriveCommand::DriveCommand() :
    CommandBase("DriveCommand"),
    m_direction(k_joystick)
{
    // Use Requires() here to declare subsystem dependencies.
    // Don't include the BallCollector here - it's driven by
    // subcommands which have their own dependencies.
    Requires(&theDriveBase());
    Requires(&theBlinkyLight());
}

// Called just before this Command runs the first time
void DriveCommand::Initialize()
{
    theDriveBase().DisableMotors();
    theDriveBase().EnableSpeedControl();
    m_direction = k_joystick;
    DriverStationLCD *lcd = DriverStationLCD::GetInstance();
    lcd->PrintfLine(DriverStationLCD::kUser_Line1, "joystick");
    lcd->UpdateLCD();
}

void DriveCommand::Go( DriveDirection direction, float speed )
{
    switch (direction) {
    default:
    case k_joystick:
	float fwd = -theOI().GetDriverY() * speed;
	float side = theOI().GetDriverX() * speed;
	float twist = theOI().GetDriverTwist() * speed;
	theDriveBase().DriveCartesian( fwd, side, twist );
	break;
    case k_forward:
	theDriveBase().DriveCartesian( speed, 0, 0 );
	break;
    case k_reverse:
	theDriveBase().DriveCartesian( -speed, 0, 0 );
	break;
    case k_right:
	theDriveBase().DriveCartesian( 0, speed, 0 );
	break;
    case k_left:
	theDriveBase().DriveCartesian( 0, -speed, 0 );
	break;
    }

    theBlinkyLight().Set(speed);
}


// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute()
{
    // The flight stick output is:
    // stick-forward -y
    // stick-reverse +y
    // stick-right   +x
    // stick-left    -x
    // twist-right   +t
    // twist-left    -t

    DriverStationLCD *lcd = DriverStationLCD::GetInstance();

    float fwd = -theOI().GetDriverY();
    float side = theOI().GetDriverX();

    if (theOI().GetDriverTrigger()) {
	if (fabs(fwd) > fabs(side)) {
	    if (fwd > 0.5) {
		lcd->PrintfLine(DriverStationLCD::kUser_Line1, "forward");
		m_direction = k_forward;
	    } else if (fwd < -0.5) {
		lcd->PrintfLine(DriverStationLCD::kUser_Line1, "reverse");
		m_direction = k_reverse;
	    } else {
		lcd->PrintfLine(DriverStationLCD::kUser_Line1, "joystick");
		m_direction = k_joystick;
	    }
	} else {
	    if (side > 0.5) {
		lcd->PrintfLine(DriverStationLCD::kUser_Line1, "right");
		m_direction = k_right;
	    } else if (side < -0.5) {
		lcd->PrintfLine(DriverStationLCD::kUser_Line1, "left");
		m_direction = k_left;
	    } else {
		lcd->PrintfLine(DriverStationLCD::kUser_Line1, "joystick");
		m_direction = k_joystick;
	    }
	}
    }

    float speed = (1.0 - theOI().GetDriverThrottle()) / 2.0;
    Go( m_direction, speed );

    lcd->UpdateLCD();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommand::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void DriveCommand::End()
{
    ;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommand::Interrupted()
{
    theDriveBase().DisableMotors();
    theBallCollector().Disable();
    theBlinkyLight().Set(0.0);
}
