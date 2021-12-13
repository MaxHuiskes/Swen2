#ifndef CBELT_H
#define CBELT_H

#include "ibelt.h"


class cBelt : iBelt
{
public:
    cBelt();

public:
    int belt;
    int maxBlock;
    int sensor;
    int motor;
    int pushrot;

//    void move(int) override;
};

#endif // CBELT_H
