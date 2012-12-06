#include "DriveCommand.h"
#include "BallCollectorFwd.h"
#include "BallCollectorRev.h"

DriveCommand::DriveCommand() :
    CommandBase("DriveCommand")
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&theDriveBase());
    Requires(&theBallTray());
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

    if (theOI().GetDriverTrigger()) {
    	theBallTray().Raise();
    	AddParallel(new BallCollectorRev());
    } else {
    	theBallTray().Lower();
    	AddParallel(new BallCollectorFwd());
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
    theDriveBase().DisableMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommand::Interrupted()
{
    ;
}
