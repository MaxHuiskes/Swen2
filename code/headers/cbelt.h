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
    void setBlock(){block = 1;};
    void setBelt(int nr){beltnr = nr;};
};

#endif // CBELT_H


