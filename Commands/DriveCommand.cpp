#include "DriveCommand.h"

DriveCommand::DriveCommand() :
    CommandBase("DriveCommand")
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&theDriveBase());
}

// Called just before this Command runs the first time
void DriveCommand::Initialize()
{
    theDriveBase().EnablePercentVbusControl();
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

    // Reorient the axes to match what we want for the
    // robot platform:
    // robot-forward  +y
    // robot-backward -y
    // robot-right    +x
    // robot-left     -x
    // turn-right     -t
    // turn-left      +t

    theDriveBase().DriveCartesian( theOI().GetDriverX(),
				   -theOI().GetDriverY(),
				   -theOI().GetDriverTwist() );
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
