#include "cbelt.h"
#include "cblock.h"
#include "sensor.h"
#include <QWidget>


cBelt::cBelt(int nr)
{
    beltnr = nr;
    if(beltnr == 1){
        highSensor = new sensor;
    }
}

void cBelt::toggleMotor(){  // toggle motor
    motor.toggleMotor();
}


void cBelt::setBlock(cblock * blck){ // set block on belt
    if (allowBlock == 0){
        block = blck->print;
        bl = blck;
        //toggleMotor();
    }
    // if belt contains a block -> belt is occupied
    setOccupiedStatus(1);
}

int cBelt::getBeltNr(){  // get belt number
    return beltnr;
}

void cBelt::receiveBlock(bool receiving){

}

bool cBelt::getOccupiedStatus(){
    return allowBlock;
}

void cBelt::setOccupiedStatus(bool status){
    allowBlock = status;
}



