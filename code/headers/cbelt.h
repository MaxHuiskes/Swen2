#ifndef CBELT_H
#define CBELT_H

#include "ibelt.h"
#include <QEvent>
#include <QString>


class cBelt : iBelt
{
public:
    cBelt();

    QString block = "No block";
    int beltnr = 0;
    int sensor = 0;
    int nextBelt = 0;

    void toggleMotor();
    void setBlock(QString);
    void setBelt(int nr);
};

#endif // CBELT_H


