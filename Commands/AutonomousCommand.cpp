#include "../CommandBase.h"
#include "AutonomousCommand.h"
#include "TimedDrive.h"
#include "StopCommand.h"
#include "CollectBalls.h"
#include "BlinkyOn.h"
#include "BlinkyOff.h"
#include "BlinkyBreathe.h"

AutonomousCommand::AutonomousCommand() :
    CommandBase("AutonomousCommand")
{
    Requires(&theDriveBase());
    Requires(&theBallCollector());
    Requires(&theBlinkyLight());

    AddSequential(new BlinkyOn());
    AddParallel(new CollectBalls());
    AddSequential(new TimedDrive( 0.35, 0.0, 0.0, 3.0 ));
    AddSequential(new BlinkyOff());
    // AddSequential(new WaitCommand(0.2));
    // AddSequential(new BlinkyOn());
    // AddSequential(new TimedDrive( 0.0, 0.0, -0.35, 0.5 ));
    // AddSequential(new BlinkyOff());
    // AddSequential(new WaitCommand(0.2));
    // AddSequential(new BlinkyOn());
    // AddSequential(new TimedDrive( 0.0, -0.35, 0.0, 3.0 ));
    // AddSequential(new BlinkyOff());
    // AddSequential(new WaitCommand(2.0));
    AddSequential(new StopCommand());
    AddSequential(new BlinkyBreathe(8.0));
}

void AutonomousCommand::Interrupted()
{
    theDriveBase().DisableMotors();
    theBallCollector().Disable();
    theBlinkyLight().Set(0.0);
}

