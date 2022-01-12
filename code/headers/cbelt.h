#ifndef CBELT_H
#define CBELT_H

#include "ibelt.h"
#include "sensor.h"
#include "cpushrot.h"
#include "cmotor.h"
#include <QEvent>
#include <QString>

class cblock;
class QWidget;
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
    void setBelt(int nr);
    void setBlock(cblock *blck);

private:
    QWidget *parent;

};

#endif // CBELT_H


