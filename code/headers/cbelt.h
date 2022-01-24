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
class sensor;
class cBelt : iBelt
{
    Q_OBJECT
public:
    cBelt(int nr);
    virtual ~cBelt();

    QString block = "No block";
    cblock *bl;

    int     getBeltNr();
    void    toggleMotor();
    int     getMotorStatus();
    void    setBlock(cblock *blck);
    void    setNoBlock(cblock *blck);
    void    blockOut();
    int     getBlockCount();
    bool    getOccupiedStatus();
    void    setOccupiedStatus(bool);
    int     getLowSensorValue();
    int     getHighSensorValue();
    int     getMetalSensorValue();
    void    resetSensor();

signals:
    void motorChange();

private:
    QWidget *parent;
    cmotor motor;
    sensor lowSensor;
    sensor *highSensor = nullptr;
    sensor *metalSensor = nullptr;
    int beltnr = 0;
    int blockCount = 0;             // max block 8
    bool beltOccupied = 0;          // 0 if no occupied, 1 if occupied
};

#endif // CBELT_H


