#include <WPILib.h>
#include <Commands/Scheduler.h>
#include "CommandBase.h"
#include "Subsystems/DriveBase.h"
#include "Subsystems/BlinkyLight.h"
#include "Subsystems/BallCollector.h"

CommandBase::CommandBase( const char *name ) : CommandGroup( name )
{
}

CommandBase::CommandBase() : CommandGroup()
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

BlinkyLight& CommandBase::theBlinkyLight()
{
    static BlinkyLight blinkyLight;
    return blinkyLight;
}

BallCollector& CommandBase::theBallCollector()
{
    static BallCollector ballCollector;
    return ballCollector;
}

BallTray& CommandBase::theBallTray()
{
    static BallTray ballTray;
    return ballTray;
}
