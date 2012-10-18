#include <WPILib.h>
#include <Commands/Scheduler.h>
#include "CommandBase.h"
#include "Subsystems/DriveBase.h"

CommandBase::CommandBase( const char *name ) : Command( name )
{
}

CommandBase::CommandBase() : Command()
{
}

// Create and return singleton instances of each of your subsystems.
OI& CommandBase::theOI()
{
    static OI oi;
    return oi;
}

DriveBase& CommandBase::theDriveBase()
{
    static DriveBase driveBase;
    return driveBase;
}
