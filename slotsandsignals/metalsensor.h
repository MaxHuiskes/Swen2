#ifndef METALSENSOR_H
#define METALSENSOR_H


class metalSensor
{
public:
    metalSensor();

    bool getSensorStatus();

private:
    bool status;
};

#endif // METALSENSOR_H
