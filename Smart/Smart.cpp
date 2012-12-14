// sample robot code
// Steve Tarr - team 1425 mentor - 11-Feb-2012

#include <stdlib.h>
#include <math.h>
#include <WPILib.h>
#include "Smart.h"

#ifndef M_PI
#define M_PI		3.14159265358979323846
#endif // M_PI

SmartJoystick::SmartJoystick( UINT32 port, const char* name )
    : Joystick( port ), m_name( name )
{
    InitSmartJoystick();
}

SmartJoystick::SmartJoystick( UINT32 port, UINT32 numAxisTypes, UINT32 numButtonTypes, const char* name )
    : Joystick( port ), m_name( name )
{
    InitSmartJoystick();
}

char* SmartJoystick::LogName( const char* axisName )
{
    // Doing this in C isn't elegant, but provides a low-overhead match
    // to the SmnartDashboard interface that relies on C strings.

    // "+2" allows for the space between the strings and a trailing NUL
    int len = strlen(m_name) + strlen(axisName) + 2;
    char *name = (char *) malloc(len);
    strcpy(name, m_name);
    strcat(name, " ");
    strcat(name, axisName);
    return name;
}

void SmartJoystick::InitSmartJoystick()
{
    m_xName = LogName("X");
    m_yName = LogName("Y");
    m_zName = LogName("Z");
    m_twistName = LogName("Twist");
    m_throttleName = LogName("Throttle");

    m_magnitudeName = LogName("Magnitude");
    m_directionName = LogName("Direction");

    m_triggerName = LogName("Trigger");
    m_topName = LogName("Top");
}

float SmartJoystick::GetX( JoystickHand hand )
{
    float value = Joystick::GetX( hand );
    if (m_xName) SmartDashboard::Log( value, m_xName );
    return value;
}

float SmartJoystick::GetY( JoystickHand hand )
{
    float value = Joystick::GetY( hand );
    if (m_yName) SmartDashboard::Log( value, m_yName );
    return value;
}

float SmartJoystick::GetZ()
{
    float value = Joystick::GetZ();
    if (m_zName) SmartDashboard::Log( value, m_zName );
    return value;
}

float SmartJoystick::GetTwist()
{
    float value = Joystick::GetTwist();
    if (m_twistName) SmartDashboard::Log( value, m_twistName );
    return value;
}

float SmartJoystick::GetThrottle()
{
    float value = Joystick::GetThrottle();
    if (m_throttleName) SmartDashboard::Log( value, m_throttleName );
    return value;
}

float SmartJoystick::GetMagnitude()
{
    float value = Joystick::GetMagnitude();
    if (m_magnitudeName) SmartDashboard::Log( value, m_magnitudeName );
    return value;
}

float SmartJoystick::GetDirectionRadians()
{
    float value = Joystick::GetDirectionRadians();
    if (m_directionName) SmartDashboard::Log( value * 180.0 / M_PI, m_directionName );
    return value;
}

float SmartJoystick::GetDirectionDegrees()
{
    float value = Joystick::GetDirectionDegrees();
    if (m_directionName) SmartDashboard::Log( value, m_directionName );
    return value;
}

bool SmartJoystick::GetTrigger( JoystickHand hand )
{
    bool value = Joystick::GetTrigger( hand );
    if (m_triggerName) SmartDashboard::Log( value, m_triggerName );
    return value;
}

bool SmartJoystick::GetTop( JoystickHand hand )
{
    bool value = Joystick::GetTop( hand );
    if (m_topName) SmartDashboard::Log( value, m_topName );
    return value;
}

SmartJoystick::~SmartJoystick()
{
    free( (void *) m_xName );
    free( (void *) m_yName );
    free( (void *) m_twistName );
    free( (void *) m_throttleName );

    free( (void *) m_magnitudeName );
    free( (void *) m_directionName );

    free( (void *) m_triggerName );
    free( (void *) m_topName );
}

///////////////////////////////////////////////////////////////////////////////

SmartVictor::SmartVictor( UINT32 channel, const char* name )
    : Victor( channel ), m_name( name )
{
}

SmartVictor::SmartVictor( UINT32 slot, UINT32 channel, const char* name )
    : Victor( slot, channel ), m_name( name )
{
}

void SmartVictor::Set( float value, UINT8 syncGroup )
{
    if (m_name) SmartDashboard::Log( value, m_name );
    printf("%s %g\n", m_name, value);

    Victor::Set( 0.0F, syncGroup );
}

void SmartVictor::PIDWrite( float value )
{
    SmartVictor::Set( value );
}

void SmartVictor::Disable()
{
    Victor::Disable();
    if (m_name) SmartDashboard::Log( "disabled", m_name );
}

SmartVictor::~SmartVictor()
{
}

///////////////////////////////////////////////////////////////////////////////

SmartJaguar::SmartJaguar( UINT32 channel, const char* name )
    : Jaguar( channel ), m_name( name )
{
}

