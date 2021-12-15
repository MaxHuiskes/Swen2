#ifndef CBELT_H
#define CBELT_H

#include "ibelt.h"
#include "sensor.h"
#include "cpushrot.h"
#include "cmotor.h"
#include <QEvent>


class cBelt : iBelt
{
public:
    cBelt(int, int);

public:
    int belt; //nummer van de band
    int maxBlock; //maximaal aantal blokjes op de band

    void move(int) override; //aan/uit van band en richting

private:
    sensor sensor;
    cmotor motor;
    //niet elke band heeft een pushrod en meeste banden hebben maar 1 sensor en motor
};

#endif // CBELT_H


