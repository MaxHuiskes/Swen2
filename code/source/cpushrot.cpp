#include "headers/cpushrot.h"

cpushrot::cpushrot()
{
    pushrodHigh = 0;
}

cpushrot::~cpushrot(){

}
void cpushrot::in(){
    pushrodHigh = 0;

}

bool cpushrot::getStatusPushrod(){
    return pushrodHigh;
}

void cpushrot::out(){
    pushrodHigh = 1;
}
