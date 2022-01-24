#ifndef SENSOR_H
#define SENSOR_H


class sensor
{
public:
    sensor();
    ~sensor();

public:
    bool getSensorValue();                      // returns sensorValue
    void setSensorValue(bool newSensorValue);   // set sensorValue

private:
    bool sensorValue;                           // if 1 detected, 0 not detected
};

#endif // SENSOR_H
