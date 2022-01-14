#include "headers/cblock.h"

cblock::cblock(QString info) // create right info to block
{
    print = info;

    if (info  == lowP){
        metal = 0;
        high = 0;
    }
    else if (info == highP){
        metal = 0;
        high = 1;
    }
    else if (info  == lowM){
        metal = 1;
        high = 0;
    }
    else if (info == highM){
        metal = 1;
        high = 1;
    }else if(info == "No block"){
        metal = NULL;
        high = NULL;
    }
}


