#include "DriveCommand.h"

DriveCommand::DriveCommand()
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&oi());
    Requires(&driveBase());
}

// Called just before this Command runs the first time
void DriveCommand::Initialize()
{
    driveBase().EnableVoltageControl();
}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute()
{
    driveBase().DriveCartesian( oi().GetDriverX(), oi().GetDriverY(),
    				oi().GetDriverTwist() );
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommand::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void DriveCommand::End()
{
    driveBase().DisableMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommand::Interrupted()
{
    ;
}
