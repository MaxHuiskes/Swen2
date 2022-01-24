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
        if(beltnr==1){
            if (blck->high == true){
                highSensor->setSensorValue(true);
            }
            lowSensor.setSensorValue(true);
        }
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

int cBelt::getLowSensorValue(){
    return lowSensor.getSensorValue();
}

int cBelt::getHighSensorValue(){
    return highSensor->getSensorValue();
}
int cBelt::getMetalSensorValue(){
    return metalSensor->getSensorValue();
}

void cBelt::resetSensor(){
    lowSensor.setSensorValue(0);
    if (beltnr == 1){
        highSensor->setSensorValue(0);
    }
    //metalSensor->setSensorValue(0);
}
