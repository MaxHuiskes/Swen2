#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H
#include "isensor.h"


class lowDistanceSensor : public ISensor
{
public:
    lowDistanceSensor();

    bool getSensorStatus();

private:
    bool status;
};

#endif // DISTANCESENSOR_H
