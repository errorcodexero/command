#include <WPILib.h>
#include <Commands/Scheduler.h>
#include "CommandBase.h"
#include "Subsystems/DriveBase.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
Joystick* CommandBase::joystick = NULL;
DriveBase* CommandBase::driveBase = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
    // line should be repeated for each subsystem in the project.
    oi = new OI();
    joystick = new Joystick(1);
    driveBase = new DriveBase();
}
