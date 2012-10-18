#include "AutonomousCommand.h"
#include "TimedDrive.h"
#include "StopCommand.h"

AutonomousCommand::AutonomousCommand() {
    AddSequential(new TimedDrive( 0.0, 6.5, 0.0, 3.0 ));
    AddSequential(new TimedDrive( 6.5, 0.0, 0.0, 2.5 ));
    // This is the default command for the DriveBase,
    // so it doesn't need to be called here.
    // AddSequential(new StopCommand());
}