SmartJaguar::SmartJaguar( UINT32 slot, UINT32 channel, const char* name )
    : Jaguar( slot, channel ), m_name( name )
{
}

void SmartJaguar::Set( float value, UINT8 syncGroup )
{
    Jaguar::Set( value, syncGroup );
    if (m_name) SmartDashboard::Log( value, m_name );
}

void SmartJaguar::Disable()
{
    Jaguar::Disable();
    if (m_name) SmartDashboard::Log( "disabled", m_name );
}

SmartJaguar::~SmartJaguar()
{
}

///////////////////////////////////////////////////////////////////////////////

SmartCANJaguar::SmartCANJaguar( UINT8 deviceNumber, const char* name, ControlMode controlMode )
    : XCANJaguar( deviceNumber, controlMode ),
      m_name(name),
      m_setName(NULL),
      m_busName(NULL),
      m_voltageName(NULL),
      m_currentName(NULL),
      m_speedName(NULL),
      m_positionName(NULL),
      m_logTimer()
{
    InitSmartCANJaguar();
    m_logTimer.Start();
}

char* SmartCANJaguar::LogName( const char* varName )
{
    // Doing this in C isn't elegant, but provides a low-overhead match
    // to the SmnartDashboard interface that relies on C strings.

    // "+2" allows for the space between the strings and a trailing NUL
    int len = strlen(m_name) + strlen(varName) + 2;
    char *name = (char *) malloc(len);
    strcpy(name, m_name);
    strcat(name, " ");
    strcat(name, varName);
    return name;
}

void SmartCANJaguar::InitSmartCANJaguar()
{
    m_setName      = LogName("set");
    m_busName      = LogName("bus");
    m_voltageName  = LogName("voltage");
    m_currentName  = LogName("current");
    m_speedName    = LogName("speed");
    m_positionName = LogName("position");

    printf("SmartCANJaguar: m_name = %s\n", m_name);
    printf("SmartCANJaguar: m_setName = %s\n", m_setName);
    printf("SmartCANJaguar: m_busName = %s\n", m_busName);
    printf("SmartCANJaguar: m_voltageName = %s\n", m_voltageName);
    printf("SmartCANJaguar: m_currentName = %s\n", m_currentName);
    printf("SmartCANJaguar: m_speedName = %s\n", m_speedName);
    printf("SmartCANJaguar: m_positionName = %s\n", m_positionName);
}

void SmartCANJaguar::Log()
{
    // limit display update rate
    if (!m_logTimer.HasPeriodPassed(0.5)) {
	return;
    }

    XCANJaguar::ControlMode mode = GetControlMode();

    if (m_name) {
	const char * modeName;
	switch(mode) {
	case XCANJaguar::kPercentVbus:
	    modeName = "percentVbus";
	    break;
	case XCANJaguar::kVoltage:
	    modeName = "voltage";
	    break;
	case XCANJaguar::kCurrent:
	    modeName = "current";
	    break;
	case XCANJaguar::kSpeed:
	    modeName = "speed";
	    break;
	case XCANJaguar::kPosition:
	    modeName = "position";
	    break;
	default:
	    modeName = "unknown";
	    break;
	}
	SmartDashboard::Log( modeName, m_name );
    }

    if (m_setName) {
	float value = Get();

	switch(mode) {
	case XCANJaguar::kPercentVbus:
				// no scaling -- assume -1 to +1
	    break;
	case XCANJaguar::kVoltage:
	    value /= 12.0;	// scale by nominal bus voltage
	    break;
	case XCANJaguar::kCurrent:
	    value /= 40.0;	// scale by circuit breaker limit
	    break;
	case XCANJaguar::kSpeed:
	    value /= 5000.;	// scale by CIM unloaded max speed
	    break;
	case XCANJaguar::kPosition:
				// no scaling -- assume -1 to +1 rotation
	    break;
	}
	SmartDashboard::Log( value, m_setName );
    }
    if (m_busName) {
	SmartDashboard::Log( GetBusVoltage(), m_busName );
    }
    if (m_voltageName) {
	SmartDashboard::Log( GetOutputVoltage(), m_voltageName );
    }
    if (m_currentName) {
	SmartDashboard::Log( GetOutputCurrent(), m_currentName );
    }
    if ((mode == XCANJaguar::kSpeed) && m_speedName) {
	SmartDashboard::Log( GetSpeed(), m_speedName );
    }
    if ((mode == XCANJaguar::kPosition) && m_positionName) {
	SmartDashboard::Log( GetPosition(), m_positionName );
    }
    // faults, temperature ...
}

void SmartCANJaguar::Set( float value, UINT8 syncGroup )
{
    XCANJaguar::Set( value, syncGroup );
    Log();
}

void SmartCANJaguar::Disable()
{
    XCANJaguar::Disable();
    if (m_name) SmartDashboard::Log( "disabled", m_name );
}

