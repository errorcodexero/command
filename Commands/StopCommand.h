#ifndef STOP_COMMAND_H
#define STOP_COMMAND_H

#include "../CommandBase.h"

class StopCommand: public CommandBase {
public:
    StopCommand();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
