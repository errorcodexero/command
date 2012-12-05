#ifndef BALL_COLLECTOR_FWD_H
#define BALL_COLLECTOR_FWD_H

#include "../CommandBase.h"

class BallCollectorFwd: public CommandBase {
public:
    BallCollectorFwd();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
