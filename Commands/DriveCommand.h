#ifndef DRIVE_COMMAND_H
#define DRIVE_COMMAND_H

#include "../CommandBase.h"
#include "CollectBalls.h"
#include "DumpBalls.h"

class DriveCommand: public CommandBase {
private:
    CollectBalls m_collectBalls;
    DumpBalls m_dumpBalls;
    typedef enum {
	k_stopped = 0,
	k_forward = 1,
	k_reverse = 2,
	k_right   = 3,
	k_left    = 4,
    } DriveDirection;
    DriveDirection m_direction;
    void Go( DriveDirection direction, float speed );

public:
    DriveCommand();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
