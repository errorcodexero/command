#ifndef DRIVE_COMMAND_H
#define DRIVE_COMMAND_H

#include "../CommandBase.h"
#include "CollectBalls.h"
#include "DumpBalls.h"

class DriveCommand: public CommandBase {
private:
    CollectBalls m_collectBalls;
    DumpBalls m_dumpBalls;

public:
    DriveCommand();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
