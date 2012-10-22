#ifndef BLINKY_OFF_H
#define BLINKY_OFF_H

#include "../CommandBase.h"

class BlinkyOff: public CommandBase {
public:
    BlinkyOff();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
