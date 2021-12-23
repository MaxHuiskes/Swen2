#include "cbelt.h"

cBelt::cBelt()
{

}
void toggleMotor(){
    // motor aansturing
}

void cBelt::setBlock(QString blck){
   if (sensor == 0){
      block = blck;
   }

}

void cBelt::setBelt(int nr){
    beltnr = nr;
}
