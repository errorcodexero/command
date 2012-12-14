#include "HoldBalls.h"

HoldBalls::HoldBalls() :
    CommandBase("HoldBalls")
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&theBallCollector());
}

// Called just before this Command runs the first time
void HoldBalls::Initialize()
{
    theBallCollector().Stop();
    theBallCollector().Raise();

    DriverStationLCD *lcd = DriverStationLCD::GetInstance();
    lcd->PrintfLine(DriverStationLCD::kUser_Line2, "hold");
    lcd->UpdateLCD();
}

// Called repeatedly when this Command is scheduled to run
void HoldBalls::Execute()
{
    ;
}

// Make this return true when this Command no longer needs to run execute()
bool HoldBalls::IsFinished()
{
    return true;
}

// Called once after isFinished returns true
void HoldBalls::End()
{
    ;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HoldBalls::Interrupted()
{
    ;
}
