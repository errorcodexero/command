#include "StopCommand.h"

StopCommand::StopCommand()
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&driveBase());
}

// Called just before this Command runs the first time
void StopCommand::Initialize()
{
    driveBase().DisableMotors();
}

// Called repeatedly when this Command is scheduled to run
void StopCommand::Execute()
{
    ;
}

// Make this return true when this Command no longer needs to run execute()
bool StopCommand::IsFinished()
{
    return true;
}

// Called once after isFinished returns true
void StopCommand::End()
{
    ;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopCommand::Interrupted()
{
    ;
}
