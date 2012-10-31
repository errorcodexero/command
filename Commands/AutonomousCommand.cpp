#include "../CommandBase.h"
#include "AutonomousCommand.h"
#include "TimedDrive.h"
#include "StopCommand.h"
#include "BlinkyOn.h"
#include "BlinkyOff.h"
#include "BlinkyBreathe.h"

AutonomousCommand::AutonomousCommand() :
    CommandGroup("AutonomousCommand")
{
    Requires(&CommandBase::theDriveBase());
    Requires(&CommandBase::theBlinkyLight());

    AddSequential(new BlinkyOn());
    AddSequential(new TimedDrive( 0.0, 4.0, 0.0, 0.5 ));
    AddSequential(new BlinkyOff());
    AddSequential(new WaitCommand(0.2));
    AddSequential(new BlinkyOn());
    AddSequential(new TimedDrive( 4.0, 0.0, 0.0, 0.5 ));
    AddSequential(new BlinkyOff());
    AddSequential(new WaitCommand(2.0));
    AddSequential(new BlinkyBreathe(8.0));
}

void AutonomousCommand::Interrupted()
{
    CommandBase::theDriveBase().DisableMotors();
    CommandBase::theBlinkyLight().Set(0.0);
}

