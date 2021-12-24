#include "cbelt.h"
#include "cblock.h"

cBelt::cBelt()
{

}
void cBelt::toggleMotor(){
    cmotor motor(bl);
    motor.moveMotor();
}


void cBelt::setBlock(cblock * blck){

   if (sensor == 0){
      block = blck->print;
      bl = blck;
      toggleMotor();
   }
}

void cBelt::setBelt(int nr){
    beltnr = nr;
    nextBelt = beltnr + 1;
}

// modbus TCP voor connectie tussen controller en ui


