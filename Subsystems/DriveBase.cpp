#include "DriveBase.h"
#include "../Robotmap.h"
#include "../Commands/StopCommand.h"

// the following could go in Robotmap.h

#define	ENCODER_COUNT	360

#define	SPEED_P		0.100
#define	SPEED_I		0.003
#define	SPEED_D		0.001

#define	MAX_SPEED	500		// RPM

#define	POSITION_P	6000.
#define	POSITION_I	5.000
#define	POSITION_D	0.500

#define	MAX_OUTPUT	8.		// reachable even with a low battery

#define	DRIVE_TOLERANCE	0.50

#define	TURN_TOLERANCE	0.35

DriveBase::DriveBase() : Subsystem("DriveBase"),
    motorLR( CAN_LEFT_REAR,   "LR" ),
    motorRR( CAN_RIGHT_REAR,  "RR" ),
    motorLF( CAN_LEFT_FRONT,  "LF" ),
    motorRF( CAN_RIGHT_FRONT, "RF" ),
    drive(motorLF, motorLR, motorRF, motorRR)
    //default motor order: drive(motorLF, motorLR, motorRF, motorRR)
{
    drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
    drive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
}
    
void DriveBase::InitDefaultCommand()
{
    SetDefaultCommand(new StopCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveBase::DisableMotor( XCANJaguar& motor )
{
    motor.DisableControl();
    motor.SetSafetyEnabled(false);	// CANJaguar *should* do this
}

void DriveBase::DisableMotors()
{
    drive.StopMotor();
    drive.SetSafetyEnabled( false );	// RobotDrive *should* do this

    DisableMotor( motorLR );		// RobotDrive *should* do this as well
    DisableMotor( motorRF );		// RobotDrive *should* do this as well
    DisableMotor( motorLF );		// RobotDrive *should* do this as well
    DisableMotor( motorRR );		// RobotDrive *should* do this as well
}

void DriveBase::EnablePercentVbusControl( XCANJaguar& motor )
{
    motor.ConfigMaxOutputVoltage( MAX_OUTPUT );	// does this matter?
    motor.ChangeControlMode( XCANJaguar::kPercentVbus );
    motor.ConfigNeutralMode( XCANJaguar::kNeutralMode_Coast );

    // force change in control mode
    motor.EnableControl();

    // Feed the watchdog now to avoid a race condition when enabling
    //   motorSafetyHelper with the previous timer already expired.
    motor.Set( 0.0F, 0 );

    // RobotDrive will handle safety
    motor.SetSafetyEnabled( false );

    // Set the timer a little longer than default
    //   to allow for CAN timeouts and retries.
    motor.SetExpiration( 0.5 );

    // Feed the watchdog again with the new interval.
    motor.Set( 0.0F, 0 );
}

void DriveBase::EnablePercentVbusControl()
{
    EnablePercentVbusControl( motorLR );
    EnablePercentVbusControl( motorRF );
    EnablePercentVbusControl( motorLF );
    EnablePercentVbusControl( motorRR );

    drive.SetMaxOutput( 1.0 );	// 100% of Vbus

    // Feed the watchdog now to avoid a race condition when enabling
    //   motorSafetyHelper with the previous timer already expired.
    drive.SetLeftRightMotorOutputs( 0.0F, 0.0F );

    // Now it's safe to enable.
    drive.SetSafetyEnabled( true );

    // Set the timer a little longer than default
    //   to allow for CAN timeouts and retries.
    drive.SetExpiration( 0.5 );

    // Feed the watchdog again with the new interval.
    drive.SetLeftRightMotorOutputs( 0.0F, 0.0F );
}

void DriveBase::EnableVoltageControl( XCANJaguar& motor )
{
    // set max voltage to something reachable even with a low battery
    motor.ConfigMaxOutputVoltage( MAX_OUTPUT );
    motor.ChangeControlMode( XCANJaguar::kVoltage );
    motor.ConfigNeutralMode( XCANJaguar::kNeutralMode_Coast );

    // force change in control mode
    motor.EnableControl();

    // Feed the watchdog now to avoid a race condition when enabling
    //   motorSafetyHelper with the previous timer already expired.
    motor.Set( 0.0F, 0 );

    // RobotDrive will handle safety
    motor.SetSafetyEnabled( false );

    // Set the timer a little longer than default
    //   to allow for CAN timeouts and retries.
    motor.SetExpiration( 0.5 );

    // Feed the watchdog again with the new interval.
    motor.Set( 0.0F, 0 );
}

void DriveBase::EnableVoltageControl()
{
    EnableVoltageControl( motorLR );
    EnableVoltageControl( motorRF );
    EnableVoltageControl( motorLF );
    EnableVoltageControl( motorRR );

    drive.SetMaxOutput( 8.0 );	// 8.0 volts for consistent results
    				// with low battery

    // Feed the watchdog now to avoid a race condition when enabling
    //   motorSafetyHelper with the previous timer already expired.
    drive.SetLeftRightMotorOutputs( 0.0F, 0.0F );

    // Now it's safe to enable.
    drive.SetSafetyEnabled( true );

    // Set the timer a little longer than default
    //   to allow for CAN timeouts and retries.
    drive.SetExpiration( 0.5 );

    // Feed the watchdog again with the new interval.
    drive.SetLeftRightMotorOutputs( 0.0F, 0.0F );
}

void DriveBase::EnableSpeedControl( XCANJaguar& motor, double p, double i, double d )
{
    motor.ConfigMaxOutputVoltage( MAX_OUTPUT );	// limit max output
    motor.ChangeControlMode( XCANJaguar::kSpeed );
    motor.ConfigNeutralMode( XCANJaguar::kNeutralMode_Brake );
    motor.SetSpeedReference( XCANJaguar::kSpeedRef_QuadEncoder );
    motor.ConfigEncoderCodesPerRev( ENCODER_COUNT );
    motor.SetPID( p, i, d );

    // force change in control mode
    motor.EnableControl();

    // Feed the watchdog now to avoid a race condition when enabling
    //   motorSafetyHelper with the previous timer already expired.
    motor.Set( 0.0F, 0 );

    // RobotDrive will handle safety
    motor.SetSafetyEnabled( false );

    // Set the timer a little longer than default
    //   to allow for CAN timeouts and retries.
    motor.SetExpiration( 0.5 );

    // Feed the watchdog again with the new interval.
    motor.Set( 0.0F, 0 );
}

void DriveBase::EnableSpeedControl()
{
    EnableSpeedControl( motorLR, SPEED_P, SPEED_I, SPEED_D );
    EnableSpeedControl( motorRF, SPEED_P, SPEED_I, SPEED_D );
    EnableSpeedControl( motorLF, SPEED_P, SPEED_I, SPEED_D );
    EnableSpeedControl( motorRR, SPEED_P, SPEED_I, SPEED_D );

    // set top speed
    drive.SetMaxOutput( MAX_SPEED );

    // Feed the watchdog now to avoid a race condition when enabling
    //   motorSafetyHelper with the previous timer already expired.
    drive.SetLeftRightMotorOutputs( 0.0F, 0.0F );

    // Now it's safe to enable.
    drive.SetSafetyEnabled( true );

    // Set the timer a little longer than default
    //   to allow for CAN timeouts and retries.
    drive.SetExpiration( 0.5 );

    // Feed the watchdog again with the new interval.
    drive.SetLeftRightMotorOutputs( 0.0F, 0.0F );
}

void DriveBase::EnablePositionControl( XCANJaguar& motor, double p, double i, double d )
{
    motor.ConfigMaxOutputVoltage( MAX_OUTPUT );	// does this matter?
    motor.ChangeControlMode( XCANJaguar::kPosition );
    motor.ConfigNeutralMode( XCANJaguar::kNeutralMode_Brake );
    motor.SetPositionReference( XCANJaguar::kPosRef_QuadEncoder );
    motor.ConfigEncoderCodesPerRev( ENCODER_COUNT );

    motor.SetPID( p, i, d );

    // force change in control mode
    motor.EnableControl( 0.0 );

    // Feed the watchdog now to avoid a race condition when enabling
    //   motorSafetyHelper with the previous timer already expired.
    motor.Set( 0.0F, 0 );

    // Now it's safe to enable.
    motor.SetSafetyEnabled( true );

    // Set the timer a little longer than default
    //   to allow for CAN timeouts and retries.
    motor.SetExpiration( 0.5 );

    // Feed the watchdog again with the new interval.
    motor.Set( 0.0F, 0 );
}

void DriveBase::EnablePositionControl()
{
    EnablePositionControl( motorLR, POSITION_P, POSITION_I, POSITION_D );
    EnablePositionControl( motorRF, POSITION_P, POSITION_I, POSITION_D );
    EnablePositionControl( motorLF, POSITION_P, POSITION_I, POSITION_D );
    EnablePositionControl( motorRR, POSITION_P, POSITION_I, POSITION_D );

    // Bypass the RobotDrive class for this mode since it doesn't deal
    //   well with arbitrarily large setpoints for multiple wheel rotations.
    drive.SetSafetyEnabled( false );

    // Start the timer
    m_driveTime = GetFPGATime();
}


void DriveBase::DriveCartesian( float fwd, float right, float spin)
{
    drive.MecanumDrive_Cartesian( -fwd, -right, spin );
}

