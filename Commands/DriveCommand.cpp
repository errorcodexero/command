#include "DriveCommand.h"
#include "CollectBalls.h"
#include "DumpBalls.h"
#include <math.h>

DriveCommand::DriveCommand() :
    CommandBase("DriveCommand"),
    m_collectBalls(),
    m_dumpBalls(),
    m_direction(k_stopped)
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&theDriveBase());
    Requires(&theBallCollector());
    Requires(&theBlinkyLight());
}

// Called just before this Command runs the first time
void DriveCommand::Initialize()
{
    theDriveBase().DisableMotors();
    theDriveBase().EnableVoltageControl();
    m_direction = k_stopped;
}

void DriveCommand::Go( DriveDirection direction, float speed )
{
    switch (direction) {
    default:
    case k_stopped:
	theDriveBase().DriveCartesian( 0, 0, 0 );
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

    float fwd = -theOI().GetDriverY();
    float side = theOI().GetDriverX();
    DriverStationLCD *lcd = DriverStationLCD::GetInstance();
    if (theOI().GetDriverTrigger()) {
	lcd->PrintfLine(DriverStationLCD::kUser_Line1, "stopped");
	m_direction = k_stopped;
    } else if (fabs(fwd) > fabs(side)) {
	if (fwd > 0.5) {
	    lcd->PrintfLine(DriverStationLCD::kUser_Line1, "forward");
	    m_direction = k_forward;
	} else if (fwd < -0.5) {
	    lcd->PrintfLine(DriverStationLCD::kUser_Line1, "reverse");
	    m_direction = k_reverse;
	}
    } else {
	if (side > 0.5) {
	    lcd->PrintfLine(DriverStationLCD::kUser_Line1, "right");
	    m_direction = k_right;
	} else if (side < -0.5) {
	    lcd->PrintfLine(DriverStationLCD::kUser_Line1, "left");
	    m_direction = k_left;
	}
    }

    float speed = (1.0 - theOI().GetDriverThrottle()) / 2.0;
    Go( m_direction, speed );

    // do something here with the ball collector controls...

    if (theOI().GetDriverButton3()) {
	lcd->PrintfLine(DriverStationLCD::kUser_Line2, "collect");
    	m_collectBalls.Run();
    }
    if (theOI().GetDriverButton4()) {
	lcd->PrintfLine(DriverStationLCD::kUser_Line2, "dump");
	m_dumpBalls.Run();
    }

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
