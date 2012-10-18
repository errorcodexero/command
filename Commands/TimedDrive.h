#ifndef TIMED_DRIVE_H
#define TIMED_DRIVE_H

#include "../CommandBase.h"

class TimedDrive: public CommandBase {
private:
    float m_driveX, m_driveY, m_driveT;
    float m_seconds;
    Timer m_timer;
    void TimedDriveInit( float x, float y, float t, float seconds );
public:
    TimedDrive();
    TimedDrive( float x, float y, float t, float seconds );
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
    void SetDirection( float x, float y, float t = 0.0 );
    void SetTime( float seconds );
};

#endif
