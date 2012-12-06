#include "../CommandBase.h"
#include "AutonomousCommand.h"
#include "TimedDrive.h"
#include "StopCommand.h"
#include "BlinkyOn.h"
#include "BlinkyOff.h"
#include "BlinkyBreathe.h"
#include "BallCollectorFwd.h"
#include "BallCollectorRev.h"
#include "BallCollectorStop.h"

AutonomousCommand::AutonomousCommand() :
    CommandBase("AutonomousCommand")
{
    Requires(&theDriveBase());
    Requires(&theBlinkyLight());
    Requires(&theBallCollector());
    Requires(&theBallTray());

    theBallTray().Lower();
    AddSequential(new BlinkyOn());
    AddParallel(new BallCollectorFwd());
    AddSequential(new TimedDrive( 0.35, 0.0, 0.0, 3.0 ));
    AddSequential(new BlinkyOff());
    AddSequential(new WaitCommand(0.2));
    AddSequential(new BlinkyOn());
    AddSequential(new TimedDrive( 0.0, 0.0, -0.35, 0.5 ));
    AddSequential(new BlinkyOff());
    AddSequential(new WaitCommand(0.2));
    AddSequential(new BlinkyOn());
    AddSequential(new TimedDrive( 0.0, -0.35, 0.0, 3.0 ));
    AddSequential(new BlinkyOff());
    AddSequential(new WaitCommand(2.0));
    AddParallel(new BallCollectorStop());
    AddParallel(new BlinkyBreathe(8.0));
}

void AutonomousCommand::Interrupted()
{
    theDriveBase().DisableMotors();
    theBlinkyLight().Set(0.0);
    theBallCollector().Set(0.0);
}

