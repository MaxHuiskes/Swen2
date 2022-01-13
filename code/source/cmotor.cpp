#include "headers/cmotor.h"
#include <QTimer>
#include <QDebug>
#include "cblock.h"
#include "sensor.h"

cmotor::cmotor()
{
    motorStatusOn = 0;
}

bool cmotor::motorNotifySensor(){
    for (int i = 0; i < 65001; i ++){
        if (i == 65000){
            return 1;
        }
    }
    return 0;
}

void cmotor::toggleMotor(){
    if(motorStatusOn == 1){
        motorStatusOn = 0;
    }
    else if(motorStatusOn == 0){
        motorStatusOn = 1;
    }
}

bool cmotor::getMotorStatus(){
    return motorStatusOn;
}
