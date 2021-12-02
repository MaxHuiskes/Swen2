#include "cbelt.h"

cBelt::cBelt()
{
    maxBlock = 8;
    sensor = 10;
    motor = 2;
    pushrot = 0;
}

void cBelt::move(int i){

    belt = i;
}
