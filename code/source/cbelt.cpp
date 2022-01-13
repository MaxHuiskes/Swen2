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
        toggleMotor();
    }
    // if belt contains a block -> belt is occupied
    setBeltStatus(1);
}

int cBelt::getBeltNr(){  // get belt number
    return beltnr;
}

bool cBelt::getBeltStatus(){
    return beltStatus;
}

void cBelt::setBeltStatus(bool newStatus){
    beltStatus = newStatus;
}

void cBelt::receiveBlock(bool receiving){

}

// modbus TCP voor connectie tussen controller en ui


