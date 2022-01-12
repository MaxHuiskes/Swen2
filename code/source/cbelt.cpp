#include "cbelt.h"
#include "cblock.h"
#include <QWidget>

cBelt::cBelt()
{

}
void cBelt::toggleMotor(){  // toggle motor
    cmotor motor(bl );
    motor.moveMotor();
}


void cBelt::setBlock(cblock * blck){ // set block on belt

    if (sensor == 0){
        block = blck->print;
        bl = blck;
        bl->detector = 0;
        toggleMotor();
    }
}

void cBelt::setBelt(int nr){  // set belt number
    beltnr = nr;
}

// modbus TCP voor connectie tussen controller en ui


