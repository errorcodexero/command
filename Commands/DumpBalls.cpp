#include "DumpBalls.h"

DumpBalls::DumpBalls() :
    CommandBase("DumpBalls")
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&theBallCollector());
}

// Called just before this Command runs the first time
void DumpBalls::Initialize()
{
    theBallCollector().Lower();
    theBallCollector().SetSpeed(1.0);

    DriverStationLCD *lcd = DriverStationLCD::GetInstance();
    lcd->PrintfLine(DriverStationLCD::kUser_Line2, "dump");
    lcd->UpdateLCD();
}

// Called repeatedly when this Command is scheduled to run
void DumpBalls::Execute()
{
    theBallCollector().RunReverse();
}

// Make this return true when this Command no longer needs to run execute()
bool DumpBalls::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void DumpBalls::End()
{
    ;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DumpBalls::Interrupted()
{
    ;
}
