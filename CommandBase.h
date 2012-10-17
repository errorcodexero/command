#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Commands/Command.h>
#include "Subsystems/OI.h"
#include "Subsystems/DriveBase.h"

// The base for all commands.  All atomic commands should subclass CommandBase.
// CommandBase creates and stores an instance of each control subsystem.
// To access a subsystem elsewhere in your code in your code use the public
// access functions that return a reference to the singleton objects, e.g.
// CommandBase::exampleSubsystem().examplemethod

class CommandBase: public Command {
private:
    // Create a single static instance of each of your subsystems
    static OI *c_oi;
    static DriveBase *c_driveBase;

public:
    CommandBase(const char *name);
    CommandBase();
    static void init();

    // Return references to singleton instances.
    static OI &oi() { return *c_oi; };
    static DriveBase &driveBase() { return *c_driveBase; };
};

#endif
