#include "distancesensor.h"
#include "isensor.h"

distanceSensor::distanceSensor() : public ISensor
{
public:
    distanceSensor();

    bool getSensorStatus();

private:
    bool status;
}
