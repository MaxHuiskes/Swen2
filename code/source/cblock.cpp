#include "headers/cblock.h"

cblock::cblock(QString info)
{
    print = info;

    if (info  == lowP){
        materiaal = 1;
        size = 1;
    }
    if (info == middleP){
        materiaal = 1;
        size = 2;
    }
    if (info == highP){
        materiaal = 1;
        size = 3;
    }
    if (info  == lowM){
        materiaal = 2;
        size = 1;
    }
    if (info == middleM){
        materiaal = 2;
        size = 2;
    }
    if (info == highM){
        materiaal = 2;
        size = 3;
    }

}


