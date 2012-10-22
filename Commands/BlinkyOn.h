#ifndef BLINKY_ON_H
#define BLINKY_ON_H

#include "../CommandBase.h"

class BlinkyOn: public CommandBase {
public:
    BlinkyOn();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
