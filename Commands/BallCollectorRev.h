#ifndef BALL_COLLECTOR_REV_H
#define BALL_COLLECTOR_REV_H

#include "../CommandBase.h"

class BallCollectorRev: public CommandBase {
public:
    BallCollectorRev();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
