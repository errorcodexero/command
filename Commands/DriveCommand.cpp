#include "DriveCommand.h"
#include "CollectBalls.h"
#include "DumpBalls.h"

DriveCommand::DriveCommand() :
    CommandBase("DriveCommand"),
    m_collectBalls(),
    m_dumpBalls()
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&theDriveBase());
    Requires(&theBallCollector());
}

// Called just before this Command runs the first time
void DriveCommand::Initialize()
{
    theDriveBase().EnableVoltageControl();
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

    float scale = (theOI().GetDriverThrottle() + 1.0) / 2.0;
    theDriveBase().DriveCartesian( -theOI().GetDriverY() * scale,
				   theOI().GetDriverX() * scale,
				   theOI().GetDriverTwist() * scale );

    // do something here with the ball collector controls...

    if (theOI().GetDriverButton2()) {
    	m_collectBalls.Run();
    }
    if (theOI().GetDriverButton3()) {
	m_dumpBalls.Run();
    }
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
