#include "headers/cmotor.h"
#include <QTimer>
#include <QDebug>
#include "cblock.h"
#include "sensor.h"

cmotor::cmotor(cblock * block , QWidget *parent)
    : QWidget(parent)
    , mLabel (this  )
{
    blck = block;
}

void cmotor::moveMotor(){
    for (int i = 0; i < 65001; i ++){
        if (i == 65000){
            printLabel();
        }
    }
}

void cmotor::printLabel(){
    blck->detector = 1;
    sensor sens;
    sens.detect();
}
