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
    theDriveBase().DriveCartesian( 
    					-theOI().GetDriverY(),
    					theOI().GetDriverX(),
    					theOI().GetDriverTwist() );
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
