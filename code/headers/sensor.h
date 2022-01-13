#ifndef SENSOR_H
#define SENSOR_H


class sensor
{
public:
    sensor();
    ~sensor() {}

public:
    bool getSensorValue(); //geeft 1 terug als de sensor iets detecteert
    //
    void setSensorValue(bool newSensorValue);

private:
    bool sensorValue;
};

#endif // SENSOR_H
