#include "headers/cmotor.h"
#include <QTime>
#include <QDebug>
#include "cblock.h"
#include "sensor.h"

cmotor::cmotor()
{
    motorStatusOn = 0;
}

cmotor::~cmotor(){

}

void cmotor::motorNotifySensor(){                       // motor simulator
    QTime dieTime= QTime::currentTime().addSecs(3);
    while (QTime::currentTime() < dieTime){
    // do notihing
    }
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
