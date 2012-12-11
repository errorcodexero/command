#ifndef DUMP_BALLS_H
#define DUMP_BALLS_H

#include "../CommandBase.h"

class DumpBalls: public CommandBase {
public:
    DumpBalls();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
