#include "BlinkyBreathe.h"
#include <math.h>

#ifndef M_PI
#define	M_PI	3.1415926535
#endif

BlinkyBreathe::BlinkyBreathe( float seconds ) :
    CommandBase("BlinkyBreathe"),
    m_startTime(0.0),
    m_cycleTime(seconds * 1.0e6)
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&theBlinkyLight());
}

// Called just before this Command runs the first time
void BlinkyBreathe::Initialize()
{
    m_startTime = GetFPGATimestamp();
    theBlinkyLight().Set(0.0);
}

// Called repeatedly when this Command is scheduled to run
void BlinkyBreathe::Execute()
{
    double elapsed = GetFPGATimestamp() - m_startTime;
    // sin ranges from -1.0 to +1.0, we need 0.0 to +1.0
    float breathe = (sin(2.0 * M_PI * elapsed / m_cycleTime) + 1.0) / 2.0;
    theBlinkyLight().Set((breathe);
}

// Make this return true when this Command no longer needs to run execute()
bool BlinkyBreathe::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void BlinkyBreathe::End()
{
    ;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BlinkyBreathe::Interrupted()
{
    theBlinkyLight().Set(0.0);
}
