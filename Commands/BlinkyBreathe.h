#ifndef BLINKY_BREATHE_H
#define BLINKY_BREATHE_H

#include "../CommandBase.h"

class BlinkyBreathe: public CommandBase {
private:
    double m_cycleTime;
    double m_startTime;
public:
    BlinkyBreathe( float seconds );
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
