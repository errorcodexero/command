#ifndef COLLECT_BALLS_H
#define COLLECT_BALLS_H

#include "../CommandBase.h"

class CollectBalls: public CommandBase {
public:
    CollectBalls();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
