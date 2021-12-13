#ifndef CBELT_H
#define CBELT_H

#include "ibelt.h"
#include <QEvent>


class cBelt : iBelt
{
public:
    cBelt();

public:
    int belt = 0;
    int block = 0;


    void move(int) override;
};

#endif // CBELT_H


