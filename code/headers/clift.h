#ifndef CLIFT_H
#define CLIFT_H
#include "cmotor.h"
#include "cpushrot.h"
#include "sensor.h"


class cLift
{
public:
    cLift();
public:
    void activate(); //bij afgeven van blokje om lift omlaag te laten gaan
    void checkDown(); //checken of de lift beneden is (zodat je de pushrod niet molt en ie ook echt wertkt)
    void goUp(); //wanneer de lift beneden is pushrod activeren en omhoog gaan
    bool isBlok; //of er een blokje op zit
private:
    sensor sensor;
   // cmotor motor;
    cpushrot pushrod;
};

#endif // CLIFT_H
