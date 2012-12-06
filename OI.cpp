// sample robot code
// Steve Tarr - team 1425 mentor

#include "OI.h"
#include "Robotmap.h"

OI::OI() :
	pIO(NULL),
	driverStick(DRIVER_STICK, "driver")
{
     DriverStation *pDS = DriverStation::GetInstance();
     pIO = &pDS->GetEnhancedIO();
}

