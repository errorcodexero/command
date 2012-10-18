#include <WPILib.h>
#include <Commands/Command.h>
#include "Robotmap.h"
#include "CommandBase.h"
#include "Commands/DriveCommand.h"
#include "Commands/TimedDrive.h"
#include "Commands/StopCommand.h"
#include "Commands/AutonomousCommand.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Compressor *m_compressor;
	Command *m_autonomousCommand;

	virtual void RobotInit() {
		m_compressor = new Compressor( COMPRESSOR_SWITCH, COMPRESSOR_RELAY );
		m_compressor->Start();
		m_autonomousCommand = new AutonomousCommand();
	}
	
	virtual void AutonomousInit() {
		m_autonomousCommand->Start();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		m_autonomousCommand->Cancel();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}

};

START_ROBOT_CLASS(CommandBasedRobot);

