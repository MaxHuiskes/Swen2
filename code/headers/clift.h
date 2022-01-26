#ifndef CLIFT_H
#define CLIFT_H
#include "ibelt.h"
#include "cmotor.h"
#include "cpushrot.h"
#include "sensor.h"

class cblock;

// edit: afleiden van IBelt
class cLift : iBelt
{
public:
    cLift(int);
    virtual ~cLift();

    QString block = "No block";
    cblock *bl;

    bool    getLiftStatus();
    void    toggleMotor();
    void    setBlock(cblock * blck);
    int     getBeltNr();
    int     getLowSensorValue();
    void    setNoBlock(cblock *blck);
    bool    getOccupiedStatus();
    void    setOccupiedStatus(bool);
    int     getMotorStatus();
    void    resetSensor();
    void    liftDown();
    void    liftUp();
    int     getMaxUp();

private:
    sensor sensor;
    cmotor motor;
    cpushrot pushrod;
    int beltnr = 0;
    bool beltOccupied = 0;          // 0 if no occupied, 1 if occupied
    bool liftStatus = 0;
    int countUp = 0; // max is 3
};

#endif // CLIFT_H
