#ifndef BALL_TRAY_H
#define BALL_TRAY_H

#include <WPILib.h>

class BallTray: public Subsystem
{
private:
    Solenoid raise;	// energize to raise tray for dumping

public:
    BallTray();
    void Raise();
    void Lower();
};

#endif
