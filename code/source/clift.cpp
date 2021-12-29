#include "headers/clift.h"
#include <thread>

cLift::cLift()
{
    isBlok = 0;
}

void cLift::activate(){
    isBlok = 1; //status blokje op lift
   // motor.moveMotor(-1); //lift omlaag
}

void cLift::checkDown(){
    if (sensor.detect() == 1)
        goUp(); //wanneer de sensor onderaan wat detecteert start goUp
}

void cLift::goUp(){
    pushrod.move(); //duwt het blokje weg
   // motor.moveMotor(1); //lift omhoog
    isBlok = 0; //status geen bokje op lift
}
