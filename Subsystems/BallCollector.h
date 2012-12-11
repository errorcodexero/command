#ifndef BALL_COLLECTOR_H
#define BALL_COLLECTOR_H

#include <WPILib.h>

class BallCollector: public Subsystem
{
private:
    Victor pwm;		// run forward to collect balls, reverse to dump
    Solenoid raise;	// energize to raise tray for dumping
    Solenoid lower;	// energize to lower tray for collecting
    float m_speed;	// ball collector speed

public:
    BallCollector();
    void Disable();
    void SetSpeed( float value );
    void RunForward();
    void RunReverse();
    void Stop();
    void Raise();
    void Lower();
};

#endif
