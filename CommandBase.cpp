#include <WPILib.h>
#include <Commands/Scheduler.h>
#include "CommandBase.h"
#include "Subsystems/DriveBase.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize static pointers to each of your subsystems.
OI *CommandBase::c_oi = NULL;
DriveBase *CommandBase::c_driveBase = NULL;

void CommandBase::init() {
    // Create a single static instance of each of your subsystems.
    // The following lines should be repeated for each subsystem
    // in the project.
    if (!oi) { c_oi = new OI(); }
    if (!driveBase) { c_driveBase = new DriveBase(); }
}
