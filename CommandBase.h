#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Commands/Command.h>
#include "OI.h"
#include "Subsystems/DriveBase.h"
#include "Subsystems/BlinkyLight.h"
#include "Subsystems/BallCollector.h"

// CommandBase is the base for all commands.
// Atomic commands should subclass CommandBase.
// Composite commands should subclass CommandGroup,
// which subclasses CommandBase.
//
// CommandBase creates and stores an instance of each control subsystem.
// To access a subsystem elsewhere in your code in your code use the public
// access functions that return a reference to the singleton objects, e.g.
// CommandBase::theSubsystem().subsystemMethod();

class CommandBase: public Command {
public:
    CommandBase(const char* name);
    CommandBase();

    // Return references to singleton instances of each of your subsystems.
    static OI &theOI();
    static DriveBase &theDriveBase();
    static BlinkyLight &theBlinkyLight();
    static BallCollector &theBallCollector();
};

#endif
