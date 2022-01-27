#include "headers/cmotor.h"
#include "cblock.h"

cmotor::cmotor()
{
    motorStatusOn = 0;
}

cmotor::~cmotor(){

}

void cmotor::toggleMotor(){                             // toggle motor on off
    if(motorStatusOn == 1){
        motorStatusOn = 0;
    }
    else if(motorStatusOn == 0){
        motorStatusOn = 1;
    }
}

bool cmotor::getMotorStatus(){                          // returns motor status
    return motorStatusOn;

}
