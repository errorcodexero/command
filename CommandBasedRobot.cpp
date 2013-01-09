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
    Command *m_disabledCommand;

    virtual void RobotInit() {
	m_compressor = new Compressor( COMPRESSOR_SWITCH, COMPRESSOR_RELAY );
	m_compressor->Start();
	m_autonomousCommand = new AutonomousCommand();
	m_teleopCommand = new DriveCommand();
	m_disabledCommand = new StopCommand();
    }
    
    virtual void AutonomousInit() {
	m_disabledCommand->Cancel();
	m_teleopCommand->Cancel();
	m_autonomousCommand->Start();
    }
    
    virtual void AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
    }

    virtual void AutonomousContinuous() {
	taskDelay(1);
    }
    
    virtual void TeleopInit() {
	m_disabledCommand->Cancel();
	m_autonomousCommand->Cancel();
	m_teleopCommand->Start();
    }
    
    virtual void TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
    }

    virtual void TeleopContinuous() {
	taskDelay(1);
    }

    virtual void DisabledInit() {
        m_autonomousCommand->Cancel();
	m_teleopCommand->Cancel();
	m_disabledCommand->Start();
    }

    virtual void DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
    }

    virtual void DisabledContinuous() {
	taskDelay(1);
    }

};

START_ROBOT_CLASS(CommandBasedRobot);

