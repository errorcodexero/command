#include "BallCollectorRev.h"

BallCollectorRev::BallCollectorRev() :
    CommandBase("BallCollectorRev")
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&theBallCollector());
}

// Called just before this Command runs the first time
void BallCollectorRev::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void BallCollectorRev::Execute()
{
    theBallCollector().Set(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool BallCollectorRev::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void BallCollectorRev::End()
{
    ;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallCollectorRev::Interrupted()
{
    ;
}
