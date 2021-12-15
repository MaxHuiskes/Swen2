#include "headers/cbelt.h"

cBelt::cBelt(int maxBlok, int bandNr)
{
    maxBlock = maxBlok; //max blokjes assignen bij maken van belt
    belt = bandNr; //nummer van band krijgen bij maken van belt
}

void cBelt::move(int a){
    motor.moveMotor(a); //beweegt de motor die bij die belt hoort
}
