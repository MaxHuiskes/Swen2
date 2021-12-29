#include "cbelt.h"
#include "cblock.h"
#include <QWidget>

cBelt::cBelt(QWidget *parent)
    :  parent(parent)
{

}
void cBelt::toggleMotor(){
    cmotor motor(bl, parent );
    motor.moveMotor();
}


void cBelt::setBlock(cblock * blck){

    if (sensor == 0){
        block = blck->print;
        bl = blck;
        bl->detector = 0;
        toggleMotor();
    }
}

void cBelt::setBelt(int nr){
    beltnr = nr;
    nextBelt = beltnr + 1;
}

// modbus TCP voor connectie tussen controller en ui


