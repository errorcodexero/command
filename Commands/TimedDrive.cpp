#include "TimedDrive.h"

TimedDrive::TimedDrive() :
    CommandBase("TimedDrive"),
    m_timer()
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&theDriveBase());
    TimedDriveInit( 0.0, 0.0, 0.0, 0.0 );
}

TimedDrive::TimedDrive( float x, float y, float t, float seconds ) : m_timer()
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&theDriveBase());
    TimedDriveInit( x, y, t, seconds );
}

// common code for all constructors
void TimedDrive::TimedDriveInit( float x, float y, float t, float seconds )
{
    m_driveX = x;
    m_driveY = y;
    m_driveT = t;
    m_seconds = seconds;
    m_timer.Start();
}

// Called just before this Command runs the first time
void TimedDrive::Initialize()
{
    theDriveBase().EnableVoltageControl();
    m_timer.Reset();
}

// Call from application to set drive parameters
void TimedDrive::SetDirection( float x, float y, float t )
{
    m_driveX = x;
    m_driveY = y;
    m_driveT = t;
}

void TimedDrive::SetTime( float seconds )
{
    m_seconds = seconds;
}

// Called repeatedly when this Command is scheduled to run
void TimedDrive::Execute()
{
    theDriveBase().DriveCartesian( m_driveX, m_driveY, m_driveT );
}

// Make this return true when this Command no longer needs to run execute()
bool TimedDrive::IsFinished()
{
    return m_timer.Get() >= m_seconds;
}

// Called once after isFinished returns true
void TimedDrive::End()
{
    theDriveBase().DisableMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TimedDrive::Interrupted()
{
    ;
}
