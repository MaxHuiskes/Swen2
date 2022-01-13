#include "headers/cpushrot.h"

cpushrot::cpushrot()
{
    pushrodHigh = 0;
}

void cpushrot::togglePushrod(){
    if(pushrodHigh == 1){
        pushrodHigh = 0;
    }
    else if(pushrodHigh == 0){
        pushrodHigh = 1;
    }
}

bool cpushrot::getStatusPushrod(){
    return pushrodHigh;
}
