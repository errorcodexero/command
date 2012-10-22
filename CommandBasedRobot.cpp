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
	Command *m_teleopCommand;

	virtual void RobotInit() {
		m_compressor = new Compressor( COMPRESSOR_SWITCH, COMPRESSOR_RELAY );
		m_compressor->Start();
		m_autonomousCommand = new AutonomousCommand();
		m_teleopCommand = new DriveCommand();
	}
	
	virtual void AutonomousInit() {
		m_autonomousCommand->Start();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() {
		m_teleopCommand->Start();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}

};

START_ROBOT_CLASS(CommandBasedRobot);

