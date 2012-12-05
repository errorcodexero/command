#ifndef BALL_COLLECTOR_STOP_H
#define BALL_COLLECTOR_STOP_H

#include "../CommandBase.h"

class BallCollectorStop: public CommandBase {
public:
    BallCollectorStop();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
