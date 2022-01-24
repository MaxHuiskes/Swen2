#include "cbelt.h"
#include "cblock.h"
#include "sensor.h"
#include <QWidget>


cBelt::cBelt(int nr)
{
    beltnr = nr;
    if(beltnr == 1){
        highSensor = new sensor;
        metalSensor = new sensor;
    }

}

void cBelt::toggleMotor(){  // toggle motor
    motor.toggleMotor();
    // emit motorChange(getMotorStatus());
}


void cBelt::setBlock(cblock * blck){ // set block on belt
    if (allowBlock == 0){
        block = blck->print;
        bl = blck;

        toggleMotor();
        //motor.motorNotifySensor(); // is niet nodig is al 5s delay

        if (beltnr == 1) {
            if (bl->high == true){
                highSensor->setSensorValue(true);
            }
            if (bl->metal == true){
                metalSensor->setSensorValue(true);
            }
        }
        lowSensor.setSensorValue(true);

        toggleMotor();

    }

    // if belt contains a block -> belt is occupied
    setOccupiedStatus(1);
}

void cBelt::setNoBlock(cblock* blck){
    block = blck->print;
    bl = blck;
}

int cBelt::getBeltNr(){  // get belt number
    return beltnr;
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
        metalSensor->setSensorValue(0);
    }

}

int cBelt::getMotorStatus(){
    return motor.getMotorStatus();
}
