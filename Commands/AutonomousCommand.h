#ifndef AUTONOMOUS_COMMAND_H
#define AUTONOMOUS_COMMAND_H

#include "Commands/CommandGroup.h"

/**
 * <p>This command group combines commands and other command groups to perform
 * a relatively complicated autonomous very robustly. This autonomous:</p>
 * <ol>
 * <li>Drives forward at some preset speed for a preset time.</li>
 * <li>Stops the robot.</li>
 * </ol>
 * 
 * <p>Recommended next step: {@link OI}</p>
 */
class AutonomousCommand: public CommandGroup {
public:	
	AutonomousCommand();
	void Interrupted();
};

#endif
