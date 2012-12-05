#include "BallCollectorFwd.h"

BallCollectorFwd::BallCollectorFwd() :
    CommandBase("BallCollectorFwd")
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&theBallCollector());
}

// Called just before this Command runs the first time
void BallCollectorFwd::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void BallCollectorFwd::Execute()
{
    theBallCollector().Set(1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool BallCollectorFwd::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void BallCollectorFwd::End()
{
    ;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallCollectorFwd::Interrupted()
{
    ;
}