SmartCANJaguar::~SmartCANJaguar()
{
    free( (void *) m_setName );
    free( (void *) m_voltageName );
    free( (void *) m_currentName );
    free( (void *) m_speedName );
    free( (void *) m_positionName );
}

///////////////////////////////////////////////////////////////////////////////

SmartPWM::SmartPWM( UINT32 channel, const char* name )
    : PWM( channel ), m_name( name )
{
}

SmartPWM::SmartPWM( UINT32 slot, UINT32 channel, const char* name )
    : PWM( slot, channel ), m_name( name )
{
}

SmartPWM::~SmartPWM()
{
}

void SmartPWM::SetRaw( UINT8 raw )
{
    if (m_name) SmartDashboard::Log( raw, m_name );
    PWM::SetRaw( raw );
}

///////////////////////////////////////////////////////////////////////////////

SmartEncoder::SmartEncoder(
		UINT32 aChannel, UINT32 bChannel,
	        const char* name,
	        bool reverseDirection,
	        EncodingType encodingType )

    : Encoder( aChannel, bChannel, reverseDirection, encodingType ),
      m_name( name ) 
{
    InitSmartEncoder();
}


SmartEncoder::SmartEncoder(
		UINT32 aSlot, UINT32 aChannel,
	        UINT32 bSlot, UINT32 bChannel,
	        const char* name,
	        bool reverseDirection,
	        EncodingType encodingType )

    : Encoder( aSlot, aChannel, bSlot, bChannel,
	       reverseDirection, encodingType ),
      m_name( name )
{
    InitSmartEncoder();
}

SmartEncoder::SmartEncoder(
		DigitalSource *aSource, DigitalSource *bSource,
	        const char* name,
	        bool reverseDirection,
	        EncodingType encodingType )

    : Encoder( aSource, bSource, reverseDirection, encodingType ),
      m_name( name )
{
    InitSmartEncoder();
}

SmartEncoder::SmartEncoder(
		DigitalSource &aSource, DigitalSource &bSource,
	        const char* name,
	        bool reverseDirection,
	        EncodingType encodingType )

    : Encoder( aSource, bSource, reverseDirection, encodingType ),
      m_name( name )
{
    InitSmartEncoder();
}

char* SmartEncoder::LogName( const char* axisName )
{
    // Doing this in C isn't elegant, but provides a low-overhead match
    // to the SmnartDashboard interface that relies on C strings.

    // "+2" allows for the space between the strings and a trailing NUL
    int len = strlen(m_name) + strlen(axisName) + 2;
    char *name = (char *) malloc(len);
    strcpy(name, m_name);
    strcat(name, " ");
    strcat(name, axisName);
    return name;
}

void SmartEncoder::InitSmartEncoder()
{
    m_rawName       = LogName("Raw");
    m_periodName    = LogName("Period");
    m_stoppedName   = LogName("Stopped");
    m_directionName = LogName("Direction");
    m_distanceName  = LogName("Distance");
    m_rateName      = LogName("Rate");
    m_pidName       = LogName("PID");
}

SmartEncoder::~SmartEncoder()
{
    free( (void *) m_rawName );
    free( (void *) m_periodName );
    free( (void *) m_stoppedName );
    free( (void *) m_directionName );
    free( (void *) m_distanceName );
    free( (void *) m_rateName );
    free( (void *) m_pidName );
}

INT32 SmartEncoder::GetRaw()
{
    INT32 value = Encoder::GetRaw();
    if (m_rawName) SmartDashboard::Log( value, m_rawName );
    return value;
}

INT32 SmartEncoder::Get()
{
    INT32 value = Encoder::Get();
    if (m_name) SmartDashboard::Log( value, m_name );
    return value;
}

double SmartEncoder::GetPeriod()
{
    double period = Encoder::GetPeriod();
    if (m_periodName) SmartDashboard::Log( period, m_periodName );
    return period;
}

bool SmartEncoder::GetStopped()
{
    bool stopped = Encoder::GetStopped();
    if (m_stoppedName) SmartDashboard::Log( stopped, m_stoppedName );
    return stopped;
}

bool SmartEncoder::GetDirection()
{
    bool direction = Encoder::GetDirection();
    if (m_directionName) SmartDashboard::Log( direction, m_directionName );
    return direction;
}

double SmartEncoder::GetDistance()
{
    double distance = Encoder::GetDistance();
    if (m_distanceName) SmartDashboard::Log( distance, m_distanceName );
    return distance;
}

double SmartEncoder::GetRate()
{
    double rate = Encoder::GetRate();
    if (m_rateName) SmartDashboard::Log( rate, m_rateName );
    return rate;
}

double SmartEncoder::PIDGet()
{
    double pid = Encoder::PIDGet();
    if (m_pidName) SmartDashboard::Log( pid, m_pidName );
    return pid;
}

///////////////////////////////////////////////////////////////////////////////

