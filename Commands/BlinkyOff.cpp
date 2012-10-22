#include "BlinkyOff.h"

BlinkyOff::BlinkyOff() :
    CommandBase("BlinkyOff")
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&theBlinkyLight());
}

// Called just before this Command runs the first time
void BlinkyOff::Initialize()
{
    theBlinkyLight().Set(0.0);
}

// Called repeatedly when this Command is scheduled to run
void BlinkyOff::Execute()
{
    ;
}

// Make this return true when this Command no longer needs to run execute()
bool BlinkyOff::IsFinished()
{
    return true;
}

// Called once after isFinished returns true
void BlinkyOff::End()
{
    ;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BlinkyOff::Interrupted()
{
    ;
}
