#ifndef ROBOTMAP_H
#define ROBOTMAP_H

// The RobotMap is a mapping from the ports sensors and actuators are wired
// into to a named constant. This provides flexibility when changing wiring,
// makes checking the wiring easier and significantly reduces the number of
// magic numbers floating around.

// OI Joysticks
#define	DRIVER_STICK	1
#define	GUNNER_STICK	2
 
// DriveBase motors (CAN controller channel numbers)
#define CAN_LEFT_REAR	5
#define CAN_RIGHT_REAR	9
#define	CAN_LEFT_FRONT	8
#define	CAN_RIGHT_FRONT	7

// Compressor
#define	COMPRESSOR_SWITCH	1	// digital input - pressure switch
#define	COMPRESSOR_RELAY	1	// relay (Spike) output - compressor 

// Blinky
#define	BLINKY_PWM		1	// Victor to control blinky light

#endif
