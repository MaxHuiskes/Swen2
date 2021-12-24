#include "headers/cmotor.h"
#include "sensor.h"
#include <QTimer>
#include "mainwindow.h"
#include <QDebug>
#include "cblock.h"
#include "quibelt.h"

cmotor::cmotor(cblock * block)
{
    blck = block;
}

void cmotor::moveMotor(){
     QTimer *timer = new QTimer;
     timer->connect(timer, &QTimer::timeout,this, &cmotor::endTimer);
     timer->isSingleShot();
     timer->start(1000);
}

void cmotor::endTimer(){

}
