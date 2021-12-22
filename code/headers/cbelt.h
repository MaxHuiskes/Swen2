#ifndef CBELT_H
#define CBELT_H

#include "ibelt.h"
#include <QEvent>


class cBelt
{
public:
    cBelt();

    int block = 0;
    int beltnr = 0;

    void toggleMotor();
    void setBlock();
    void setBelt(int nr);
};

#endif // CBELT_H


