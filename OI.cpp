// sample robot code
// Steve Tarr - team 1425 mentor

#include "OI.h"
#include "Robotmap.h"
#include "Commands/CollectBalls.h"
#include "Commands/DumpBalls.h"
#include "Commands/HoldBalls.h"

OI::OI() :
	pIO(NULL),
	driverStick(DRIVER_STICK),
	button2(&driverStick, 2),
	button3(&driverStick, 3),
	button4(&driverStick, 4),
	button5(&driverStick, 5),
	button6(&driverStick, 6)
{
    DriverStation *pDS = DriverStation::GetInstance();
    pIO = &pDS->GetEnhancedIO();

    button2.WhenPressed(new HoldBalls());
    button3.WhenPressed(new CollectBalls());
    button4.WhenPressed(new DumpBalls());
}

