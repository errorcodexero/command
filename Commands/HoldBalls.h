#ifndef HOLD_BALLS_H
#define HOLD_BALLS_H

#include "../CommandBase.h"

class HoldBalls: public CommandBase {
public:
    HoldBalls();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
