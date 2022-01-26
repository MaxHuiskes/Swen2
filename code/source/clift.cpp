#include "headers/clift.h"
#include "cblock.h"
#include <QDebug>

cLift::cLift(int nr)
{
    beltnr = nr;
    pushrod.in();
    beltOccupied = 0;
}

cLift::~cLift(){

}

void cLift::setBlock(cblock *blck){
    if (beltOccupied == 0 && countUp < 4){
        block = blck->print;
        bl = blck;
        countUp++;
        toggleMotor();

        sensor.setSensorValue(true);

        toggleMotor();
        // if belt contains a block -> belt is occupied
        setOccupiedStatus(1);
    }

}

void cLift::toggleMotor(){
     motor.toggleMotor();
}

bool cLift::getLiftStatus(){
    return liftStatus;
}

void cLift::setNoBlock(cblock* blck){           // set no block on belt
    block = blck->print;
    bl = blck;
}

int cLift::getBeltNr(){                          // get belt number
    return beltnr;
}

bool cLift::getOccupiedStatus(){                // returns occupied value
    return beltOccupied;
}

void cLift::setOccupiedStatus(bool status){     // sets if belt is occupied
    beltOccupied = status;
}

int cLift::getLowSensorValue(){                 // returns low sensor value
    return sensor.getSensorValue();
}

void cLift::resetSensor(){                      // reset all sensor value
    sensor.setSensorValue(0);
}

int cLift::getMotorStatus(){                    // gets and returns motor status
    return motor.getMotorStatus();
}

void cLift::liftUp(){
    pushrod.out();
    liftStatus = pushrod.getStatusPushrod();
}
void cLift::liftDown(){
    pushrod.in();
    countUp = 0;
    liftStatus = pushrod.getStatusPushrod();
}
int cLift::getMaxUp(){
    return countUp;
}
