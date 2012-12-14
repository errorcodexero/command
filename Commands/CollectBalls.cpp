#include "CollectBalls.h"

CollectBalls::CollectBalls() :
    CommandBase("CollectBalls")
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(&theBallCollector());
}

// Called just before this Command runs the first time
void CollectBalls::Initialize()
{
    theBallCollector().Lower();
    theBallCollector().SetSpeed(1.0);

    DriverStationLCD *lcd = DriverStationLCD::GetInstance();
    lcd->PrintfLine(DriverStationLCD::kUser_Line2, "collect");
    lcd->UpdateLCD();
}

// Called repeatedly when this Command is scheduled to run
void CollectBalls::Execute()
{
    theBallCollector().RunForward();
}

// Make this return true when this Command no longer needs to run execute()
bool CollectBalls::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void CollectBalls::End()
{
    ;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CollectBalls::Interrupted()
{
    ;
}
