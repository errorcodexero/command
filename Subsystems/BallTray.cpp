#include "BallTray.h"
#include "../Robotmap.h"

BallTray::BallTray() :
    Subsystem("BallTray"),
    raise( BALL_TRAY_SOLENOID  )
{
    raise.Set(false);
}
    
// Put methods for controlling this subsystem
// here. Call these from Commands.

void BallTray::Raise()
{
    raise.Set( true );
}

void BallTray::Lower()
{
    raise.Set( false );
}

