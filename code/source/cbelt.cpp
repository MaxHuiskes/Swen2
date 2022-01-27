#include "cbelt.h"
#include "cblock.h"
#include "sensor.h"
#include <QWidget>


cBelt::cBelt(int nr)
{
    beltnr = nr;
    if(beltnr == 1 || beltnr == 6){
        highSensor = new sensor;
        metalSensor = new sensor;
        if (beltnr == 6){
            low2Sensor = new sensor;
            low3Sensor = new sensor;
        }
    }

}

cBelt::~cBelt(){
    if (beltnr == 1 || beltnr == 6){
        delete highSensor;
        delete metalSensor;
        if (beltnr == 6){
            delete low2Sensor;
            delete low3Sensor;
        }
    }
}

void cBelt::toggleMotor(){                      // toggle motor
    motor.toggleMotor();
}


void cBelt::setBlock(cblock * blck){            // set block on belt
    if (beltOccupied == 0){
        if (beltnr == 1 && blockCount == 8){    // max blocks on belt chain
            setMaxBlockCount(1);
        }
        if (beltnr == 1 && noMoreBlock == 1){   // no more blocks placed on belts
            return;
        }
        block = blck->print;
        bl = blck;

        toggleMotor();

        if (beltnr == 1) {
            blockCount++;                       // add 1 to blockCount max is eight
            if (bl->high == true){
                highSensor->setSensorValue(true);
            }
            if (bl->metal == true){
                metalSensor->setSensorValue(true);
            }
        }
        if(beltnr == 6){
            if (bl->high == true){
                highSensor->setSensorValue(true);
            } else {
                highSensor->setSensorValue(false);
            }
            if (bl->metal == true){
                metalSensor->setSensorValue(true);
            } else {
                metalSensor->setSensorValue(false);
            }

        }

        lowSensor.setSensorValue(true);

        toggleMotor();

    }

    // if belt contains a block -> belt is occupied
    setOccupiedStatus(1);
}

void cBelt::setNoBlock(cblock* blck){           // set no block on belt
    block = blck->print;
    bl = blck;
}

int cBelt::getBeltNr(){                          // get belt number
    return beltnr;
}

bool cBelt::getOccupiedStatus(){                // returns occupied value
    return beltOccupied;
}

void cBelt::setOccupiedStatus(bool status){     // sets if belt is occupied
    beltOccupied = status;
}

int cBelt::getLowSensorValue(){                 // returns low sensor value
    return lowSensor.getSensorValue();
}
int cBelt::getLow2SensorValue(){                 // returns low sensor value
    return low2Sensor->getSensorValue();
}
int cBelt::getLow3SensorValue(){                 // returns low sensor value
    return low3Sensor->getSensorValue();
}

int cBelt::getHighSensorValue(){                // returns high sensor value
    return highSensor->getSensorValue();
}
int cBelt::getMetalSensorValue(){               // returns metel sensor value
    return metalSensor->getSensorValue();
}

void cBelt::resetSensor(){                      // reset all sensor value
    lowSensor.setSensorValue(0);
    if (beltnr == 1 || beltnr == 6){
        highSensor->setSensorValue(0);
        metalSensor->setSensorValue(0);
        if (beltnr == 6) {
            low2Sensor->setSensorValue(0);
            low3Sensor->setSensorValue(0);
        }
    }

}

int cBelt::getMotorStatus(){                    // gets and returns motor status
    return motor.getMotorStatus();
}

void cBelt::blockOut(){                         // block out of belt chain
    blockCount--;
    if (blockCount == 0 && noMoreBlock == 0){
        setMaxBlockCount(0);
    }
}

int cBelt::getBlockCount(){
    return blockCount;
}

void cBelt::setMaxBlockCount(bool maxBlock){
    noMoreBlock = maxBlock;
}

void cBelt::setLow23SensorValue(bool nr, bool value){
    if (nr == 0 ){
        low2Sensor->setSensorValue(value);
    }else if (nr == 1){
        low3Sensor->setSensorValue(value);
    }

}
