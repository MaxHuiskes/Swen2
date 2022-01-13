#include "headers/clift.h"
#include <thread>

void cLift::getBlock(int a){
    if((a == 0 && liftPos == 1) || (a == 1 && liftPos == 0)){
        pushrod.move(); //lift moven als blok van de andere belt komt
    }
    liftBelt.block = "Block";
}
