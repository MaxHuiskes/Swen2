#ifndef CBELT_H
#define CBELT_H

#include "ibelt.h"
#include "sensor.h"
#include "cpushrot.h"
#include "cmotor.h"
#include <QEvent>
#include <QString>

class cblock;
class cBelt : iBelt
{
public:
    cBelt();

    QString block = "No block";
    cblock *bl;
    int beltnr = 0;
    int sensor = 0;
    int nextBelt = 0;

    void toggleMotor();
    void setBlock(cblock *blck);
    void setBelt(int nr);

};

#endif // CBELT_H


