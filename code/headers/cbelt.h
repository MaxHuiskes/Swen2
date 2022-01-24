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
public:
    cBelt(int nr);

    QString block = "No block";
    cblock *bl;

    int  getBeltNr();
    void toggleMotor();
    void setBlock(cblock *blck);
    bool getBeltStatus(); // returns 1 if belt is occupied, 0 if belt is not occupied
    void setBeltStatus(bool newStatus); // sets belt status to 1 or 0
    void receiveBlock(bool receiving);
    bool getOccupiedStatus();
    void setOccupiedStatus(bool);
    int getLowSensorValue();
    int getHighSensorValue();
    int getMetalSensorValue();
    void resetSensor();

private:
    QWidget *parent;
    cmotor motor;

    sensor lowSensor;
    sensor *highSensor = nullptr;
    sensor *metalSensor = nullptr;
    int beltnr = 0;
    bool allowBlock = 0;
    bool beltStatus; // 0 if not occupied, 1 if occupied
};

#endif // CBELT_H


