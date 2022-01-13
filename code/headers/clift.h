#ifndef CLIFT_H
#define CLIFT_H
#include "cmotor.h"
#include "cpushrot.h"
#include "sensor.h"

// edit: afleiden van IBelt
class cLift
{
public:
    cLift();
public:

    // functies die eruit moeten/aangepast moeten worden:
    //edit: wat doet deze functie?
    void activate(); //bij afgeven van blokje om lift omlaag te laten gaan
    // waarom geen checkUp? indien in onbekende stand weet je niet waar je lift is -> je hebt ook geen return waarde
    void checkDown(); //checken of de lift beneden is (zodat je de pushrod niet molt en ie ook echt werkt)
    // je lift kan alleen naar boven?, schrijven als toggleLift/togglePushrod?
    void goUp(); //wanneer de lift beneden is pushrod activeren en omhoog gaan
    // aanpassen naar occupied();?
    bool isBlok; //of er een blokje op zit
private:
    sensor sensor;
    cmotor motor;
    cpushrot pushrod;
};

#endif // CLIFT_H
