#include "headers/sensor.h"

sensor::sensor()
{
    sensorValue = 0;
}

bool sensor::getSensorValue() {
    return sensorValue;
}

void sensor::setSensorValue(bool newSensorValue){
    sensorValue = newSensorValue;
}

