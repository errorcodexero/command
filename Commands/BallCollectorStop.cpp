#include "BallCollectorStop.h"

BallCollectorStop::BallCollectorStop() :
    CommandBase("BallCollectorStop")
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&theBallCollector());
}

// Called just before this Command runs the first time
void BallCollectorStop::Initialize()
{
    theBallCollector().Disable();
}

// Called repeatedly when this Command is scheduled to run
void BallCollectorStop::Execute()
{
    ;
}

// Make this return true when this Command no longer needs to run execute()
bool BallCollectorStop::IsFinished()
{
    return true;
}

// Called once after isFinished returns true
void BallCollectorStop::End()
{
    ;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallCollectorStop::Interrupted()
{
    ;
}
