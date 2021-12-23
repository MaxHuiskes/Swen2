#include "cbelt.h"

cBelt::cBelt()
{

}
void cBelt::toggleMotor(){
    // motor aansturing
}

void cBelt::setBlock(QString blck){
   if (sensor == 0){
      block = blck;
   }
}

void cBelt::setBelt(int nr){
    beltnr = nr;
    nextBelt = beltnr + 1;
}

// modbus TCP voor connectie tussen controller en ui
